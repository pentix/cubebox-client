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


#include "physix.h"

void physix(void){
	while(1){
		stack *stackptr;
		OPEN_STACK(THREAD_PHYSICS);
			stackptr = stack_head(THREAD_PHYSICS);

			// Process stackptr
			if(stackptr != NULL){
				switch(stackptr->id){
					case 9:
						printf("Walk forwards\n");
						break;
					
					case 11:
						printf("Walk backwards\n");
						break;

					case 3:
						printf("Walk left\n");
						break;

					case 1:
						printf("Walk right\n");
						break;
					
					case 0xFF:
					default:
					break;
				}
				
				stack_drop(THREAD_PHYSICS);
			}
		CLOSE_STACK(THREAD_PHYSICS);
		
		// sleep 50ms -> avg. 20fps input
		usleep(50000);
	}
}
