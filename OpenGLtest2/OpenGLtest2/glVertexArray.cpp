
#include "glVertexArray.h"

#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL+(bytes))


void GLVertexArray::initGLVertexArray(int mCount) {
	vaoID.resize(mCount);
	vboID.resize(mCount);
	iboID.resize(mCount);
}

void GLVertexArray::draw(int modelID,int modelIndexCount) {
	glBindVertexArray(vaoID[modelID]);
	glDrawArrays(GL_QUADS, 0, modelIndexCount);//�`�悳���ׂ��C���f�b�N�X�̐�(���_���W(x,y,z)�����g���邩)
	glBindVertexArray(0);
}

void GLVertexArray::buildVBO(GLenum usage, const std::vector<Model*>& mlist,int mCount) {
	glGenVertexArrays(mCount, &(vaoID[0]));//VAO2�쐬
	glGenBuffers(mCount, &(vboID[0]));//VBO2�쐬
	glGenBuffers(mCount, &(iboID[0]));//IBO2�쐬

	for (int i = 0; i < mCount; ++i) {
		glBindVertexArray(vaoID[i]);//VAO�؂�ւ�

		//------VBOi��----------//
		glBindBuffer(GL_ARRAY_BUFFER, vboID[i]);//�o�C���h
												  //��ڂ̃o�b�t�@�I�u�W�F�N�g�ɒ��_�f�[�^�z���]������
												  //�o�b�t�@�̃o�C���h
		glBindBuffer(GL_ARRAY_BUFFER, vboID[i]);
		//���_���̃A�b�v���[�h
		glBufferData(GL_ARRAY_BUFFER, sizeof(mlist[i]->myVertex), &(mlist[i]->myVertex[0]), usage);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//�C���f�b�N�X�o�b�t�@�����l��
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID[i]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mlist[i]->indices), &(mlist[i]->indices[0]), usage);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


		//�C���f�b�N�X�o�b�t�@�\���Z�b�g
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID[i]);
		//���_�o�b�t�@���Z�b�g
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);


		GLsizei stride = sizeof(MyVertex);//���_�f�[�^��(���̒��_�f�[�^�܂ł̋���)
		glBindBuffer(GL_ARRAY_BUFFER, vboID[i]);
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

