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


/****h* Client/Thread
 * NAME
 *   Thread
 * FUNCTION
 *   This module provides functions for secure thread communication.
 *
 ******/

#ifndef __THREAD_H__
#define __THREAD_H__

#include "globals.h"

/****d* Thread/OPEN_STACK
 * NAME
 *   OPEN_STACK
 * FUNCTION
 *   Lock a mutex for a specific thread
 * SOURCE
 */
#define OPEN_STACK(StackNr) pthread_mutex_lock(&mutex[StackNr]);
/******/

/****d* Thread/POP_STACK
 * NAME
 *   POP_STACK
 * FUNCTION
 *   Returns a pointer of a specific type to the newest value from a stack  
 * SOURCE
 */
#define POP_STACK(StackNr, type) ((type*)stack_head(StackNr)->val);stack_drop(StackNr);
/******/

/****d* Thread/CLOSE_STACK
 * NAME
 *   CLOSE_STACK
 * FUNCTION
 *   Unlock a mutex for a specific thread
 * SOURCE
 */
#define CLOSE_STACK(StackNr) pthread_mutex_unlock(&mutex[StackNr]);
/******/


#define NUMTHREADS 5

pthread_t thread[NUMTHREADS];
stack *thread_stack[NUMTHREADS];
pthread_mutex_t mutex[NUMTHREADS];


extern void stack_push(unsigned int thread_id, unsigned char id, void *val, unsigned int val_size);
extern stack* stack_drop(unsigned int thread_id);
extern stack* stack_head(unsigned int thread_id);


#endif
