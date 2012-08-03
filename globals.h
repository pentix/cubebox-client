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


//Default
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

//gl
#include <GL/glut.h>
#include <portaudio.h>
#include <GL/glu.h>
#include <GL/gl.h>

//pthread
#include <pthread.h>
#include <signal.h>

//Parser
#include "../shared/libs/parser/parser.h"

#define falloc(ptr,n_bytes) while((ptr=malloc(n_bytes))==NULL);

//FIFO
typedef struct stack{
	unsigned char id;
	void *val;
	struct stack *next;
} stack;

extern void halt();


#define NUMTHREADS 5

#define GRAPHIC		0
#define SOUND		1
#define MAP_GEN		2
#define SYNC_PLAYER	3
#define IO_PHYSIC	4

#define GRAPHIC_FPS 20

pthread_t thread[NUMTHREADS];
stack *thread_stack[NUMTHREADS];
pthread_mutex_t mutex[NUMTHREADS];

#include "com/server/main.h"
#include "com/thread/main.h"
#include "io/main.h"
#include "gl/main.h"
#include "map/main.h"

#endif
