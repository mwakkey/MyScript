
#include "glVertexArray.h"


#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL+(bytes))

void GLVertexArray::glBufferDraw(GLenum usage, const Model& m)
{

	//�o�b�t�@�I�u�W�F�N�g�̍쐬
	glGenBuffers(1, &vBuffer);

	//��ڂ̃o�b�t�@�I�u�W�F�N�g�ɒ��_�f�[�^�z���]������
	//�o�b�t�@�̃o�C���h
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer);
	//���_���̃A�b�v���[�h
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.myVertex), &(m.myVertex[0]), usage);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//�C���f�b�N�X�o�b�t�@�����l��
	glGenBuffers(1, &iBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m.indices), &(m.indices[0]), usage);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	//�C���f�b�N�X�o�b�t�@�\���Z�b�g
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer);
	//���_�o�b�t�@���Z�b�g
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	
	GLsizei stride = sizeof(MyVertex);//���_�f�[�^��(���̒��_�f�[�^�܂ł̋���)
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer);
	glVertexPointer(3, GL_FLOAT, stride, NULL);
	glNormalPointer(GL_FLOAT, stride, BUFFER_OFFSET(sizeof(var3D<float, float, float>)));
	glTexCoordPointer(2, GL_FLOAT, stride, BUFFER_OFFSET(sizeof(var3D<float, float, float>) * 2));


	//�`��
	glDrawElements(GL_TRIANGLES, m.indices.size(), GL_UNSIGNED_INT, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}
