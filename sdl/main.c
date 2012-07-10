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


int LoadGLTextures(){
	unsigned char i;
	
    SDL_Surface *TextureImage[1]; 

    if((TextureImage[0] = SDL_LoadBMP("media/images/textures/texturemap.bmp"))){
		glGenTextures(1, textures);

		glBindTexture(GL_TEXTURE_2D,textures[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->w,
			TextureImage[0]->h,0,GL_BGR,
			GL_UNSIGNED_BYTE,TextureImage[0]->pixels);

		if(TextureImage[0])
			SDL_FreeSurface(TextureImage[0]);
	}
	
	
	
	// And now, build a displaylist
	displaylists = glGenLists(256);
	
	glBindTexture(GL_TEXTURE_2D, textures[0]); 
	
	// Load every texture 1 time
	// into a new list.
	
	glNewList(displaylists, GL_COMPILE);
	glBegin(GL_QUADS);                                                     
		glTexCoord2f(0.0f, 1.0f/16); 		glVertex3f((-0.5f), (-0.5f), (0.5f));		
		glTexCoord2f(1.0f/16, 1.0f/16);		glVertex3f((0.5f),  (-0.5f), (0.5f));	
		glTexCoord2f(1.0f/16, 0.0f);		glVertex3f((0.5f),  (0.5f),  (0.5f));  	
		glTexCoord2f(0.0f, 0.0f);			glVertex3f((-0.5f), (0.5f),  (0.5f));		
		                                                               
		glTexCoord2f(1.0f/16, 1.0f/16);		glVertex3f((-0.5f), (-0.5f), (0.5f));	
		glTexCoord2f(0.0f,1.0f/16);			glVertex3f((-0.5f), (-0.5f), (-0.5f));	
		glTexCoord2f(0.0f, 0.0f);			glVertex3f((-0.5f), (0.5f),  (-0.5f));		
		glTexCoord2f(1.0f/16, 0.0);			glVertex3f((-0.5f), (0.5f),  (0.5f));		
		                                                               
		glTexCoord2f(1.0f/16, 1.0f/16);		glVertex3f((-0.5f), (-0.5f), (-0.5f));
		glTexCoord2f(0.0f, 1.0f/16);		glVertex3f((0.5f),  (-0.5f), (-0.5f));	
		glTexCoord2f(0.0f, 0.0f);			glVertex3f((0.5f),  (0.5f),  (-0.5f));  		
		glTexCoord2f(1.0f/16, 0.0f);		glVertex3f((-0.5f), (0.5f),  (-0.5f));	
		                                                               
		glTexCoord2f(0.0f, 1.0f/16);		glVertex3f((0.5f),  (-0.5f), (0.5f));		
		glTexCoord2f(1.0f/16, 1.0f/16);		glVertex3f((0.5f),  (-0.5f), (-0.5f));	
		glTexCoord2f(1.0f/16, 0.0f);		glVertex3f((0.5f),  (0.5f),  (-0.5f));		
		glTexCoord2f(0.0f, 0.0);			glVertex3f((0.5f),  (0.5f),  (0.5f));			
		                                                               
		glTexCoord2f(1.0f/16, 1.0f/16);		glVertex3f((-0.5f), (0.5f),  (-0.5f));
		glTexCoord2f(0.0f, 1.0f/16);		glVertex3f((0.5f),  (0.5f),  (-0.5f));		
		glTexCoord2f(0.0f, 0.0f);			glVertex3f((0.5f),  (0.5f),  (0.5f));  	
		glTexCoord2f(1.0f/16, 0.0f);		glVertex3f((-0.5f), (0.5f),  (0.5f));	
		                                                               
		glTexCoord2f(0.0f, 1.0f/16);		glVertex3f((-0.5f), (-0.5f), (-0.5f));	
		glTexCoord2f(1.0f/16, 1.0f/16);		glVertex3f((0.5f),  (-0.5f), (-0.5f));
		glTexCoord2f(1.0f/16, 0.0f);		glVertex3f((0.5f),  (-0.5f), (0.5f));  	
		glTexCoord2f(0.0f, 0.0f);			glVertex3f((-0.5f), (-0.5f), (0.5f));		
	glEnd();  
	glEndList();                                                           

	
	return 1;
}

void draw_cube(float x, float y, float z){
	glRotatef(-xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(-zrot, 0.0f, 0.0f, 1.0f);
	
	glTranslatef(-x, -y, -z);
	glCallList(displaylists);
}

void play_sound(unsigned char id){
	Mix_PlayChannel(-1, sounds[id], 0);	
}

void sdl(stack* stackptr){
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		perror("Could not initialize screen!\n");
		exit(1);
	}
	
	int fullscreen, window_width, window_height, color_depth;
	
	// Read configuration
	pthread_mutex_lock(&mutex[0]);
		stackptr=stack_head(0);
		while(1){
			if(stackptr->id==0)
				fullscreen = *((int*)stackptr->val);
			if(stackptr->id==1)
				window_width = *((int*)stackptr->val);
			if(stackptr->id==2)
				window_height = *((int*)stackptr->val);
			if(stackptr->id==3)
				color_depth = *((int*)stackptr->val);

			if(stackptr->id==0xFF) break;
			if((stackptr=stack_drop(0))==NULL) break;
			
		}
	pthread_mutex_unlock(&mutex[0]);
	
	
	Uint32 flags;
	flags = SDL_OPENGL | SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_HWACCEL;

	if(fullscreen == 1)
		flags |= SDL_FULLSCREEN;

	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	
	if(SDL_SetVideoMode(window_width, window_height, color_depth, flags) == NULL){
		perror("Could not create window\n");
		exit(1);
	}
	
	// Set window caption
	SDL_WM_SetCaption("Cubebox", "Cubebox");
	
	// Set Rotation to 0
	xrot=0;
	zrot=0;
	
	LoadGLTextures();

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.2f, 0.2f, 1.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	//~ glColor4f( 1.0f, 1.0f, 1.0f, 0.5f);
	//~ glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glViewport(0, 0, (GLint)window_width, (GLint)window_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)window_width/(float)window_height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);

	while(1){

		pthread_mutex_lock(&mutex[0]);
			stackptr=stack_head(0);
			if((stackptr != NULL)&&(stackptr->id!=0xFF)){
				
					if(stackptr->id==7){
						xrot = *((float*)stackptr->val);
					} else if(stackptr->id==8){
						zrot = *((float*)stackptr->val);
					}
			}
		pthread_mutex_unlock(&mutex[0]);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -5.0f);
		
		draw_cube(0, 0, 0);
		
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -5.0f);
		
		draw_cube(1, 0, 0);

		SDL_GL_SwapBuffers();
		SDL_Delay(40);
	}
}


void sound(stack* stackptr){
	int i;
	char filename[32];
	
	if(SDL_Init(SDL_INIT_AUDIO) != 0){
		perror("Could not initialize audio!\n");
		exit(1);
	}

	if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096))
		return;

	for(i=0; i<NUMBER_OF_SOUNDS; i++){
		sprintf(filename, "media/sound/%d.wav", i);
		sounds[i] = Mix_LoadWAV(filename);
		if(sounds[i] == NULL){
			perror("Error: Could not read sound files correctly!\n");
			halt();
		}
		
		printf("Loaded '%s'\n", filename);
	}
	//~ return;
	while(1){
		// We can directly receive the id and play it
		pthread_mutex_lock(&mutex[1]);		
		stackptr=stack_head(1);
		if(stackptr->id!=0xFF){
			play_sound(stackptr->id);
			stackptr=stack_drop(1);
		}
		pthread_mutex_unlock(&mutex[1]);
				
		SDL_Delay(50);
	}
}

//~ void destroy_sound(void){
	//~ Mix_CloseAudio();
//~ }
