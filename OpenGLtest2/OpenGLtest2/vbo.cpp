#include <GL/glew.h>
#include <GL/freeglut.h>
#include "vbo.h"

#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL + (bytes))

using namespace GL;

VBO::VBO(const VERTEX::Vertex vertex[],int vertSize, const int indices[],int dimension)
	:dim(dimension),stride(sizeof(vertex[0])),vrtSize(vertSize) {

	glGenBuffers(1, &vrtID);
	glBindBuffer(GL_ARRAY_BUFFER, vrtID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &idxID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

VBO::~VBO() {
	glDeleteBuffers(1, &vrtID);
	glDeleteBuffers(1, &idxID);
}


void VBO::draw() {
	//インデックスバッファをセットする
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxID);

	//頂点バッファを各属性について設定した上でセットする
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, vrtID);
	glVertexPointer(dim, GL_FLOAT, stride, NULL);//stride(頂点データの間隔),オフセットは最初なので0
	glTexCoordPointer(2, GL_FLOAT, stride, BUFFER_OFFSET(sizeof(float) * dim));//オフセットはverticesのサイズ分

	glDrawElements(GL_TRIANGLES, vrtSize, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void VBO::modify(VERTEX::Vertex newVertices[]) {
	glBindBuffer(GL_ARRAY_BUFFER, vrtID);
	VERTEX::Vertex* tmp = reinterpret_cast<VERTEX::Vertex*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	tmp = newVertices;

	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
