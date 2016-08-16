
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

void Model::posInit(float pX, float pY, float pZ) {
	for (auto mv : myVertex) {
		mv.vertices.x += pX;
		mv.vertices.y += pY;
		mv.vertices.z += pZ;
	}
}