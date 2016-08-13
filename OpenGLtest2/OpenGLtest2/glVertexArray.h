#pragma once
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>
#include <vector>
#include "model.h"


//VBO+VAO���s���N���X
class GLVertexArray
{
private:
	std::vector<GLuint> vaoId;
	std::vector<GLuint> vboId;
	std::vector<GLuint> iboId;

public:
	GLVertexArray(int vaoSize, int vboSize, int iboSize);

	//usage -> GL_STATIC_DRAW |GL_DYNAMIC_DRAW |GL_STREAM_DRAW
	//VBO���쐬�AVAO�ŃJ�v�Z��������
	void buildVBO(GLenum usage, const std::vector<Model>& mlist);

	//�`��
	void draw(int arraySize);
};