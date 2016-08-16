
#include "glVertexArray.h"

#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL+(bytes))


void GLVertexArray::initGLVertexArray(int mCount) {
	vaoID.resize(mCount);
	vboID.resize(mCount);
	iboID.resize(mCount);
}

void GLVertexArray::draw(int modelID,int modelIndexCount) {
	glBindVertexArray(vaoID[modelID]);
	glDrawArrays(GL_QUADS, 0, modelIndexCount);//描画されるべきインデックスの数(頂点座標(x,y,z)が何組あるか)
	glBindVertexArray(0);
}

void GLVertexArray::buildVBO(GLenum usage, const std::vector<Model*>& mlist,int mCount) {
	glGenVertexArrays(mCount, &(vaoID[0]));//VAO2つ作成
	glGenBuffers(mCount, &(vboID[0]));//VBO2つ作成
	glGenBuffers(mCount, &(iboID[0]));//IBO2つ作成

	for (int i = 0; i < mCount; ++i) {
		glBindVertexArray(vaoID[i]);//VAO切り替え

		//------VBOi個目----------//
		glBindBuffer(GL_ARRAY_BUFFER, vboID[i]);//バインド
												  //一つ目のバッファオブジェクトに頂点データ配列を転送する
												  //バッファのバインド
		glBindBuffer(GL_ARRAY_BUFFER, vboID[i]);
		//頂点情報のアップロード
		glBufferData(GL_ARRAY_BUFFER, sizeof(mlist[i]->myVertex), &(mlist[i]->myVertex[0]), usage);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//インデックスバッファも同様に
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID[i]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mlist[i]->indices), &(mlist[i]->indices[0]), usage);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


		//インデックスバッファ―をセット
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID[i]);
		//頂点バッファをセット
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);


		GLsizei stride = sizeof(MyVertex);//頂点データ長(次の頂点データまでの距離)
		glBindBuffer(GL_ARRAY_BUFFER, vboID[i]);
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

