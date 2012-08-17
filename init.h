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


#ifndef __INIT_H__
#define __INIT_H__

/****h* Client/Init_h
 * NAME
 *   Init
 * FUNCTION
 *   Thread initialition and glut setup.
 *
 ******/
 
#include "globals.h"

extern void init(void);
extern void halt(void);

extern unsigned long getUsec(void);

/****d* Init/TimedCallback
 * NAME
 *   TimedCallback
 * FUNCTION
 *   Kind of a timer. Calls the function in a specified interval.
 *   The function gets at least one time called.
 * INPUTS
 *   func -- function pointer to the timer function
 *   CPS -- calls per second
 *   BrkCond -- break condition
 * SOURCE
 */
#define TimedCallback(func, CPS, BrkCond) \
	do{ \
		unsigned long cb_time=getUsec(); \
		func(); \
		usleep((int)((1000000.0f/(((float)CPS)))-(getUsec()-cb_time)));\
		/*printf("Refresh time %lu-%lu=%lu usec\n",getUsec(), cb_time, getUsec()-cb_time); */ \
	}while(!BrkCond);
#endif
/******/
