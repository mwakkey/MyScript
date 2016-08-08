#pragma once
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>


class GLVertexArray
{
private:
	std::vector<GLuint> vBuffer;
	
	void glVertexBuffer(GLenum usage,const Model& m);
	void glIndexBuffer();
public:
	void glDraw();


};