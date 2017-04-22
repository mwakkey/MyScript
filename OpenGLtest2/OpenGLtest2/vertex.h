#pragma once

namespace VERTEX {
	class Vertex {
	private:
		float* vrt;//頂点座標
		float* tex;//テクスチャ座標(u,v)

		int dim;
	public:
		Vertex();
		Vertex(const float[],const float[2],const int);
		~Vertex();
		Vertex& operator=(const Vertex&);

		int getDim();
	};
	
	//vertices[][dim], indices[][2]からVertex[]を生成する
	Vertex* vertexArray(float**, float**, int, int);
}