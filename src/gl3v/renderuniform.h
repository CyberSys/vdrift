#ifndef _RENDERUNIFORM
#define _RENDERUNIFORM

#include "renderuniformentry.h"
#include "renderuniformvector.h"

/// The bare minimum required to update uniforms
struct RenderUniform
{
	GLuint location;
	RenderUniformVector <float> data;
	
	RenderUniform() {}
	RenderUniform(GLint loc, const RenderUniformEntry & entry) : location(loc), data(entry.data) {}
	RenderUniform(GLint loc, const std::vector <float> & newdata) : location(loc), data(newdata) {}
};

#endif
