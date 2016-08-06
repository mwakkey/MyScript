
#include "model.h"


Model::Model(TBuffer<float> *vs, TBuffer<int> *fs,int dim)
{
	dimension = dim;
	int bufSize = fs->bufSize();
	vertices.resize(bufSize * dimension);//頂点インデックスの数*頂点座標の次元数

	for (int i = 0; i < bufSize; ++i) {
		//頂点インデックスを取り出す(インデックス値は1～なのでマイナス1する)
		int index = fs->get(i) - 1;
		for (int j = 0; j < dimension; ++j) {
			//インデックスごとに頂点座標(x,y,z)を順に取り出す
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