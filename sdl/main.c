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


void play_sound(unsigned char id){
	Mix_PlayChannel(-1, sounds[id], 0);	
}

void sdl(stack* stackptr){
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
		perror("Could not initialize screen!\n");
		exit(1);
	}
	
	int fullscreen, window_width, window_height, color_depth;
	
	// Read configuration
	pthread_mutex_lock(&mutex[0]);
		switch(stackptr->id){
		case 0:
			fullscreen = (int)stackptr->val;
		break;
		case 1:
			window_width = (int)stackptr->val;
		break;
		case 2:
			window_height = (int)stackptr->val;
		break;
		case 3:
			color_depth = (int)stackptr->val;
		break;

		default:
		break;
		}
	pthread_mutex_unlock(&mutex[0]);
	
	Uint32 flags;
	if(fullscreen == 0){
		flags = SDL_SWSURFACE;
	} else {
		flags = SDL_SWSURFACE | SDL_FULLSCREEN;
	}
	
	if(SDL_SetVideoMode(window_width, window_height, color_depth, flags) == NULL){
		perror("Could not create window\n");
		exit(1);
	}
	
	// Set window caption
	SDL_WM_SetCaption("Cubebox", "Cubebox");
	
	while(1)
		usleep(50000);
}


void sound(stack* stackptr){
	int i;
	char filename[32];

	for(i=0; i<NUMBER_OF_SOUNDS; i++){
		sprintf(filename, "media/sound/%d.wav", i);
		sounds[i] = Mix_LoadWAV(filename);
		
		printf("Loaded '%s'.wav", filename);
	}

	if(Mix_OpenAudio(42100, AUDIO_S16, 2, 4096))
		return 1;

	while(1){
		usleep(50000);
	}
}

//~ void destroy_sound(void){
	//~ Mix_CloseAudio();
//~ }
