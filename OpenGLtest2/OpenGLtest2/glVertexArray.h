#pragma once
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>


class GLVertexArray
{
private:
	GLuint positionBuffer;
	GLuint vertexArray;
	const GLuint positionLocation = 0;
	const GLuint positionBindIndex = 0;

	void glBuffer();
public:
	void glDraw();


};