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


/****h* Client/Init
 * NAME
 *   Init
 * FUNCTION
 *   Thread initialition and glut setup.
 *
 ******/

#include "init.h"

/****f* Init/GetUsec
 * NAME
 *   getUsec
 * FUNCTION
 *   getUsec calculates usecs from gettimeofday.
 * INPUTS
 * RESULT
 *   returns usecs
 * SOURCE
 */
unsigned long getUsec(){
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return (unsigned long)1000000*(unsigned long)tv.tv_sec+(unsigned long)tv.tv_usec;
}
/******/

/****f* Init/Config
 * NAME
 *   config
 * FUNCTION
 *   config reads the config file.
 * INPUTS
 * RESULT
 *   configuration gets pushed to the related thread.
 * SOURCE
 */
void config(void){
	// Graphic configuration
	char *check;
	int val[4];
	search_init("./etc/client.conf");

	// window-width
	val[0]=atoi(((check=search_for_key("window-width", 1))!=NULL)?check:"900");
		
	// window-height
	val[1]=atoi(((check=search_for_key("window-height", 1))!=NULL)?check:"600");
	
	// color-depth
	val[2]=atoi(((check=search_for_key("color-depth", 1))!=NULL)?check:"24");
	
	// fullscreen
	val[3]=atoi(((check=search_for_key("fullscreen", 1))!=NULL)?check:"0");

	OPEN_STACK(THREAD_GRAPHICS);
		stack_push(THREAD_GRAPHICS, 1, &val[0], sizeof(int));
		stack_push(THREAD_GRAPHICS, 2, &val[1], sizeof(int));
		stack_push(THREAD_GRAPHICS, 3, &val[2], sizeof(int));
		stack_push(THREAD_GRAPHICS, 0, &val[3], sizeof(int));
	CLOSE_STACK(THREAD_GRAPHICS);
	
	search_destroy();
}
/******/

/****f* Init/Halt
 * NAME
 *   halt
 * FUNCTION
 *   halt kills all threads.
 * INPUTS
 * RESULT
 *   Stack and threads are properly terminated.
 * SOURCE
 */
void halt(void){
	printf("Bye!\n");
	raise(SIGTERM);
}
/******/

/****f* Init/Graphix
 * NAME
 *   graphix
 * FUNCTION
 *   graphix calls the display function and limit the fps.
 * INPUTS
 * SOURCE
 */
void graphix(){
	TimedCallback(display, GRAPHIC_FPS, 1);
}
/******/

/****f* Init/Init_graphic
 * NAME
 *   init_graphic
 * FUNCTION
 *   init_graphic initializes the gl surface.
 * INPUTS
 * SOURCE
 */
void *init_graphic(){
	char *argv[]={"cubebox\0",NULL};
	int argc=1, *intptr, width, height;
	char fullscreen=0;
	stack *stackptr;
	char gamemode[256];
	BitMap *image;
    char alpha_col[3];
    
		
	OPEN_STACK(THREAD_GRAPHICS);
	
	while(((stackptr=stack_head(THREAD_GRAPHICS)) != NULL)&&(stack_head(THREAD_GRAPHICS)->id!=0xFF)){
		switch(stackptr->id){
			case 0:
				intptr=POP_STACK(THREAD_GRAPHICS, int);
				if(*(intptr))fullscreen=1;
				free(intptr);
			break;
			case 1:
				intptr=POP_STACK(THREAD_GRAPHICS, int);
				width=*(intptr);
				free(intptr);
			break;
			case 2:
				intptr=POP_STACK(THREAD_GRAPHICS, int);
				height=*(intptr);
				free(intptr);
			break;
			default:
				intptr=POP_STACK(THREAD_GRAPHICS, int);
				free(intptr);
			break;
		}
	}

	CLOSE_STACK(THREAD_GRAPHICS);
	
	glutInit			(&argc,argv);
	glutInitDisplayMode	(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize	(width, height);

	if(fullscreen){
		sprintf(gamemode, "%dx%d:24", width, height);
		glutGameModeString(gamemode);
		glutEnterGameMode(); 
	}else{
		glutCreateWindow("CUBEBOX");
	}
	
	glutDisplayFunc		(graphix);
	glutReshapeFunc		(reshape);
	glutKeyboardFunc	(keyboard);
	glutKeyboardUpFunc	(keyboard_up);
	glutIgnoreKeyRepeat (1);
	glutSetCursor		(GLUT_CURSOR_FULL_CROSSHAIR);
	glutIdleFunc		(graphix);
	glutPassiveMotionFunc(mouse);
	
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	alpha_col[0]=0xFF;
	alpha_col[1]=0xFF;
	alpha_col[2]=0xFF;

	image=LoadBmp("./media/images/textures/texturemap.bmp", BMP_ENABLE_ALPHA|BMP_ENABLE_ALPHA_COL, 0x00, alpha_col);
    
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image->height, image->width, 0, GL_BGRA, GL_UNSIGNED_BYTE, image->data);

	FreeBmp(image);
	
	glutMainLoop();
	
	return NULL;
}
/******/

/****f* Init/Init_sound
 * NAME
 *   init_sound
 * FUNCTION
 *   init_sound initializes portaudio.
 * INPUTS
 * NOTES
 *   Not implemented yet.
 * SOURCE
 */
void *init_sound(){
	return NULL;
}
/*****/

/****f* Init/Init_map
 * NAME
 *   init_map
 * FUNCTION
 *   init_map initializes the worldgenerator.
 * INPUTS
 * NOTES
 *   Not implemented yet.
 * SOURCE
 */
void *init_map(){
	return NULL;
}
/******/

/****f* Init/Init_com
 * NAME
 *   init_com
 * FUNCTION
 *   init_com initializes the socket for the server communication.
 * INPUTS
 * NOTES
 *   Not implemented yet.
 * SOURCE
 */
void *init_com(){
	return NULL;
}
/******/

/****f* Init/Init_physix
 * NAME
 *   init_physix
 * FUNCTION
 *   init_physix initializes the function for movement and gravity calculations.
 * INPUTS
 * NOTES
 *   Not implemented yet.
 * SOURCE
 */
void *init_physix(void* stackptr){
	while(1)
		TimedCallback(physix, 60, 1);
	return NULL;
}
/******/

/****f* Init/Init
 * NAME
 *   init
 * FUNCTION
 *   init initializes the threads.
 * INPUTS
 * SOURCE
 */
void init(void){
	int i;
	for(i=0;i<NUMTHREADS;i++){
		falloc(thread_stack[i], sizeof(stack));
		thread_stack[i]->id=0xFF;
		pthread_mutex_init(&mutex[i], NULL);
	}
	
	signal(SIGABRT, NULL);
	
	config();
	
	#ifdef DEBUG
		printf("Read configuration successfully!\n");
	#endif
	
	
	pthread_create(&thread[0], NULL, init_graphic, (void *)thread_stack[0]);
	pthread_create(&thread[1], NULL, init_sound, (void *)thread_stack[1]);
	pthread_create(&thread[2], NULL, init_map, (void *)thread_stack[2]);
	pthread_create(&thread[3], NULL, init_com, (void *)thread_stack[3]);
	pthread_create(&thread[4], NULL, init_physix, (void *)thread_stack[4]);
}
/*****/
