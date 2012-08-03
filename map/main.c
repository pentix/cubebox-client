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


#include "main.h"

void fill_chunk(float x, float y, float z){
	long lx, ly, lz;
	long *worldptr;
	
	pthread_mutex_lock(&mutex[0]);
		for(lx=x; lx<x+16; lx++){
			for(ly=y; ly<y+16; ly++){
				for(lz=z; lz<z+512; lz++){
					worldptr = (long *)malloc(4*sizeof(long));
					
					// Write a stone
					world[lx][ly][lz] = 1;
					worldptr[0] = lx;
					worldptr[1] = ly;
					worldptr[2] = lz;
					worldptr[3] = 1; // Stones
					
					// Push it
					stack_push(0, 11, (void *)worldptr, 4*sizeof(long));
				}
			}
		}
	pthread_mutex_unlock(&mutex[0]);
}

void generate_map(void){

}

void map(stack* stackptr){
	
}
