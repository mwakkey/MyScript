#pragma once

namespace VERTEX {
	struct Vertex2D {
		float vrt[2];//���_���W
		float tex[2];//�e�N�X�`�����W(u,v)
	};
	struct Vertex3D {
		float vrt[3];//���_���W
		float tex[2];//�e�N�X�`�����W(u,v)
	};
	
	//vertices[][2], textures[][2]����Vertex2D[]�𐶐�����
	void vertexArray2D(Vertex2D*, const float[][2], const float[][2], int);
	//vertices[][2]��ύX����
	void vertexArray2D(Vertex2D*, const float[][2]);

	//vertices[][3], textures[][2]����Vertex3D[]�𐶐�����
	void vertexArray3D(Vertex3D*, const float[][3], const float[][2], int);
	//vertices[][3]��ύX����
	void vertexArray3D(Vertex3D*, const float[][3]);
}