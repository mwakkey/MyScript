
#include "glVertexArray.h"

#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL+(bytes))


GLVertexArray::GLVertexArray(int vaoSize, int vboSize, int iboSize) {
	vaoId.resize(vaoSize);
	vboId.resize(vboSize);
	iboId.resize(iboSize);
}

void GLVertexArray::draw(int arraySize) {
	glBindVertexArray(vaoId[0]);
	glDrawArrays(GL_QUADS, 0, arraySize);//���_�z��(�x�N�g��)�̃T�C�Y=���_���W�������邩
	glBindVertexArray(0);
}

void GLVertexArray::buildVBO(GLenum usage, const std::vector<Model>& mlist) {
	glGenVertexArrays(2, &(vaoId[0]));//VAO2�쐬
	glGenBuffers(2, &(vboId[0]));//VBO2�쐬
	glGenBuffers(2, &(iboId[0]));//IBO2�쐬

	for (int i = 0; i < 2; ++i) {
		glBindVertexArray(vaoId[i]);//VAO�؂�ւ�

		//------VBOi��----------//
		glBindBuffer(GL_ARRAY_BUFFER, vboId[i]);//�o�C���h
												  //��ڂ̃o�b�t�@�I�u�W�F�N�g�ɒ��_�f�[�^�z���]������
												  //�o�b�t�@�̃o�C���h
		glBindBuffer(GL_ARRAY_BUFFER, vboId[i]);
		//���_���̃A�b�v���[�h
		glBufferData(GL_ARRAY_BUFFER, sizeof(mlist[i].myVertex), &(mlist[i].myVertex[0]), usage);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//�C���f�b�N�X�o�b�t�@�����l��
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId[i]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mlist[i].indices), &(mlist[i].indices[0]), usage);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


		//�C���f�b�N�X�o�b�t�@�\���Z�b�g
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId[i]);
		//���_�o�b�t�@���Z�b�g
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);


		GLsizei stride = sizeof(MyVertex);//���_�f�[�^��(���̒��_�f�[�^�܂ł̋���)
		glBindBuffer(GL_ARRAY_BUFFER, vboId[i]);
		glVertexPointer(3, GL_FLOAT, stride, NULL);
		glNormalPointer(GL_FLOAT, stride, BUFFER_OFFSET(sizeof(var3D<float, float, float>)));
		glTexCoordPointer(2, GL_FLOAT, stride, BUFFER_OFFSET(sizeof(var3D<float, float, float>) * 2));
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);//�A���o�C���h
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glBindVertexArray(0);

}

