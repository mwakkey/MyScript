
#include "obj.h"
#include <fstream>
#include <stdio.h>

void Obj::loadObj(const std::string fileName,Model* m)
{
	std::ifstream ifs(fileName);
	std::string line;
	TBuffer<float> *vs = new TBuffer<float>;
	TBuffer<int> *fs = new TBuffer<int>;
	TBuffer<float> *vns = new TBuffer<float>;
	TBuffer<int> *uvs = new TBuffer<int>;

	while (std::getline(ifs, line)) {
		if (line[0] == 'v'&&line[1] == ' ') {
			readVertices(line, vs);
		}
		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ') {
			readNormals(line, vns);
		}
		else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ') {
			readUVs(line, uvs);
		}
		else if (line[0] == 'f'&&line[1] == ' ') {
			readIndices(line, fs);
		}
	}
	ifs.close();

	m = new Model(vs, fs);


	delete(vs);
	delete(fs);
}

void Obj::readVertices(const std::string line, TBuffer<float> *vs)
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


void Obj::readIndices(const std::string line, TBuffer<int> *fs)
{
	int v1, v2, v3;
	int t1, t2, t3;
	int n1, n2, n3;
	int count;

	//f 1/3/2 2/2/1 3/3/1@‚Ì‚æ‚¤‚É‹Lq‚³‚ê‚Ä‚¢‚é
	count = sscanf_s(line.c_str(),
				   "%*s %d%*c%d%*c%d "
				   "%d%*c%d%*c%d "
				   "%d%*c%d%*c%d",
				   &v1, &t1, &n1, &v2, &t2, &n2, &v3, &t3, &n3);

	if (count == 9) {
		fs->add(v1);
		fs->add(t1);
		fs->add(n1);
		fs->add(v2);
		fs->add(t2);
		fs->add(n2);
		fs->add(v3);
		fs->add(t3);
		fs->add(n3);
	}

}

void Obj::readNormals(const std::string line, TBuffer<float> *vns)
{
	float x, y, z;
	int count;
	count = sscanf_s(line.c_str(), "%*s%f%f%f", &x, &y, &z);

	if (count == 3) {
		vns->add(x);
		vns->add(y);
		vns->add(z);
	}
}

void Obj::readUVs(const std::string line, TBuffer<int> *uvs)
{
	float u, v;
	int count;
	count = sscanf_s(line.c_str(), "%*s%f%f", &u, &v);

	if (count == 2) {
		uvs->add(u);
		uvs->add(v);
	}
}
