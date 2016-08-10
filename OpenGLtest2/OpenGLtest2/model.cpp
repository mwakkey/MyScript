
#include "model.h"


Model::Model(TBuffer<var3D<float, float, float>> *vs, TBuffer<var3D<int, int, int>> *fs, TBuffer<var3D<float, float, float>> *vns, TBuffer<var2D<float, float>> *uvs)
{
	int bufSize = fs->bufSize();

	for (int i = 0; i < bufSize; ++i) {
		//fs��vtn��v�f�Ɏ���vector
		//���_�C���f�b�N�X�����o��(�C���f�b�N�X�l��1�`�Ȃ̂Ń}�C�i�X1����)
		var3D<int,int,int> index = fs->get(i);
		index.x--;//v�̃C���f�b�N�X
		index.y--;//t�̃C���f�b�N�X
		index.z--;//n�̃C���f�b�N�X

		vertices.push_back(vs->get(index.x));
		textures.push_back(uvs->get(index.y));
		normals.push_back(vns->get(index.z));

	}
}

/*
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
*/