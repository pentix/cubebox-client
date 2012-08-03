//~ /*
 //~ * Copyright (c) 2012, The Cubebox Team <http://cubebox.bplaced.net/>
 //~ * 
 //~ * 
 //~ * This file is part of cubebox.
 //~ * 
 //~ * cubebox is free software: you can redistribute it and/or modify
 //~ * it under the terms of the GNU General Public License as published by
 //~ * the Free Software Foundation, either version 3 of the License, or
 //~ * (at your option) any later version.
 //~ * 
 //~ * cubebox is distributed in the hope that it will be useful,
 //~ * but WITHOUT ANY WARRANTY; without even the implied warranty of
 //~ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 //~ * GNU General Public License for more details.
 //~ * 
 //~ * You should have received a copy of the GNU General Public License
 //~ * along with cubebox.  If not, see <http://www.gnu.org/licenses/>.
 //~ *
//~ */
//~ 
//~ 
//~ #include "main.h"
//~ 
//~ /* Infinite loop to read all inputs */
//~ void read_inputs(char key, int a, int b){
	//~ char readin_keys[256] = {0};	//@params 0=key up; 1=key down
	
	//~ if(input_event.type==GLUT_MOUSEMOTION){
		//~ float xrel = input_event.motion.xrel*MOUSE_SENSITIVITY;
		//~ float zrel = input_event.motion.yrel*MOUSE_SENSITIVITY;
		//~ 
				//~ pthread_mutex_lock(&mutex[0]);
				//~ stack_push(0, 7, (void *)&xrel, sizeof(float));
					//~ stack_push(0, 8, (void *)&zrel, sizeof(float));
				//~ pthread_mutex_unlock(&mutex[0]);
				//~ 
				//~ #ifdef DEBUG
					//~ printf("Xrel: %f Zrel: %f\n", xrel, zrel);
				//~ #endif
			//~ }
	//~ }
//~ 
	//~ if(readin_keys[GLUT_KEY_ESCAPE]){
		//~ halt();
	//~ }
//~ 
	//~ if(readin_keys[GLUT_KEY_w]){
		//~ fprintf(stderr, "W");
	//~ }
//~ 
	//~ 
	//~ if(readin_keys[GLUT_KEY_SPACE]){  // TODO: and player is not in air
		//~ pthread_mutex_lock(&mutex[1]);
			//~ stack_push(1, SND_JUMP, NULL, 0);
		//~ pthread_mutex_unlock(&mutex[1]);
	//~ }
		//~ 
	//~ usleep(50);
	//~ 
	//~ }
//~ }
//~ 
//~ void io(stack* stackptr){
	//~ read_inputs(stackptr);
//~ }
