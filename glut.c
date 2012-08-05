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


/****h* Client/Glut
 * NAME
 *   Glut
 * FUNCTION
 *   This module provides the Glut callback functions.
 *
 ******/
 
 
#include "glut.h"

/****f* Glut/Reshape
 * NAME
 *   reshape
 * FUNCTION
 *   reshape is a glut callback function.
 *   It gets called when the window size is modified.
 * INPUTS
 *   * width -- window width
 *   * height -- window height
 * NOTES
 *   Function arguments are provided by glut.
 * SOURCE
 */
void reshape(int width, int height){
	if (height==0){
		height=1;
	}
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glutWarpPointer(width/2, height/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									
}
/******/

void mouse(){
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	glutWarpPointer(width/2, height/2);	
}

void display(){
	
}

void keyboard(unsigned char key, int x, int y){
	if(key==27){
		raise(SIGTERM);
	}
	printf("%c\n", key);
}


//~ 
//~ #ifndef WIN
//~ #include <X11/Xlib.h>
//~ #endif
//~ 
//~ 
//~ void gl(stack* stackptr){
//~ 
	//~ #ifndef WIN
		//~ XInitThreads();
	//~ #endif
	//~ 
	//~ if(gl_init(1,{"\0",NULL}) != 0){
		//~ perror("Could not initialize screen!\n");
		//~ exit(1);
	//~ }
	//~ 
	//~ int fullscreen, window_width, window_height, color_depth;
	//~ 
	//~ // Read configuration
	//~ pthread_mutex_lock(&mutex[0]);
		//~ stackptr=stack_head(0);
		//~ while(1){
			//~ if(stackptr->id==0)
				//~ fullscreen = *((int*)stackptr->val);
			//~ if(stackptr->id==1)
				//~ window_width = *((int*)stackptr->val);
			//~ if(stackptr->id==2)
				//~ window_height = *((int*)stackptr->val);
			//~ if(stackptr->id==3)
				//~ color_depth = *((int*)stackptr->val);
			//~ if(stackptr->id==0xFF) break;
			//~ if((stackptr=stack_drop(0))==NULL) break;
		//~ }
	//~ pthread_mutex_unlock(&mutex[0]);
	//~ 
	//~ 
	//~ Uint32 flags;
	//~ flags = gl_OPENGL | gl_DOUBLEBUF | gl_HWSURFACE | gl_HWACCEL | (!!fullscreen)*gl_FULLSCREEN;
	//~ 
	//~ gl_GL_SetAttribute( gl_GL_DOUBLEBUFFER, 1 );
//~ 
	//~ if(gl_SetVideoMode(window_width, window_height, color_depth, flags) == NULL){
		//~ perror("Could not create window\n");
		//~ exit(1);
	//~ }
//~ 
	//~ // Set window caption
	//~ gl_WM_SetCaption("Cubebox", "Cubebox");
	//~ 
	//~ // Grab and hide cursor
	//~ gl_WM_GrabInput(gl_GRAB_ON);
	//~ gl_ShowCursor(gl_DISABLE);
	//~ 
	//~ // Set Rotation to 0
	//~ xrot=0;
	//~ zrot=0;
	//~ 
	//~ LoadGLTextures();
//~ 
	//~ glEnable(GL_TEXTURE_2D);
	//~ glEnable(GL_DEPTH_TEST);
	//~ glShadeModel(GL_SMOOTH);
	//~ glDepthFunc(GL_LEQUAL);
	//~ glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	//~ glClearColor(0.2f, 0.2f, 1.0f, 1.0f);
	//~ glClearDepth(1.0f);
	//~ 
	//~ glColor4f( 1.0f, 1.0f, 1.0f, 0.5f);
	//~ glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//~ 
	//~ glViewport(0, 0, (GLint)window_width, (GLint)window_height);
	//~ glMatrixMode(GL_PROJECTION);
	//~ glLoadIdentity();
	//~ gluPerspective(45.0f, (float)window_width/(float)window_height, 0.1f, 100.0f);
	//~ glMatrixMode(GL_MODELVIEW);
//~ 
	//~ 
	//~ long *longptr;
//~ 
	//~ while(1){
//~ 
		//~ pthread_mutex_lock(&mutex[0]);
			//~ stackptr=stack_head(0);
			//~ while((stackptr != NULL)&&(stackptr->id!=0xFF)){
				//~ switch(stackptr->id){
					//~ case 7:
						//~ zrot += *((float*)stackptr->val);
					//~ break;
					//~ case 8:
						//~ xrot += *((float*)stackptr->val);
					//~ break;
					//~ case 11:
						//~ longptr = ((long *)stackptr->val);
//~ 
						//~ glLoadIdentity();
						//~ glTranslatef(0.0f, 0.0f, -5.0f);
						//~ draw_cube(*(longptr), *(longptr+1), *(longptr+2), (short)(*(longptr+3)));
//~ 
						//~ free(longptr);
					//~ break;
				//~ }
				//~ stackptr=stack_drop(0);
			//~ }
		//~ pthread_mutex_unlock(&mutex[0]);
		//~ 
		//~ glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//~ 
		//~ glLoadIdentity();
		//~ glTranslatef(0.0f, 0.0f, -5.0f);
		//~ draw_cube(0, 0, 0, 1);
//~ 
		//~ glLoadIdentity();
		//~ glRotatef(15000000000*xrot, 1000, 1000, 1000);
		//~ draw_ground();
//~ 
		//~ gl_GL_SwapBuffers();
		//~ gl_Delay(40);
	//~ }
//~ }
//~ 
//~ 
//~ void sound(stack* stackptr){
	//~ int i;
	//~ char filename[32];
	//~ 
	//~ if(gl_Init(gl_INIT_AUDIO) != 0){
		//~ perror("Could not initialize audio!\n");
		//~ exit(1);
	//~ }
//~ 
	//~ if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096))
		//~ return;
//~ 
	//~ for(i=0; i<NUMBER_OF_SOUNDS; i++){
		//~ sprintf(filename, "media/sound/%d.wav", i);
		//~ sounds[i] = Mix_LoadWAV(filename);
		//~ if(sounds[i] == NULL){
			//~ perror("Error: Could not read sound files correctly!\n");
			//~ halt();
		//~ }
		//~ 
		//~ #ifdef DEBUG
			//~ printf("Loaded '%s'\n", filename);
		//~ #endif
	//~ }
	//~ return;
	//~ while(1){
		//~ // We can directly receive the id and play it
		//~ pthread_mutex_lock(&mutex[1]);		
		//~ stackptr=stack_head(1);
		//~ if(stackptr->id!=0xFF){
			//~ play_sound(stackptr->id);
			//~ stackptr=stack_drop(1);
		//~ }
		//~ pthread_mutex_unlock(&mutex[1]);
				//~ 
		//~ gl_Delay(50);
	//~ }
//~ }
//~ 
//~ void destroy_sound(void){
	//~ Mix_CloseAudio();
//~ }
