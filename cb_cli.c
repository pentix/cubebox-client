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

/****h* Client/CB_CLI
 * NAME
 *   cb_cli
 * FUNCTION
 *   This module provides the main function for the client.
 *
 ******/
 
#ifndef LINUX

int gettimeofday( struct timeval *tv, struct timezone *tz )
{
	LARGE_INTEGER tickPerSecond;
	LARGE_INTEGER tick;
	time_t rawtime;

	time(&rawtime);
	tv->tv_sec = (long)rawtime;

	QueryPerformanceFrequency(&tickPerSecond);
	QueryPerformanceCounter(&tick);

	tv->tv_usec = (tick.QuadPart % tickPerSecond.QuadPart);
	return 0;
}


int usleep(int time){ //doesn't work
	HANDLE hTimer = NULL; 
	LARGE_INTEGER liDueTime; 
	
	liDueTime.QuadPart=time*-1; // negativer Wert= relative Zeit, positiv=absoluter Zeit (siehe SetWaitableTimer) 

	hTimer = CreateWaitableTimer(NULL, TRUE, NULL); 
	SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0);
	WaitForSingleObject(hTimer, INFINITE);
	return 0;
} 

#endif

 

/****f* CB_CLI/Main
 * NAME
 *   main
 * FUNCTION
 *   Program entry point
 * INPUTS
 *   * argc -- number of arguments
 *   * argv -- arguments
 * SOURCE
 */
int main(int argc, char **argv){
	int i;
	atexit(halt);
	init();

	for(i=0;i<NUMTHREADS;i++)
		pthread_join(thread[i], NULL);
	
	return 0;
}
/******/
