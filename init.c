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

#include "globals.h"
#include "init.h"

void config(void){
	search_init("./etc/client.conf");
	
	int window_width  = atoi(search_for_key("window-width", 0));
	int window_height = atoi(search_for_key("window-height", 0));
	int color_depth  = (unsigned char)atoi(search_for_key("color-depth", 0));
		
	search_destroy();
}

void halt(){
	int i;
	for(i=0;i<NUMTHREADS;i++)
		pthread_kill(thread[i], 3);
	SDL_Quit();
}

/* Init the SDL environment */
void *init_sdl(){
	sdl();
	return NULL;
}

/* Init sound */
void *init_sound(){
	sound();
	return NULL;
}

/* Init map */
void *init_map(){
	map();
	return NULL;
}

/* Init com */
void *init_com(){
	com();
	return NULL;
}

/* Init io */
void *init_io(){
	io();
	return NULL;
}


/* Init cubebox */
void init(void){
	config();
	printf("Read configuration successfully!\n");
	pthread_create(&thread[0], NULL, init_sdl, NULL);
	pthread_create(&thread[1], NULL, init_sound, NULL);
	pthread_create(&thread[2], NULL, init_map, NULL);
	pthread_create(&thread[3], NULL, init_com, NULL);
	pthread_create(&thread[4], NULL, init_io, NULL);
}


