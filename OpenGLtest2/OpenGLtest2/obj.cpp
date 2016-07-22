
#include "obj.h"
#include <fstream>
#include <stdio.h>


Model* Obj::loadObj(const std::string fileName)
{
	std::ifstream ifs(fileName);
	std::string line;
	TBuffer<float> *vs = new TBuffer<float>;
	TBuffer<int> *fs = new TBuffer<int>;

	while (std::getline(ifs, line)) {
		if (line[0] == 'v'&&line[1] == ' ') {
			readVertices(line, vs);
		}
		else if (line[0] == 'f'&&line[1] == ' ') {
			readIndices(line, fs);
		}
	}
	ifs.close();

	Model *m = new Model(vs,fs);


	delete(vs);
	delete(fs);

	return m;
}

void Obj::readVertices(const std::string line, TBuffer<float> *vs)
{
	float verts[3];
	int count;

	count = sscanf_s(line.c_str(), "%*s%f%f%f", &verts[0], &verts[1], &verts[2]);

	if (count == 3) {
		for (int i = 0; i < 3; ++i) {
			vs->add(verts[i]);
		}
		
	}

}

void Obj::readIndices(const std::string line, TBuffer<int> *fs)
{
	int indices[3];
	int count;

	count = sscanf_s(line.c_str(), "%*s%d%d%d", &indices[0], &indices[1], &indices[2]);

	if (count == 3) {
		for (int i = 0; i < 3; ++i) {
			fs->add(indices[i]);
		}
	}

}

/*
Model::Model(TBuffer<float> *vs,TBuffer<int> *fs)
{
	int bufSize = fs->bufSize();
	vertices.resize(bufSize*3);//頂点インデックスの数*頂点座標の次元数

	for (int i = 0; i < bufSize; ++i) {
		//頂点インデックスを取り出す(インデックス値は1～なのでマイナス1する)
		int index = fs->get(i) - 1;
		for (int j = 0; j < 3; ++j) {
			//インデックスごとに頂点座標(x,y,z)を順に取り出す
			vertices[i * 3 + j] = vs->get(index * 3 + j);
		}
	}
}
*/