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
	
	// Graphic configuration
	char *check;
	int val;

	// window-width
	val=atoi(((check=search_for_key("window-width", 1))!=NULL)?check:"0");
	stack_push(0, 1, &val, sizeof(int));
	
	// window-height
	val=atoi(((check=search_for_key("window-height", 1))!=NULL)?check:"0");
	stack_push(0, 2, &val, sizeof(int));
	
	// color-depth
	val=atoi(((check=search_for_key("color-depth", 1))!=NULL)?check:"0");
	stack_push(0, 3, &val, sizeof(int));
	
	// fullscreen
	val=atoi(((check=search_for_key("fullscreen", 1))!=NULL)?check:"0");
	stack_push(0, 0, &val, sizeof(int));
	
	search_destroy();
}

void halt(){
	int i;
	for(i=0;i<NUMTHREADS;i++)
		pthread_kill(thread[i], 3);
	SDL_Quit();
}

/* Init the SDL environment */
void *init_sdl(void* stackptr){
	sdl((stack*) stackptr);
	return NULL;
}

/* Init sound */
void *init_sound(void* stackptr){
	sound((stack*) stackptr);
	return NULL;
}

/* Init map */
void *init_map(void* stackptr){
	map((stack*) stackptr);
	return NULL;
}

/* Init com */
void *init_com(void* stackptr){
	com((stack*) stackptr);
	return NULL;
}

/* Init io */
void *init_io(void* stackptr){
	io((stack*) stackptr);
	return NULL;
}


/* Init cubebox */
void init(void){
	int i;
	for(i=0;i<NUMTHREADS;i++){
		falloc(thread_stack[i], sizeof(stack));
		thread_stack[i]->id=0xFF;
		pthread_mutex_init(&mutex[i], NULL);
	}
	
	config();
	printf("Read configuration successfully!\n");
	
	pthread_create(&thread[0], NULL, init_sdl, (void *)thread_stack[0]);
	pthread_create(&thread[1], NULL, init_sound, (void *)thread_stack[1]);
	pthread_create(&thread[2], NULL, init_map, (void *)thread_stack[2]);
	pthread_create(&thread[3], NULL, init_com, (void *)thread_stack[3]);
	pthread_create(&thread[4], NULL, init_io, (void *)thread_stack[4]);
}


