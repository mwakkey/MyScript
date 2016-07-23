
#include "model.h"


Model::Model(TBuffer<float> *vs, TBuffer<int> *fs,int dim)
{
	int bufSize = fs->bufSize();
	vertices.resize(bufSize * dim);//頂点インデックスの数*頂点座標の次元数

	for (int i = 0; i < bufSize; ++i) {
		//頂点インデックスを取り出す(インデックス値は1～なのでマイナス1する)
		int index = fs->get(i) - 1;
		for (int j = 0; j < dim; ++j) {
			//インデックスごとに頂点座標(x,y,z)を順に取り出す
			vertices[i * dim + j] = vs->get(index * dim + j);
		}
	}
}
