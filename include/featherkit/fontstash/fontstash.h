//
// Copyright (c) 2011 Andreas Krinke andreas.krinke@gmx.de
// Copyright (c) 2009 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef FONTSTASH_H
#define FONTSTASH_H

#include <vector>

#ifdef __MACOSX__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

void sth_create(int cachew, int cacheh);

int sth_add_font(const char* path);
int sth_add_font_from_memory(unsigned char* buffer);

int  sth_add_bitmap_font(int ascent, int descent, int line_gap);
void sth_add_glyph(int idx, GLuint id, const char* s,  /* @rlyeh: function does not return int */
                  short size, short base, int x, int y, int w, int h,
                  float xoffset, float yoffset, float xadvance);

void sth_begin_draw();
void sth_end_draw(std::vector<float>& vertices, std::vector<float>& texCoords, GLuint& textureId);

void sth_draw_text(int idx, float size,
				   float x, float y, const char* string, float* dx);

void sth_dim_text(int idx, float size, const char* string,
				  float* minx, float* miny, float* maxx, float* maxy);

void sth_vmetrics(int idx, float size,
				  float* ascender, float* descender, float * lineh);

void sth_delete();

#endif // FONTSTASH_H
