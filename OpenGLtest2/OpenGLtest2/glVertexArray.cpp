
#include "glVertexArray.h"

#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL+(bytes))


GLVertexArray::GLVertexArray(int vaoSize, int vboSize, int iboSize) {
	vaoId.resize(vaoSize);
	vboId.resize(vboSize);
	iboId.resize(iboSize);
}

void GLVertexArray::draw(int arraySize) {
	glBindVertexArray(vaoId[0]);
	glDrawArrays(GL_QUADS, 0, arraySize);//頂点配列(ベクトル)のサイズ=頂点座標が何個あるか
	glBindVertexArray(0);
}

void GLVertexArray::buildVBO(GLenum usage, const std::vector<Model>& mlist) {
	glGenVertexArrays(2, &(vaoId[0]));//VAO2つ作成
	glGenBuffers(2, &(vboId[0]));//VBO2つ作成
	glGenBuffers(2, &(iboId[0]));//IBO2つ作成

	for (int i = 0; i < 2; ++i) {
		glBindVertexArray(vaoId[i]);//VAO切り替え

		//------VBOi個目----------//
		glBindBuffer(GL_ARRAY_BUFFER, vboId[i]);//バインド
												  //一つ目のバッファオブジェクトに頂点データ配列を転送する
												  //バッファのバインド
		glBindBuffer(GL_ARRAY_BUFFER, vboId[i]);
		//頂点情報のアップロード
		glBufferData(GL_ARRAY_BUFFER, sizeof(mlist[i].myVertex), &(mlist[i].myVertex[0]), usage);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//インデックスバッファも同様に
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId[i]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mlist[i].indices), &(mlist[i].indices[0]), usage);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


		//インデックスバッファ―をセット
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId[i]);
		//頂点バッファをセット
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);


		GLsizei stride = sizeof(MyVertex);//頂点データ長(次の頂点データまでの距離)
		glBindBuffer(GL_ARRAY_BUFFER, vboId[i]);
		glVertexPointer(3, GL_FLOAT, stride, NULL);
		glNormalPointer(GL_FLOAT, stride, BUFFER_OFFSET(sizeof(var3D<float, float, float>)));
		glTexCoordPointer(2, GL_FLOAT, stride, BUFFER_OFFSET(sizeof(var3D<float, float, float>) * 2));
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);//アンバインド
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glBindVertexArray(0);

}

