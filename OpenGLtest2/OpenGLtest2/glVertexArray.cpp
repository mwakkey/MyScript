
#include "glVertexArray.h"


#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL+(bytes))

void GLVertexArray::glBufferDraw(GLenum usage, const Model& m)
{

	//バッファオブジェクトの作成
	glGenBuffers(1, &vBuffer);

	//一つ目のバッファオブジェクトに頂点データ配列を転送する
	//バッファのバインド
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer);
	//頂点情報のアップロード
	glBufferData(GL_ARRAY_BUFFER, sizeof(m.myVertex), &(m.myVertex[0]), usage);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//インデックスバッファも同様に
	glGenBuffers(1, &iBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m.indices), &(m.indices[0]), usage);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	//インデックスバッファ―をセット
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer);
	//頂点バッファをセット
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	
	GLsizei stride = sizeof(MyVertex);//頂点データ長(次の頂点データまでの距離)
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer);
	glVertexPointer(3, GL_FLOAT, stride, NULL);
	glNormalPointer(GL_FLOAT, stride, BUFFER_OFFSET(sizeof(var3D<float, float, float>)));
	glTexCoordPointer(2, GL_FLOAT, stride, BUFFER_OFFSET(sizeof(var3D<float, float, float>) * 2));


	//描画
	glDrawElements(GL_TRIANGLES, m.indices.size(), GL_UNSIGNED_INT, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}
