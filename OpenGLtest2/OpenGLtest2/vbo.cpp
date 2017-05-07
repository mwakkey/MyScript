#include <GL/glew.h>
#include <GL/freeglut.h>
#include "vbo.h"

#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL + (bytes))

using namespace GL;

VBO::VBO(const float vertices[][2], const float textures[][2], const int indices[], const unsigned int textureID)
	:texID(textureID), dim(2), stride(sizeof(VERTEX::Vertex2D)), vrtLength(sizeof(vertices) / sizeof(vertices[0])) {

	VERTEX::Vertex2D* vertex = new VERTEX::Vertex2D[vrtLength];
	VERTEX::vertexArray2D(vertex, vertices, textures);
	
	glGenBuffers(1, &vrtID);
	glBindBuffer(GL_ARRAY_BUFFER, vrtID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VERTEX::Vertex2D)*vrtLength, vertex, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &idxID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	delete[] vertex;

}
VBO::VBO(const float vertices[][3], const float textures[][2], const int indices[], const unsigned int textureID)
	:texID(textureID), dim(3), stride(sizeof(VERTEX::Vertex3D)), vrtLength(sizeof(vertices) / sizeof(vertices[0])) {

	VERTEX::Vertex3D* vertex = new VERTEX::Vertex3D[vrtLength];
	VERTEX::vertexArray3D(vertex, vertices, textures);

	glGenBuffers(1, &vrtID);
	glBindBuffer(GL_ARRAY_BUFFER, vrtID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VERTEX::Vertex3D)*vrtLength, vertex, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &idxID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	delete[] vertex;
}

VBO::~VBO() {
	glDeleteBuffers(1, &vrtID);
	glDeleteBuffers(1, &idxID);
}


void VBO::draw() {

	//インデックスバッファをセットする
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxID);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texID); //描画するテクスチャ(のID)を指定

	//頂点バッファを各属性について設定した上でセットする
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, vrtID);
	glVertexPointer(dim, GL_FLOAT, stride, NULL);//stride(頂点データの間隔),オフセットは最初なので0
	glTexCoordPointer(2, GL_FLOAT, stride, BUFFER_OFFSET(sizeof(float) * dim));//オフセットはverticesのサイズ分

	glDrawElements(GL_TRIANGLES, vrtLength, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void VBO::modify(const float newVertices[][2]) {
	glBindBuffer(GL_ARRAY_BUFFER, vrtID);
	VERTEX::Vertex2D* tmp = reinterpret_cast<VERTEX::Vertex2D*>(glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE));
	VERTEX::vertexArray2D(tmp, newVertices);

	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::modify(const float newVertices[][3]) {
	glBindBuffer(GL_ARRAY_BUFFER, vrtID);
	VERTEX::Vertex3D* tmp = reinterpret_cast<VERTEX::Vertex3D*>(glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE));
	VERTEX::vertexArray3D(tmp, newVertices);

	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}