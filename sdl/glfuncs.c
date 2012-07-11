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


#include "../globals.h"
#include "main.h"


int LoadGLTextures(){
	unsigned int i;
	
    SDL_Surface *TextureImage[1]; 

    if((TextureImage[0] = SDL_LoadBMP("media/images/textures/texturemap.bmp"))){
		glGenTextures(1, textures);

		glBindTexture(GL_TEXTURE_2D,textures[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->w,
			TextureImage[0]->h,0,GL_BGR,
			GL_UNSIGNED_BYTE,TextureImage[0]->pixels);

		if(TextureImage[0])
			SDL_FreeSurface(TextureImage[0]);
	}
	

	displaylists = glGenLists(NUMBER_OF_TEXTURES);
	
	for(i=0;i<NUMBER_OF_TEXTURES;i++){
		#ifdef DEBUG
			printf("Binding Texture %i\n", i);
		#endif
		
		glBindTexture(GL_TEXTURE_2D, textures[0]); 

		glNewList(displaylists+i, GL_COMPILE);

		glBegin(GL_QUADS);                                                     
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((-0.5f), (-0.5f), (0.5f));
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((0.5f),  (-0.5f), (0.5f));
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((0.5f),  (0.5f),  (0.5f));
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((-0.5f), (0.5f),  (0.5f));		
																		   
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((-0.5f), (-0.5f), (0.5f));	
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+1.0f/16.0f);
				glVertex3f((-0.5f), (-0.5f), (-0.5f));	
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((-0.5f), (0.5f),  (-0.5f));		
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((-0.5f), (0.5f),  (0.5f));		
																		   
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((-0.5f), (-0.5f), (-0.5f));
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((0.5f),  (-0.5f), (-0.5f));	
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((0.5f),  (0.5f),  (-0.5f));  		
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((-0.5f), (0.5f),  (-0.5f));	
																		   
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((0.5f),  (-0.5f), (0.5f));		
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((0.5f),  (-0.5f), (-0.5f));	
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((0.5f),  (0.5f),  (-0.5f));		
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((0.5f),  (0.5f),  (0.5f));			
																		   
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((-0.5f), (0.5f),  (-0.5f));
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((0.5f),  (0.5f),  (-0.5f));		
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((0.5f),  (0.5f),  (0.5f));  	
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((-0.5f), (0.5f),  (0.5f));	
																		   
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((-0.5f), (-0.5f), (-0.5f));	
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f)+(1.0f/16.0f));
				glVertex3f((0.5f),  (-0.5f), (-0.5f));
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f)+(1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((0.5f),  (-0.5f), (0.5f));  	
			glTexCoord2f(((float)((int)i%16)*1.0f/16.0f), ((float)((int)i/16)*1.0f/16.0f));
				glVertex3f((-0.5f), (-0.5f), (0.5f));		
		glEnd();  
		glEndList();                                                           
	}
	return 1;
}


void draw_cube(float x, float y, float z, int type){
	glRotatef(-xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(-zrot, 0.0f, 0.0f, 1.0f);
		
	glTranslatef(-x, -y, -z);
	glCallList(displaylists+type);
}


