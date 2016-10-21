#ifndef _CREATE_SHADER_H
#define _CREATE_SHADER_H
#include "Utilities\glew\glew.h"


char* file_read(const char* filename);
void print_log(GLuint object);
GLuint create_shader(const char* filename, GLenum type);
#endif