#pragma once

#include <vector>
#include <string>

//3つのベクトル
struct Vector3f
{
	float x;
	float y;
	float z;
}vec3d;
//4つのベクトル
struct Vector4f
{
	float x;
	float y;
	float z;
	float w;
}vec4d;
//4つの反射
struct Reflection4
{
	float diffuse;
	float ambient;
	float emission;
	float specular;
};
//4つのカラー
struct Color4
{
	float r;
	float g;
	float b;
	float a;
};
//UV座標
struct UV
{
	float u;//u値
	float v;//v値
}vec2d;
struct Vector4I
{
	int x;
	int y;
	int z;
	int w;
};
//ポリゴンデータ
struct Triangle
{
	Vector3f TriVer;
	Vector3f TriNor;
	UV TriUV;
}Tri;
//ポリゴンデータ
struct Quadrangle
{
	Vector3f QuadVer;
	Vector3f QuadNor;
	UV QuadUV;
}Quad;
//マテリアル構造体
struct MATERIAL
{
	int MaterialID;//ID
	std::string MaterialName;//マテリアル名
	Color4 Color;//カラー
	Reflection4 ReflectionColor;//反射
	float Power;//shiness
	std::string TextureName;//テクスチャ名
}mtl;
//モデルクラス
class MODEL
{
protected:
	bool LoadMaterialFromFile(char* FileName);//マテリアルロード
	std::vector <Triangle> Tridata;
	std::vector <Quadrangle> Quaddata;
public:
	MODEL();
	MODEL(char* FileName);//コンストラクタ
	bool OBJ_Load(char* FileName);//ロード
	void Draw();
};
