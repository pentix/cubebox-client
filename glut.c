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
 * RESULT
 *   Perspective gets adjusted to new window size
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


/****f* Glut/Keyboard
 * NAME
 *   keyboard
 * FUNCTION
 *   keyboard is a glut callback function.
 *   It gets called when a "normal" key is pressed.
 *   This function is mainly responsible for processing
 *   keyboard inputs.
 * INPUTS
 *   key -- The ASCII Code of the pressed key
 *   x -- The x mouse position
 *   y -- The y mouse position 
 * NOTES
 *   Function arguments are provided by glut.
 * SOURCE
 */
void keyboard(unsigned char key, int x, int y){
	// Convert lowercase letters to uppercase letters
	if(key > 96 && key < 123)
		key-=32;

	OPEN_STACK(THREAD_PHYSICS);
	if(key == 'W'){
			stack_push(THREAD_PHYSICS, 9, NULL, 0);
	} else if(key == 'S'){
			stack_push(THREAD_PHYSICS, 11, NULL, 0);
	} else if(key == 'A'){
			stack_push(THREAD_PHYSICS, 3, NULL, 0);
	} else if(key == 'D'){
			stack_push(THREAD_PHYSICS, 1, NULL, 0);
	}
	CLOSE_STACK(THREAD_PHYSICS);
	
	// Terminate game with Esc
	if(key == 27){
		halt();
	}
}
/******/


/****f* Glut/Keyboard_up
 * NAME
 *   keyboard_up
 * FUNCTION
 *   keyboard_up is a glut callback function.
 *   It gets called when a "normal" key is released.
 *   This function is mainly responsible for processing
 *   keyboard inputs.
 * INPUTS
 *   key -- The ASCII Code of the released key
 *   x -- The x mouse position
 *   y -- The y mouse position 
 * NOTES
 *   Function arguments are provided by glut.
 * SOURCE
 */
void keyboard_up(unsigned char key, int x, int y){
	// Convert lowercase letters to uppercase letters
	if(key > 96 && key < 123)
		key-=32;
	
	OPEN_STACK(THREAD_PHYSICS);
	if(key == 'W'){
			stack_push(THREAD_PHYSICS, 10, NULL, 0);
	} else if(key == 'S'){
			stack_push(THREAD_PHYSICS, 12, NULL, 0);
	} else if(key == 'A'){
			stack_push(THREAD_PHYSICS, 4, NULL, 0);
	} else if(key == 'D'){
			stack_push(THREAD_PHYSICS, 2, NULL, 0);
	}
	CLOSE_STACK(THREAD_PHYSICS);

}
/******/


/****f* Glut/Mouse
 * NAME
 *   mouse
 * FUNCTION
 *   mouse is a glut callback function.
 *   It gets called when the mouse is moved.
 * RESULT
 *   Mouse gets centred in window.
 * NOTES
 *   Function arguments are provided by glut.
 * SOURCE
 */
void mouse(){
	// Reset pointer to the center of the window
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	glutWarpPointer(width/2, height/2);
}
/******/

/****f* Glut/Display
 * NAME
 *   display
 * FUNCTION
 *   display is a glut callback function.
 *   It gets cyclicaly called with limited FPS.
 * INPUTS
 * 
 * RESULT
 *   Everything gets drawed here.
 * SOURCE
 */
void display(){

	stack *stackptr;
	
	float zrot, xrot, *floatptr;
	long *longptr;

	OPEN_STACK(THREAD_GRAPHICS);
	
	while(((stackptr=stack_head(0)) != NULL)&&(stack_head(0)->id!=0xFF)){
		switch(stackptr->id){
			case 7:
				floatptr=POP_STACK(THREAD_GRAPHICS, float);
				zrot += *(floatptr);
				free(floatptr);
			break;
			case 8:
				floatptr=POP_STACK(THREAD_GRAPHICS, float);
				xrot += *(floatptr);
				free(floatptr);
			break;
			case 11:
				longptr = POP_STACK(THREAD_GRAPHICS, long);

				glLoadIdentity();
				glTranslatef(0.0f, 0.0f, -5.0f);
				
				//~ draw_cube(*(longptr), *(longptr+1), *(longptr+2), (short)(*(longptr+3)));

				free(longptr);
			break;
			default:
				longptr=POP_STACK(THREAD_GRAPHICS, long);
				free(longptr);
			break;
		}
	}
	CLOSE_STACK(THREAD_GRAPHICS);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	//~ draw_cube(0, 0, 0, 1);

	glLoadIdentity();
	glRotatef(xrot, 1000, 1000, 1000);
	//~ draw_ground();
	
	glutSwapBuffers();
}
/******/

