
#include "glVertexArray.h"
#include "obj.h"

void GLVertexArray::glVertexBuffer(GLenum usage, const Model& m)
{

	//バッファオブジェクトの作成
	glGenBuffers(vBuffer.size(), &vBuffer[0]);
	
	//一つ目のバッファオブジェクトに頂点データ配列を転送する
	//バッファのバインド
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer[0]);
	//頂点情報のアップロード
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.vertices), &(m.vertices[0]), usage);
	
	//二つ目〃法線データ配列
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.normal), &(m.normal[0]), usage);

	//三つ目〃テクスチャ座標配列
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.uvs), &(m.uvs[0]), usage);

	//四つ目〃頂点インデックス
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.index), &(m.index[0]), usage);


	//バインドの解除
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	delete(model);
}

void GLVertexArray::glIndexBuffer()
{
	glGenBuffers(1, &vBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*model->vertices.size(), &(model->vertices[0]), usage);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void GLVertexArray::glDraw()
{
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_POINTS, 0, 1);
}