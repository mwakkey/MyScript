#pragma once
#include <string>
#include <vector>
#include <fbxsdk.h>

typedef struct Vertex {
	float x, y, z;				//頂点座標
	float normx, normy, normz;	//法線
};

typedef struct Point2 {
	float x, y;

	bool operator==(Point2& val) {
		(this->x == val.x) && (this->y == val.y);
	}
};

typedef struct UvSet {
	std::string uvSetName;
	std::vector<std::string> textures;
	std::vector<Point2> uvBuffer;
};

typedef struct ColorRGBA {
	float r, g, b, a;
};

//Fbxファイルから頂点座標、法線、UVなどを管理するクラス
class FbxFigure {
private:
	int polygonCount;		//総ポリゴン数
	int* polygonSize;		//各ポリゴンのサイズ

	int vertexCount;		//頂点数
	Vertex* vertexBuffer;	//頂点バッファ(Vertex)
	int indexCount;			//インデックス数
	int* indexBuffer;		//インデックスバッファ

	int normalLayerCount;	//法線セットの数

	UvSet uvSet;			//UVセット

	ColorRGBA* vertexColor;	//頂点カラー配列
public:
	FbxFigure() {}
	~FbxFigure();

	//ポリゴンの頂点数を格納する(全メッシュのポリゴンを統一することが理想だが...)
	void getPolygonSize(FbxMesh* fbxMesh);
	void getPolygon(FbxMesh* fbxMesh);
	void getNormal(FbxMesh* fbxMesh);
	void getUV(FbxMesh* fbxMesh);			//テクスチャのUV座標を取得
	void getTextureNames(FbxMesh* fbxMesh);	//テクスチャの名前を取得
	void getVertexColor(FbxMesh* fbxMesh);
};