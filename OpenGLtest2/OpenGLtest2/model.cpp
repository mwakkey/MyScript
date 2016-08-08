
#include "model.h"


Model::Model(TBuffer<float> *vs, TBuffer<int> *fs, TBuffer<float> *vns, TBuffer<int> *uvs)
{
	int bufSize = fs->bufSize();
	vertices.resize(bufSize * 3);//頂点インデックスの数*頂点座標の次元数(= 3)

	for (int i = 0; i < bufSize; ++i) {
		//頂点インデックスを取り出す(インデックス値は1～なのでマイナス1する)
		int index = fs->get(i) - 1;
		if (i % 3 == 0) {
			for (int j = 0; j < 3; ++j) {
				//インデックスごとに頂点座標(x,y,z)を順に取り出す
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