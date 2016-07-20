
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

	Model *m = createModel(vs, fs);

	ifs.close();
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

Model* Obj::createModel(TBuffer<float> *vs, TBuffer<int> *fs)
{
	;
}