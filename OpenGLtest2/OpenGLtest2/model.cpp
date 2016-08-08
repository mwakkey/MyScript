
#include "model.h"


Model::Model(TBuffer<float> *vs, TBuffer<int> *fs, TBuffer<float> *vns, TBuffer<int> *uvs)
{
	int bufSize = fs->bufSize();
	vertices.resize(bufSize * 3);//���_�C���f�b�N�X�̐�*���_���W�̎�����(= 3)

	for (int i = 0; i < bufSize; ++i) {
		//���_�C���f�b�N�X�����o��(�C���f�b�N�X�l��1�`�Ȃ̂Ń}�C�i�X1����)
		int index = fs->get(i) - 1;
		if (i % 3 == 0) {
			for (int j = 0; j < 3; ++j) {
				//�C���f�b�N�X���Ƃɒ��_���W(x,y,z)�����Ɏ��o��
				vertices[i/3 * 3 + j] = vs->get(index * 3 + j);
			}
		}
		else if(i%3==1){
			for (int j = 0; j < 3; ++j) {
				normal[i / 3 * 3 + j] = vns->get(index * 3 + j);
			}
		}
		else
			for (int j = 0; j < 2; ++j) {
				this->uvs[i / 3 * 2 + j] = uvs->get(index * 3 + j);
			}
	}
}


void Model::initPos(const std::vector<float>& pos) {
	if (pos.size() == 3) {
		position = pos;
	}
}

void Model::moveModel(const std::vector<float>& deltaPos) {
	if (deltaPos.size()==3) {
		for (int j = 0; j < 3; ++j) {
			position[j] += deltaPos[j];
			for (int i = 0; (i*3 + j) < vertices.size(); ++i) {
				vertices[(i*3 + j)] += position[j];
			}
		}

	}
}