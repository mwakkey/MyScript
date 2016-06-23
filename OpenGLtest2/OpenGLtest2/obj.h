#pragma once

#include <vector>
#include <string>

//3�̃x�N�g��
struct Vector3f
{
	float x;
	float y;
	float z;
}vec3d;
//4�̃x�N�g��
struct Vector4f
{
	float x;
	float y;
	float z;
	float w;
}vec4d;
//4�̔���
struct Reflection4
{
	float diffuse;
	float ambient;
	float emission;
	float specular;
};
//4�̃J���[
struct Color4
{
	float r;
	float g;
	float b;
	float a;
};
//UV���W
struct UV
{
	float u;//u�l
	float v;//v�l
}vec2d;
struct Vector4I
{
	int x;
	int y;
	int z;
	int w;
};
//�|���S���f�[�^
struct Triangle
{
	Vector3f TriVer;
	Vector3f TriNor;
	UV TriUV;
}Tri;
//�|���S���f�[�^
struct Quadrangle
{
	Vector3f QuadVer;
	Vector3f QuadNor;
	UV QuadUV;
}Quad;
//�}�e���A���\����
struct MATERIAL
{
	int MaterialID;//ID
	std::string MaterialName;//�}�e���A����
	Color4 Color;//�J���[
	Reflection4 ReflectionColor;//����
	float Power;//shiness
	std::string TextureName;//�e�N�X�`����
}mtl;
//���f���N���X
class MODEL
{
protected:
	bool LoadMaterialFromFile(char* FileName);//�}�e���A�����[�h
	std::vector <Triangle> Tridata;
	std::vector <Quadrangle> Quaddata;
public:
	MODEL();
	MODEL(char* FileName);//�R���X�g���N�^
	bool OBJ_Load(char* FileName);//���[�h
	void Draw();
};
