/*
 * Copyright (c) 2012, The Cubebox Team <http://cubebox.bplaced.net/>
 * 
 * 
 * This file is part of cubebox.
 * 
 * cubebox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * cubebox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with cubebox.  If not, see <http://www.gnu.org/licenses/>.
 *
*/


#include "../globals.h"
#include "main.h"


int light = 0; /* Whether or not lighting is on */
int blend = 0; /* Whether or not blending is on */

GLfloat xrot;      /* X Rotation */
GLfloat yrot;      /* Y Rotation */
GLfloat xspeed;    /* X Rotation Speed */
GLfloat yspeed;    /* Y Rotation Speed */
GLfloat z = -5.0f; /* Depth Into The Screen */

/* Ambient Light Values ( NEW ) */
GLfloat LightAmbient[]  = { 0.5f, 0.5f, 0.5f, 1.0f };
/* Diffuse Light Values ( NEW ) */
GLfloat LightDiffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
/* Light Position ( NEW ) */
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };

GLuint filter;     /* Which Filter To Use */
GLuint texture[3]; /* Storage for 3 textures */


/* function to load in bitmap as a GL texture */
int LoadGLTextures( )
{
    /* Status indicator */
    int Status = 0;

    /* Create storage space for the texture */
    SDL_Surface *TextureImage[1]; 

    /* Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit */
    if ( ( TextureImage[0] = SDL_LoadBMP( "data/glass.bmp" ) ) )
        {

	    /* Set the status to 1 */
	    Status = 1;

	    /* Create The Texture */
	    glGenTextures( 3, &texture[0] );

	    /* Load in texture 1 */
	    /* Typical Texture Generation Using Data From The Bitmap */
	    glBindTexture( GL_TEXTURE_2D, texture[0] );

	    /* Generate The Texture */
	    glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage[0]->w,
			  TextureImage[0]->h, 0, GL_BGR,
			  GL_UNSIGNED_BYTE, TextureImage[0]->pixels );
	    
	    /* Nearest Filtering */
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			     GL_NEAREST );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
			     GL_NEAREST );

	    /* Load in texture 2 */
	    /* Typical Texture Generation Using Data From The Bitmap */
	    glBindTexture( GL_TEXTURE_2D, texture[1] );

	    /* Linear Filtering */
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			     GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
			     GL_LINEAR );

	    /* Generate The Texture */
	    glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage[0]->w,
			  TextureImage[0]->h, 0, GL_BGR,
			  GL_UNSIGNED_BYTE, TextureImage[0]->pixels );

	    /* Load in texture 3 */
	    /* Typical Texture Generation Using Data From The Bitmap */
	    glBindTexture( GL_TEXTURE_2D, texture[2] );

	    /* Mipmapped Filtering */
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			     GL_LINEAR_MIPMAP_NEAREST );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
			     GL_LINEAR );

	    /* Generate The MipMapped Texture ( NEW ) */
	    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, TextureImage[0]->w,
			       TextureImage[0]->h, GL_BGR,
			       GL_UNSIGNED_BYTE, TextureImage[0]->pixels );
        }

    /* Free up any memory we may have used */
    if ( TextureImage[0] )
	    SDL_FreeSurface( TextureImage[0] );

    return Status;
}

void play_sound(unsigned char id){
	Mix_PlayChannel(-1, sounds[id], 0);	
}

void sdl(stack* stackptr){
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
		perror("Could not initialize screen!\n");
		exit(1);
	}
	
	int fullscreen, window_width, window_height, color_depth;
	
	// Read configuration
	pthread_mutex_lock(&mutex[0]);
	while(1){
		if(stackptr->id==0)
				fullscreen = *((int*)stackptr->val);
		if(stackptr->id==1)
				window_width = *((int*)stackptr->val);
		if(stackptr->id==2)
				window_height = *((int*)stackptr->val);
		if(stackptr->id==3)
				color_depth = *((int*)stackptr->val);

		stackptr=stackptr->next;
		if(stack_drop(0)==0xFF)break;
	}
	pthread_mutex_unlock(&mutex[0]);
		
	uint32_t flags;

	flags  = SDL_OPENGL;
	flags |= SDL_GL_DOUBLEBUFFER;
	flags |= SDL_HWPALETTE;
	flags |= (SDL_FULLSCREEN*fullscreen);
	flags |= (SDL_GetVideoInfo()->hw_available)?SDL_HWSURFACE:SDL_SWSURFACE;
	flags |= (!!(SDL_GetVideoInfo()->blit_hw))*SDL_HWSURFACE;

    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	if(SDL_SetVideoMode(window_width, window_height, color_depth, flags) == NULL){
		perror("Could not create window\n");
		exit(1);
	}
	
	// Set window caption
	SDL_WM_SetCaption("Cubebox", "Cubebox");
	
	    if ( !LoadGLTextures( ) )
			return;


	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
    glLightfv( GL_LIGHT1, GL_DIFFUSE, LightDiffuse );
    glLightfv( GL_LIGHT1, GL_POSITION, LightPosition );
    glEnable( GL_LIGHT1 );

    /* Full Brightness, 50% Alpha ( NEW ) */
    glColor4f( 1.0f, 1.0f, 1.0f, 0.5f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);


	while(1)
		usleep(50000);
}


void sound(stack* stackptr){
	int i;
	char filename[32];

	for(i=0; i<NUMBER_OF_SOUNDS; i++){
		sprintf(filename, "media/sound/%d.wav", i);
		sounds[i] = Mix_LoadWAV(filename);
		
		printf("Loaded '%s'", filename);
	}

	if(Mix_OpenAudio(42100, AUDIO_S16, 2, 4096))
		return;

	while(1){
		usleep(50000);
	}
}

//~ void destroy_sound(void){
	//~ Mix_CloseAudio();
//~ }
