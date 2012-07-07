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

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#define __DEBUG__

#define NUMTHREADS 1

//Default
#include <stdio.h>
#include <stdlib.h>

//SDL
#include <SDL/SDL.h>

//pthread
#include <pthread.h>

//Windows
#ifdef WIN
	#include <windows.h>
#endif

//Parser
#include "../shared/libs/parser/parser.h"

#define falloc(ptr,n_bytes) while((ptr=malloc(n_bytes))==NULL);

pthread_t thread[NUMTHREADS];
// 0: SDL_GRAPHIC

void* thread_stack[NUMTHREADS];

#endif
