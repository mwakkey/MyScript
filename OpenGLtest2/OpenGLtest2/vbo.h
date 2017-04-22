#pragma once
#include "vertex.h"

namespace GL {
	class VBO {
	private:
		unsigned int vrtID;//GLuint
		unsigned int idxID;//GLuint

		int dim;//頂点データのうち、頂点座標
		int stride;//頂点データの間隔
		int vrtSize;//頂点データの長さ
		VBO() {}
	public:
		VBO(const VERTEX::Vertex[], int, const int[], int);
		~VBO();
		void draw();
		void modify(VERTEX::Vertex[]);
	};
}