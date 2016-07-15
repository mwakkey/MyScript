
#include "glVertexArray.h"

void GLVertexArray::glBuffer()
{
	glCreateBuffers(1, &positionBuffer);
	glNamedBufferData(positionBuffer, sizeof(positionData), positionData, GL_STATIC_DRAW);

	glCreateVertexArrays(1, &vertexArray);
	glEnableVertexArrayAttrib(vertexArray, positionLocation);
	glVertexArrayAttribFormat(vertexArray, positionLocation, 2, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribBinding(vertexArray, positionLocation, positionBindIndex);
	glVertexArrayVertexBuffer(vertexArray, positionBindIndex, positionBuffer, 0, sizeof(GLfloat) * 2);
}

void GLVertexArray::glDraw()
{
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_POINTS, 0, 1);
}