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


#include "init.h"

/* Config values */
struct config __config;
FILE *config_file;


/* Parse the config into the __config struct */
void read_configuration(void){
	config_file = fopen("../shared/etc/client.conf", "r");
	search_init(config_file);
	
	__config.window_width  = atoi(search_for_key("window-width", 0));
	__config.window_height = atoi(search_for_key("window-height", 0));
	__config.color_depth  = (unsigned char)atoi(search_for_key("color-depth", 0));
		
	search_destroy();
	fclose(config_file);
}


/* Init the SDL environment */
void init_sdl_environment(void){
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
		perror("Could not initialize screen!\n");
		exit(1);
	}
	
	window = SDL_SetVideoMode(__config.window_width, __config.window_height, __config.color_depth, SDL_SWSURFACE); 
	if(window == NULL){
		perror("Could not create window\n");
		exit(1);
	}
	
	
	// Set @Exit function to SQL_Quit
	atexit(SDL_Quit);
}


/* Init cubebox */
void cubebox_init(void){
	read_configuration();
	
	#ifdef __DEBUG__
		printf("Read window-width \t\t = \t\t %dpx\n", __config.window_width);
		printf("Read window-height \t\t = \t\t %dpx\n", __config.window_height);
		printf("Read color-depth \t\t = \t\t %d bit\n", __config.color_depth);
	#endif
	
	printf("Read configuration successfully!\n");
	
	init_sdl_environment();
}


/* Destroy used memory ressources */
void cubebox_destroy(void){
	
}
