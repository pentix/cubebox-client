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

#include "thread.h"

/****f* Thread/Stack_push
 * NAME
 *   stack_push
 * FUNCTION
 *   This pushs something in a stack, so other treads can work
 *   task for task down.
 * INPUTS
 *   * thread_id -- To which tread the task belongs
 *   * id -- The id (identifies the task)
 *   * val -- pointer to additional informations
 *   * val_size -- size of the memory segment 'val' points to
 * SOURCE
 */
void stack_push(unsigned int thread_id, unsigned char id, void *val, unsigned int val_size){
	void *HEAD;

	HEAD=thread_stack[thread_id];
	falloc(thread_stack[thread_id], sizeof(stack));
	thread_stack[thread_id]->next=HEAD;
	thread_stack[thread_id]->id=id;
	
	if(val != NULL && val_size != 0){
		falloc(thread_stack[thread_id]->val,val_size);
		memcpy(thread_stack[thread_id]->val, val, val_size);
	}
}
/******/


/****f* Thread/Stack_head
 * NAME
 *   stack_head
 * FUNCTION
 *   Returns the latest element in the stack
 * INPUTS
 *   thread_id -- The id of the thread of which the latest element should be returned
 * RESULT
 *   A pointer to the latest element
 * SOURCE
 */
stack* stack_head(unsigned int thread_id ){
	return 	thread_stack[thread_id];
}
/******/


/****f* Thread/Stack_drop
 * NAME
 *   stack_drop
 * FUNCTION
 *   Returns the next element in the stack and removes it from the stack
 * INPUTS
 *   thread_id -- The id of the thread of which the next element should be returned
 * RESULT
 *   A pointer to the next element
 * SOURCE
 */
stack* stack_drop(unsigned int thread_id ){
	stack *HEAD;
	if(thread_stack[thread_id]->id == 0xFF) return NULL;
	HEAD=thread_stack[thread_id]->next;
	if(HEAD==NULL) return NULL;
	free(thread_stack[thread_id]);
	thread_stack[thread_id]=HEAD;
	return HEAD;
}
/******/
