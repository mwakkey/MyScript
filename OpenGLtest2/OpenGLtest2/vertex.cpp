#include "vertex.h"

using namespace VERTEX;


void VERTEX::vertexArray2D(Vertex2D* vertex2D, const float vertices[][2],const float textures[][2], int length) {

	for (int i = 0; i < length; ++i) {
		vertex2D[i].vrt[0] = vertices[i][0];
		vertex2D[i].vrt[1] = vertices[i][1];
		vertex2D[i].tex[0] = textures[i][0];
		vertex2D[i].tex[1] = textures[i][1];
	}
}
void VERTEX::vertexArray2D(Vertex2D* vertex2D, const float vertices[][2]) {
	int length = sizeof(vertices) / sizeof(vertices[0]);

	for (int i = 0; i < length; ++i) {
		vertex2D[i].vrt[0] = vertices[i][0];
		vertex2D[i].vrt[1] = vertices[i][1];
	}
}

void VERTEX::vertexArray3D(Vertex3D* vertex3D, const float vertices[][3], const float textures[][2], int length) {

	for (int i = 0; i < length; ++i) {
		vertex3D[i].vrt[0] = vertices[i][0];
		vertex3D[i].vrt[1] = vertices[i][1];
		vertex3D[i].vrt[2] = vertices[i][2];
		vertex3D[i].tex[0] = textures[i][0];
		vertex3D[i].tex[1] = textures[i][1];
	}
}
void VERTEX::vertexArray3D(Vertex3D* vertex3D, const float vertices[][3]) {
	int length = sizeof(vertices) / sizeof(vertices[0]);

	for (int i = 0; i < length; ++i) {
		vertex3D[i].vrt[0] = vertices[i][0];
		vertex3D[i].vrt[1] = vertices[i][1];
		vertex3D[i].vrt[2] = vertices[i][2];
	}
}