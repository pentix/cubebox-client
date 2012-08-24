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


/****h* Client/Glelements
 * NAME
 *   Glelements
 * FUNCTION
 *   Graphics functions
 *
 ******/

/****f* Glelements/draw_block
 * NAME
 *   draw_block
 * FUNCTION
 *   Draw a block into OpenGL's memory
 * OPTIONS
 *   x -- x coordinate
 *   y -- y coordinate
 *   z -- z coordinate
 *   texture -- BitMap-struct pointer
 * SOURCE
 */
void draw_block(float x, float y, float z, BitMap* texture){

	glBindTexture(GL_TEXTURE_2D, BlockTextures[texture][0][0]);
	
	glBegin(GL_QUADS);

	// Back Face
	glTexCoord2f( 0.0f, 1.0f ); glVertex3f(x+0.0f, y+0.0f, z+1.0f);
	glTexCoord2f( 1.0f, 1.0f ); glVertex3f(x+1.0f, y+0.0f, z+1.0f);
	glTexCoord2f( 1.0f, 0.0f ); glVertex3f(x+1.0f, y+1.0f, z+1.0f);
	glTexCoord2f( 0.0f, 0.0f ); glVertex3f(x+0.0f, y+1.0f, z+1.0f);

	// Front Face
	glTexCoord2f( 1.0f, 1.0f ); glVertex3f(x+0.0f, y+0.0f, z+0.0f);
	glTexCoord2f( 1.0f, 0.0f ); glVertex3f(x+0.0f, y+1.0f, z+0.0f);
	glTexCoord2f( 0.0f, 0.0f ); glVertex3f(x+1.0f, y+1.0f, z+0.0f);
	glTexCoord2f( 0.0f, 1.0f ); glVertex3f(x+1.0f, y+0.0f, z+0.0f);

	// Top Face
	glTexCoord2f( 0.0f, 0.0f ); glVertex3f(x+0.0f, y+1.0f, z+0.0f);
	glTexCoord2f( 0.0f, 1.0f ); glVertex3f(x+0.0f, y+1.0f, z+1.0f);
	glTexCoord2f( 1.0f, 1.0f ); glVertex3f(x+1.0f, y+1.0f, z+1.0f);
	glTexCoord2f( 1.0f, 0.0f ); glVertex3f(x+1.0f, y+1.0f, z+0.0f);

	// Bottom Face
	glTexCoord2f( 0.0f, 0.0f ); glVertex3f(x+0.0f, y+0.0f, z+0.0f);
	glTexCoord2f( 1.0f, 0.0f ); glVertex3f(x+1.0f, y+0.0f, z+0.0f);
	glTexCoord2f( 1.0f, 1.0f ); glVertex3f(x+1.0f, y+0.0f, z+1.0f);
	glTexCoord2f( 0.0f, 1.0f ); glVertex3f(x+0.0f, y+0.0f, z+1.0f);

	// Right face
	glTexCoord2f( 1.0f, 1.0f ); glVertex3f(x+1.0f, y+0.0f, z+0.0f);
	glTexCoord2f( 1.0f, 0.0f ); glVertex3f(x+1.0f, y+1.0f, z+0.0f);
	glTexCoord2f( 0.0f, 0.0f ); glVertex3f(x+1.0f, y+1.0f, z+1.0f);
	glTexCoord2f( 0.0f, 1.0f ); glVertex3f(x+1.0f, y+0.0f, z+1.0f);

	// Left Face
	glTexCoord2f( 0.0f, 1.0f ); glVertex3f(x+0.0f, y+0.0f, z+0.0f);
	glTexCoord2f( 1.0f, 1.0f ); glVertex3f(x+0.0f, y+0.0f, z+1.0f);
	glTexCoord2f( 1.0f, 0.0f ); glVertex3f(x+0.0f, y+1.0f, z+1.0f);
	glTexCoord2f( 0.0f, 0.0f ); glVertex3f(x+0.0f, y+1.0f, z+0.0f);

	glEnd();

}
/******/
