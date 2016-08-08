
#include "glVertexArray.h"
#include "obj.h"

void GLVertexArray::glVertexBuffer(GLenum usage, const Model& m)
{

	//�o�b�t�@�I�u�W�F�N�g�̍쐬
	glGenBuffers(vBuffer.size(), &vBuffer[0]);
	
	//��ڂ̃o�b�t�@�I�u�W�F�N�g�ɒ��_�f�[�^�z���]������
	//�o�b�t�@�̃o�C���h
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer[0]);
	//���_���̃A�b�v���[�h
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.vertices), &(m.vertices[0]), usage);
	
	//��ځV�@���f�[�^�z��
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.normal), &(m.normal[0]), usage);

	//�O�ځV�e�N�X�`�����W�z��
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.uvs), &(m.uvs[0]), usage);

	//�l�ځV���_�C���f�b�N�X
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.index), &(m.index[0]), usage);


	//�o�C���h�̉���
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	delete(model);
}

void GLVertexArray::glIndexBuffer()
{
	glGenBuffers(1, &vBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*model->vertices.size(), &(model->vertices[0]), usage);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void GLVertexArray::glDraw()
{
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_POINTS, 0, 1);
}