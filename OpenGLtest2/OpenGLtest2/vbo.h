#pragma once
#include "vertex.h"

namespace GL {
	class VBO {
	private:
		unsigned int vrtID;//Vertex配列の登録ID(GLuint)
		unsigned int idxID;//Vertexのインデックスを表す配列の登録ID(GLuint)
		unsigned int texID;//テクスチャの登録ID(GLuint)

		int dim;//頂点データのうち、頂点座標の次元数
		int stride;//頂点データの間隔
		int vrtLength;//頂点データの長さ
		VBO(){}
	public:
		VBO(const float[][2], const float[][2], const int[], const unsigned int);
		VBO(const float[][3], const float[][2], const int[], const unsigned int);
		~VBO();

		void draw();
		void modify(const float[][2]);
		void modify(const float[][3]);

	};
}