#include "vertex.h"

using namespace VERTEX;

Vertex::Vertex()
	:dim(0) {
	vrt = 0;
	tex = 0;
}

Vertex::Vertex(const float vertice[],const float texture[2],const int dimension)
	:dim(dimension){
	vrt = new float[dim];
	tex = new float[2];
}
Vertex::~Vertex() {
	delete[] vrt;
	delete[] tex;
}

Vertex& Vertex::operator=(const Vertex& vertex) {
	delete[] vrt;
	this->vrt = vertex.vrt;

	delete[] tex;
	this->tex = vertex.tex;

	this->dim = vertex.dim;
	return *this;
}

int Vertex::getDim() {
	return dim;
}

Vertex* VERTEX::vertexArray(float** vertices, float** indices, int dim, int length) {
	Vertex* vertex = new Vertex[length];

	for (int i = 0; i < length; ++i) {
		vertex[i] = Vertex(vertices[i], indices[i], dim);
	}

	return vertex;
}