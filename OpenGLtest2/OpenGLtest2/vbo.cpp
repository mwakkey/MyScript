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
	//�C���f�b�N�X�o�b�t�@���Z�b�g����
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxID);

	//���_�o�b�t�@���e�����ɂ��Đݒ肵����ŃZ�b�g����
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, vrtID);
	glVertexPointer(dim, GL_FLOAT, stride, NULL);//stride(���_�f�[�^�̊Ԋu),�I�t�Z�b�g�͍ŏ��Ȃ̂�0
	glTexCoordPointer(2, GL_FLOAT, stride, BUFFER_OFFSET(sizeof(float) * dim));//�I�t�Z�b�g��vertices�̃T�C�Y��

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
