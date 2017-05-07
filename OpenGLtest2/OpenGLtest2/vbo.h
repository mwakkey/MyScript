#pragma once
#include "vertex.h"

namespace GL {
	class VBO {
	private:
		unsigned int vrtID;//Vertex�z��̓o�^ID(GLuint)
		unsigned int idxID;//Vertex�̃C���f�b�N�X��\���z��̓o�^ID(GLuint)
		unsigned int texID;//�e�N�X�`���̓o�^ID(GLuint)

		int dim;//���_�f�[�^�̂����A���_���W�̎�����
		int stride;//���_�f�[�^�̊Ԋu
		int vrtLength;//���_�f�[�^�̒���
		VBO(){}
	public:
		VBO(const float[][2], const float[][2], const int[], const unsigned int);
		VBO(const float[][3], const float[][2], const int[], const unsigned int);
		~VBO();

		void draw();
		void modify(const float[][2]);
		void modify(const float[][3]);

	};
}