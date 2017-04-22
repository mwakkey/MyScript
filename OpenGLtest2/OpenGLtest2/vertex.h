#pragma once

namespace VERTEX {
	class Vertex {
	private:
		float* vrt;//���_���W
		float* tex;//�e�N�X�`�����W(u,v)

		int dim;
	public:
		Vertex();
		Vertex(const float[],const float[2],const int);
		~Vertex();
		Vertex& operator=(const Vertex&);

		int getDim();
	};
	
	//vertices[][dim], indices[][2]����Vertex[]�𐶐�����
	Vertex* vertexArray(float**, float**, int, int);
}