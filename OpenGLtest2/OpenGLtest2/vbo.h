#pragma once
#include "vertex.h"

namespace GL {
	class VBO {
	private:
		unsigned int vrtID;//GLuint
		unsigned int idxID;//GLuint

		int dim;//���_�f�[�^�̂����A���_���W
		int stride;//���_�f�[�^�̊Ԋu
		int vrtSize;//���_�f�[�^�̒���
		VBO() {}
	public:
		VBO(const VERTEX::Vertex[], int, const int[], int);
		~VBO();
		void draw();
		void modify(VERTEX::Vertex[]);
	};
}