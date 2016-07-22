
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
	vertices.resize(bufSize*3);//���_�C���f�b�N�X�̐�*���_���W�̎�����

	for (int i = 0; i < bufSize; ++i) {
		//���_�C���f�b�N�X�����o��(�C���f�b�N�X�l��1�`�Ȃ̂Ń}�C�i�X1����)
		int index = fs->get(i) - 1;
		for (int j = 0; j < 3; ++j) {
			//�C���f�b�N�X���Ƃɒ��_���W(x,y,z)�����Ɏ��o��
			vertices[i * 3 + j] = vs->get(index * 3 + j);
		}
	}
}
*/