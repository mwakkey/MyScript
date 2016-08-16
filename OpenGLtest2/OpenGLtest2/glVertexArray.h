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
	std::vector<GLuint> vaoID;
	std::vector<GLuint> vboID;
	std::vector<GLuint> iboID;

public:
	//mSize:モデルの数
	void initGLVertexArray(int mCount);

	//usage -> GL_STATIC_DRAW |GL_DYNAMIC_DRAW |GL_STREAM_DRAW
	//VBOを作成、VAOでカプセル化する
	void buildVBO(GLenum usage, const std::vector<Model*>& mlist, int mCount);

	//modelIDに対応するモデルを描画(indexCount:そのモデルに頂点座標が何個あるかを表す)
	void draw(int modelID,int modelIndexCount);
};