#pragma once
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>
#include <vector>
#include "model.h"


//VBO+VAOを行うクラス
class GLVertexArray
{
private:
	std::vector<GLuint> vaoId;
	std::vector<GLuint> vboId;
	std::vector<GLuint> iboId;

public:
	GLVertexArray(int vaoSize, int vboSize, int iboSize);

	//usage -> GL_STATIC_DRAW |GL_DYNAMIC_DRAW |GL_STREAM_DRAW
	//VBOを作成、VAOでカプセル化する
	void buildVBO(GLenum usage, const std::vector<Model>& mlist);

	//描画
	void draw(int arraySize);
};