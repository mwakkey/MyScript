#pragma once
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>
#include "model.h"


class GLVertexArray
{
private:
	GLuint vBuffer;
	GLuint iBuffer;

public:
	void glBufferDraw(GLenum usage, const Model& m);

};