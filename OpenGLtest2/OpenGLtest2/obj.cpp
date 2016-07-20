
#include "obj.h"
#include <fstream>


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

void Obj::readVertices(const std::string line,TBuffer<float> *vs)
{
	;
}

void Obj::readIndices(const std::string line,TBuffer<int> *fs)
{
	;
}

Model* Obj::createModel(TBuffer<float> *vs, TBuffer<int> *fs)
{
	;
}