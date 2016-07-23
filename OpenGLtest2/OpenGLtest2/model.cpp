
#include "model.h"


Model::Model(TBuffer<float> *vs, TBuffer<int> *fs,int dim)
{
	int bufSize = fs->bufSize();
	vertices.resize(bufSize * dim);//���_�C���f�b�N�X�̐�*���_���W�̎�����

	for (int i = 0; i < bufSize; ++i) {
		//���_�C���f�b�N�X�����o��(�C���f�b�N�X�l��1�`�Ȃ̂Ń}�C�i�X1����)
		int index = fs->get(i) - 1;
		for (int j = 0; j < dim; ++j) {
			//�C���f�b�N�X���Ƃɒ��_���W(x,y,z)�����Ɏ��o��
			vertices[i * dim + j] = vs->get(index * dim + j);
		}
	}
}
