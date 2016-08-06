
#include "glVertexArray.h"
#include "obj.h"

void GLVertexArray::glBuffer()
{
	glCreateBuffers(1, &positionBuffer);

	Model *model = Obj::loadObj3D("test.obj");
	glNamedBufferData(positionBuffer, sizeof(float)*model->vertices.size(), &(model->vertices[0]), GL_STATIC_DRAW);
	delete(model);

	glCreateVertexArrays(1, &vertexArray);
	glEnableVertexArrayAttrib(vertexArray, positionLocation);
	glVertexArrayAttribFormat(vertexArray, positionLocation, 2, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribBinding(vertexArray, positionLocation, positionBindIndex);
	glVertexArrayVertexBuffer(vertexArray, positionBindIndex, positionBuffer, 0, sizeof(GLfloat) * 3);
}

void GLVertexArray::glDraw()
{
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_POINTS, 0, 1);
}