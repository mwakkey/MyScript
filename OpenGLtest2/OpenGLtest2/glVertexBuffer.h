#pragma once
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>
#include "model.h"


//VBO���s���N���X
class GLVertexBuffer
{
private:
	GLuint vBuffer;
	GLuint iBuffer;

	//usage -> GL_STATIC_DRAW |GL_DYNAMIC_DRAW |GL_STREAM_DRAW
	void glBufferDraw(GLenum usage, const Model& m);//���f��1�̂�`�悷��

public:
	std::vector<Model> mlist;
	//usage -> GL_STATIC_DRAW |GL_DYNAMIC_DRAW |GL_STREAM_DRAW
	void glVBODraw(GLenum usage);

};