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
	char readin_keys[256] = {0};	//@params 0=key up; 1=key down

	while(1){
		while(SDL_PollEvent(&input_event) == 1){
			if(input_event.type == SDL_QUIT)
				halt();
			
			if(input_event.type == SDL_KEYDOWN)
				readin_keys[input_event.key.keysym.sym]=1;
			
			if(input_event.type==SDL_KEYUP)
				readin_keys[input_event.key.keysym.sym]=0;
			
		}

		if(readin_keys[SDLK_ESCAPE]){
			halt();
		}

		if(readin_keys[SDLK_w]){
			fprintf(stderr, "W");
		}

		
		if(readin_keys[SDLK_SPACE]){
			stack_push(1, SND_JUMP, NULL, 0);
			SDL_Delay(500);
		}
		
	SDL_Delay(50);
	
	}
}

void io(stack* stackptr){
	read_inputs(stackptr);
}
