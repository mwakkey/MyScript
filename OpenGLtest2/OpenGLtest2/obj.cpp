
#include "obj.h"
#include <fstream>
#include <stdio.h>

Model* Obj::loadObj2D(const std::string fileName)
{
	std::ifstream ifs(fileName);
	std::string line;
	TBuffer<float> *vs = new TBuffer<float>;
	TBuffer<int> *fs = new TBuffer<int>;

	while (std::getline(ifs, line)) {
		if (line[0] == 'v'&&line[1] == ' ') {
			readVertices2D(line, vs);
		}
		else if (line[0] == 'f'&&line[1] == ' ') {
			readIndices(line, fs, 3);//四角形なら第三引数を4にする
		}
	}
	ifs.close();

	Model *m = new Model(vs, fs, 2);


	delete(vs);
	delete(fs);

	return m;
}
Model* Obj::loadObj3D(const std::string fileName)
{
	std::ifstream ifs(fileName);
	std::string line;
	TBuffer<float> *vs = new TBuffer<float>;
	TBuffer<int> *fs = new TBuffer<int>;

	while (std::getline(ifs, line)) {
		if (line[0] == 'v'&&line[1] == ' ') {
			readVertices3D(line, vs);
		}
		else if (line[0] == 'f'&&line[1] == ' ') {
			readIndices(line, fs, 3);//四角形なら第三引数を4にする
		}
	}
	ifs.close();

	Model *m = new Model(vs, fs, 3);


	delete(vs);
	delete(fs);

	return m;
}

void Obj::readVertices3D(const std::string line, TBuffer<float> *vs)
{
	std::vector<float> verts(3);
	int count;

	count = sscanf_s(line.c_str(), "%*s%f%f%f", &verts[0], &verts[1], &verts[2]);

	if (count == 3) {
		for (int i = 0; i < 3; ++i) {
			vs->add(verts[i]);
		}

	}

}
void Obj::readVertices2D(const std::string line, TBuffer<float> *vs)
{
	std::vector<float> verts(2);
	int count;

	count = sscanf_s(line.c_str(), "%*s%f%f", &verts[0], &verts[1]);

	if (count == 2) {
		for (int i = 0; i < 2; ++i) {
			vs->add(verts[i]);
		}

	}

}


void Obj::readIndices(const std::string line, TBuffer<int> *fs, int figure)
{
	std::vector<int> indices(figure);
	int count;
	if (figure == 3) {
		count = sscanf_s(line.c_str(), "%*s%d%d%d", &indices[0], &indices[1], &indices[2]);
	}
	else if (figure == 4) {
		count = sscanf_s(line.c_str(), "%*s%d%d%d%d", &indices[0], &indices[1], &indices[2], &indices[3]);
	}

	if (count == figure) {
		for (int i = 0; i < figure; ++i) {
			fs->add(indices[i]);
		}
	}

}