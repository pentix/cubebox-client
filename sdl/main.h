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

#ifndef __SDL_MAIN_H__
#define __SDL_MAIN_H__

enum {
	SND_JUMP=0,
	NUMBER_OF_SOUNDS
};

// Sounds
Mix_Chunk *sounds[NUMBER_OF_SOUNDS];

extern void sdl(stack* stackptr);
extern void sound(stack* stackptr);
extern void play_sound(unsigned char id);

#define NUMBER_OF_TEXTURES 256
GLuint textures[1];
GLuint displaylists;

float xrot, zrot; 

#endif
