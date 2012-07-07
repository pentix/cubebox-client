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

void io(){}

/* Infinite loop to read all inputs */
void read_inputs(void){
	while(1){
		while(SDL_PollEvent(&input_event)){
			if(input_event.type == SDL_KEYDOWN){
				switch(input_event.key.keysym.sym){
				case SDLK_ESCAPE:
					pthread_exit(NULL);
					break;
				default: break;
				}
			}
		}
	}
}
