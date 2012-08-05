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


/****h* Client/Globals
 * NAME
 *   globals
 * FUNCTION
 *   This module provides the headers used in the project.
 ******/


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

typedef struct stack{
	unsigned char id;
	void *val;
	struct stack *next;
} stack;

#define GRAPHIC		0
#define SOUND		1
#define MAP_GEN		2
#define SYNC_PLAYER	3
#define IO_PHYSIC	4

#include "thread.h"
#include "server.h"
#include "physix.h"
#include "glut.h"
#include "map.h"

#endif
