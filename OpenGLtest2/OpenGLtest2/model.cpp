
#include "model.h"


Model::Model(TBuffer<float> *vs, TBuffer<int> *fs,int dim)
{
	dimension = dim;
	int bufSize = fs->bufSize();
	vertices.resize(bufSize * dimension);//���_�C���f�b�N�X�̐�*���_���W�̎�����

	for (int i = 0; i < bufSize; ++i) {
		//���_�C���f�b�N�X�����o��(�C���f�b�N�X�l��1�`�Ȃ̂Ń}�C�i�X1����)
		int index = fs->get(i) - 1;
		for (int j = 0; j < dimension; ++j) {
			//�C���f�b�N�X���Ƃɒ��_���W(x,y,z)�����Ɏ��o��
			vertices[i * dimension + j] = vs->get(index * dimension + j);
		}
	}
}


void Model::initPos(const std::vector<float>& pos) {
	if (dimension == pos.size()) {
		position = pos;
	}
}

void Model::moveModel(const std::vector<float>& deltaPos) {
	if (dimension == deltaPos.size()) {
		for (int j = 0; j < dimension; ++j) {
			position[j] += deltaPos[j];
			for (int i = 0; (i*dimension + j) < vertices.size(); ++i) {
				vertices[(i*dimension + j)] += position[j];
			}
		}

	}
}