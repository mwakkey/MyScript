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
	std::vector<GLuint> vaoID;
	std::vector<GLuint> vboID;
	std::vector<GLuint> iboID;

public:
	//mSize:���f���̐�
	void initGLVertexArray(int mCount);

	//usage -> GL_STATIC_DRAW |GL_DYNAMIC_DRAW |GL_STREAM_DRAW
	//VBO���쐬�AVAO�ŃJ�v�Z��������
	void buildVBO(GLenum usage, const std::vector<Model*>& mlist, int mCount);

	//modelID�ɑΉ����郂�f����`��(indexCount:���̃��f���ɒ��_���W�������邩��\��)
	void draw(int modelID,int modelIndexCount);
};