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

void sound(){}

void sdl(){
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
		perror("Could not initialize screen!\n");
		exit(1);
	}
	
	if(SDL_SetVideoMode(800,600, 8, SDL_SWSURFACE) == NULL){
		perror("Could not create window\n");
		exit(1);
	}
	
	// Set window caption
	SDL_WM_SetCaption("Cubebox", "Cubebox");
	
	while(1)usleep(50000);
}
