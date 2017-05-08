#pragma once

namespace VERTEX {
	struct Vertex2D {
		float vrt[2];//頂点座標
		float tex[2];//テクスチャ座標(u,v)
	};
	struct Vertex3D {
		float vrt[3];//頂点座標
		float tex[2];//テクスチャ座標(u,v)
	};
	
	//vertices[][2], textures[][2]からVertex2D[]を生成する
	void vertexArray2D(Vertex2D*, const float[][2], const float[][2], int);
	//vertices[][2]を変更する
	void vertexArray2D(Vertex2D*, const float[][2]);

	//vertices[][3], textures[][2]からVertex3D[]を生成する
	void vertexArray3D(Vertex3D*, const float[][3], const float[][2], int);
	//vertices[][3]を変更する
	void vertexArray3D(Vertex3D*, const float[][3]);
}