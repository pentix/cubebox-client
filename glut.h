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


#ifndef __gl_MAIN_H__
#define __gl_MAIN_H__

#include "globals.h"

#define GRAPHIC_FPS 20

extern void reshape(int width,int height);
extern void keyboard(unsigned char key, int x, int y);
extern void keyboard_up(unsigned char key, int x, int y);
extern void display();
extern void mouse();


//~ 
//~ enum {
	//~ SND_JUMP=0,
	//~ NUMBER_OF_SOUNDS
//~ };
//~ 
//~ // Sounds
//~ char *sounds[NUMBER_OF_SOUNDS];
//~ 
//~ extern void gl(stack* stackptr);
//~ extern void sound(stack* stackptr);
//~ extern void play_sound(unsigned char id);
//~ extern void draw_cube(float x, float y, float z, int type);
//~ extern int LoadGLTextures();
//~ 
//~ #define NUMBER_OF_TEXTURES 256
//~ unsigned int textures[1];
//~ unsigned int displaylists;
//~ 
//~ float xrot, zrot;
//~ unsigned int ground;
//~ 
#endif
