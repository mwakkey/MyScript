#pragma once
#include <string>
#include <vector>
#include <fbxsdk.h>

typedef struct Vertex {
	float x, y, z;				//���_���W
	float normx, normy, normz;	//�@��
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

//Fbx�t�@�C�����璸�_���W�A�@���AUV�Ȃǂ��Ǘ�����N���X
class FbxFigure {
private:
	int polygonCount;		//���|���S����
	int* polygonSize;		//�e�|���S���̃T�C�Y

	int vertexCount;		//���_��
	Vertex* vertexBuffer;	//���_�o�b�t�@(Vertex)
	int indexCount;			//�C���f�b�N�X��
	int* indexBuffer;		//�C���f�b�N�X�o�b�t�@

	int normalLayerCount;	//�@���Z�b�g�̐�

	UvSet uvSet;			//UV�Z�b�g

	ColorRGBA* vertexColor;	//���_�J���[�z��
public:
	FbxFigure() {}
	~FbxFigure();

	//�|���S���̒��_�����i�[����(�S���b�V���̃|���S���𓝈ꂷ�邱�Ƃ����z����...)
	void getPolygonSize(FbxMesh* fbxMesh);
	void getPolygon(FbxMesh* fbxMesh);
	void getNormal(FbxMesh* fbxMesh);
	void getUV(FbxMesh* fbxMesh);			//�e�N�X�`����UV���W���擾
	void getTextureNames(FbxMesh* fbxMesh);	//�e�N�X�`���̖��O���擾
	void getVertexColor(FbxMesh* fbxMesh);
};