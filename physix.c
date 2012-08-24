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


/****h* Client/Physix
 * NAME
 *   Physix
 * FUNCTION
 *   Basic physic computations
 *
 ******/

#include "physix.h"

/****f* Physix/Physix
 * NAME
 *   physix
 * FUNCTION
 *   Never ending physical computations. Started in a own thread.
 * NOTE
 *   First part reads the pressed keys from the stack. Only the second
 *   part is responsible for the computations.
 * SOURCE
 */
void physix(void){
	// Some values that may be affected of changes in the stack
	static double x=0;
	static double y=0;
	static double z=0;
	static double xrot=0;
	static double yrot=0;
	static char forwards=0, left=0, backwards=0, right=0;
	
	stack *stackptr;
	float *floatptr;
	

	
	OPEN_STACK(THREAD_PHYSICS);
		stackptr = stack_head(THREAD_PHYSICS);
	
		if(stackptr != NULL){	
			while(stackptr->id != 0xFF){			
				// movement flags

				// Process stackptr
					switch(stackptr->id){
						case 1:
							right = 1;
							stack_drop(THREAD_PHYSICS);
						break;
						case 2:
							right = 0;
							stack_drop(THREAD_PHYSICS);
						break;


						case 3:
							left = 1;
							stack_drop(THREAD_PHYSICS);
						break;
						case 4:
							left = 0;
							stack_drop(THREAD_PHYSICS);
						break;


						case 9:
							forwards = 1;
							stack_drop(THREAD_PHYSICS);
						break;
						case 10:
							forwards = 0;
							stack_drop(THREAD_PHYSICS);
						break;

							
						case 11:
							backwards = 1;
							stack_drop(THREAD_PHYSICS);
						break;
						case 12:
							backwards = 0;
							stack_drop(THREAD_PHYSICS);
						break;
						
						case 13:
							floatptr = POP_STACK(THREAD_PHYSICS, float);
							xrot += *floatptr;
							free(floatptr);
						break;
						case 14:
							floatptr = POP_STACK(THREAD_PHYSICS, float);
							yrot += *floatptr;
							free(floatptr);
						break;

						case 0xFF:						
						default:
							stack_drop(THREAD_PHYSICS);
						break;
					}
					stackptr = stack_head(THREAD_PHYSICS);
				}
		}
	CLOSE_STACK(THREAD_PHYSICS);
	
	
	/* Physical computations start here */

	
	
	if(forwards)
		printf("Walk forwards\n");
	
	if(backwards)
		printf("Walk backwards\n");
	
	if(left)
		printf("Walk left\n");
	
	if(right)
		printf("Walk right\n");
	
}
/******/
