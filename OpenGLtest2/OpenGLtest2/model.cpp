
#include "model.h"


Model::Model(TBuffer<var3D<float, float, float>> *vs, TBuffer<var3D<int, int, int>> *fs, TBuffer<var3D<float, float, float>> *vns, TBuffer<var2D<float, float>> *uvs)
{
	int bufSize = fs->bufSize();
	myVertex.resize(bufSize);
	indices.resize(bufSize);

	for (int i = 0; i < bufSize; ++i) {
		//fsはvtnを要素に持つvector
		//頂点インデックスを取り出す(インデックス値は1～なのでマイナス1する)
		var3D<int,int,int> index = fs->get(i);
		indices[i] = index.x;
		index.x--;//vのインデックス
		index.y--;//tのインデックス
		index.z--;//nのインデックス

		myVertex[i].vertices=vs->get(index.x);
		myVertex[i].textures=uvs->get(index.y);
		myVertex[i].normals=vns->get(index.z);

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