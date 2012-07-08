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
#include "../../globals.h"

void stack_push(unsigned int thread_id, unsigned char id, void *val, unsigned int val_size){
	void *HEAD;


	pthread_mutex_lock(&mutex[thread_id]);
		HEAD=thread_stack[thread_id];
		falloc(thread_stack[thread_id], sizeof(stack));
		thread_stack[thread_id]->next=HEAD;
		thread_stack[thread_id]->id=id;
		
		if(val != NULL && val_size != 0){
			falloc(thread_stack[thread_id]->val,val_size);
			memcpy(thread_stack[thread_id]->val, val, val_size);
		}
	pthread_mutex_unlock(&mutex[thread_id]);
}

stack* stack_head(unsigned int thread_id ){
	return 	thread_stack[thread_id];
}


stack* stack_drop(unsigned int thread_id ){
	stack *HEAD;
	if(thread_stack[thread_id]->id == 0xFF) return NULL;
	HEAD=thread_stack[thread_id]->next;
	free(thread_stack[thread_id]);
	thread_stack[thread_id]=HEAD;
	return HEAD;
}

