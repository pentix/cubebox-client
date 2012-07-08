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

/* Infinite loop to read all inputs */
void read_inputs(stack* stackptr){
	int readin_keys[256] = {0};//@params 0=key up; 1=key down

	while(1){
		while(SDL_PollEvent(&input_event) == 1){
			if(input_event.type == SDL_KEYDOWN){
				readin_keys[input_event.key.keysym.sym]=1;
			}
			if(input_event.type==SDL_KEYUP){
				readin_keys[input_event.key.keysym.sym]=0;
			}

			if(readin_keys[SDLK_ESCAPE]==1){
				halt();
			}

			if(readin_keys[SDLK_w]==1){
				//move player.....

			}
		}
	usleep(50000);
	}
}

void io(stack* stackptr){
	read_inputs(stackptr);
}
