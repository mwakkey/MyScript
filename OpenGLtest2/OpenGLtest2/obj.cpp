
#include "obj.h"

Obj::Obj()
{
	vs = new TBuffer<float>;
	fs = new TBuffer<int>;
}

Obj::~Obj()
{
	delete(vs);
	delete(fs);
}

Model* Obj::loadObj(const std::string fileName)
{
	std::string line;
}

void Obj::readVertices(const std::string line)
{
	;
}

void Obj::readIndices(const std::string line)
{
	;
}

Model* Obj::createModel()
{
	;
}