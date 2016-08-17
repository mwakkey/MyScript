
#include "objLoader.h"
#include <fstream>
#include <stdio.h>

void ObjLoader::loadObj(const std::string fileName,Model* m)
{
	std::ifstream ifs(fileName);
	std::string line;
	TBuffer<var3D<float, float, float>> *vs = new TBuffer<var3D<float, float, float>>;
	TBuffer<var3D<int, int, int>> *fs = new TBuffer<var3D<int, int, int>>;
	TBuffer<var3D<float, float, float>> *vns = new TBuffer<var3D<float, float, float>>;
	TBuffer<var2D<float, float>> *uvs = new TBuffer<var2D<float, float>>;

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

	m = new Model(vs, fs, vns, uvs);


	delete(vs);
	delete(fs);
	delete(vns);
	delete(uvs);
}

void ObjLoader::readVertices(const std::string line, TBuffer<var3D<float, float, float>> *vs)
{
	var3D<float, float, float> verts;
	int count;

	count = sscanf_s(line.c_str(), "%*s%f%f%f", &(verts.x), &(verts.y), &(verts.z));

	if (count == 3) {
		vs->add(verts);
	}

}


void ObjLoader::readIndices(const std::string line, TBuffer<var3D<int, int, int>> *fs)
{
	var3D<int, int, int> vtn1;
	var3D<int, int, int> vtn2;
	var3D<int, int, int> vtn3;
	int count;

	//f 1/3/2 2/2/1 3/3/1@‚Ì‚æ‚¤‚É‹Lq‚³‚ê‚Ä‚¢‚é
	count = sscanf_s(line.c_str(),
				   "%*s %d%*c%d%*c%d "
				   "%d%*c%d%*c%d "
				   "%d%*c%d%*c%d",
				   &(vtn1.x), &(vtn1.y), &(vtn1.z), &(vtn2.x), &(vtn2.y), &(vtn2.z), &(vtn3.x), &(vtn3.y), &(vtn3.z));

	if (count == 9) {
		fs->add(vtn1);
		fs->add(vtn2);
		fs->add(vtn3);
	}

}

void ObjLoader::readNormals(const std::string line, TBuffer<var3D<float, float, float>> *vns)
{
	var3D<float, float, float> norms;
	int count;
	count = sscanf_s(line.c_str(), "%*s%f%f%f", &(norms.x), &(norms.y), &(norms.z));

	if (count == 3) {
		vns->add(norms);
	}
}

void ObjLoader::readUVs(const std::string line, TBuffer<var2D<float, float>> *uvs)
{
	var2D<float, float> texts;
	int count;
	count = sscanf_s(line.c_str(), "%*s%f%f", &(texts.x), &(texts.y));

	if (count == 2) {
		uvs->add(texts);
	}
}
