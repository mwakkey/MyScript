#pragma once
#include <fbxsdk.h>

class FbxLoader {
private:
	fbxsdk_2015_1::FbxManager* fbxManager;
	fbxsdk_2015_1::FbxImporter* fbxImporter;
	fbxsdk_2015_1::FbxScene* fbxScene;//3D��Ԃ��\������I�u�W�F�N�g�̃R���e�i
	fbxsdk_2015_1::FbxNode* rootNode;//fbxScene�̃��[�g�m�[�h

	FbxMesh* fbxMesh;
	int polygonNum;			//���|���S����
	int polygonVertexNum;	//�|���S�����_�C���f�b�N�X��
	int* indexAry;			//�S�|���S�����_�̃C���f�b�N�X�z��
	FbxVector4* controlAry; //���b�V���Ɋ܂܂�钸�_���W�̔z��

public:
	FbxLoader();
	~FbxLoader();
	
	void fbxImport(const char* filePath);//FBX�t�@�C����ǂݍ���(���s������Manager������)
	void fbxSceneImport();//FBX�V�[����ǂݍ���(���s������Manager���A����������Importer������)

	void fbxMeshImport();//fbxScene���烁�b�V������ǂݍ����fbxMesh���Ɋi�[����
	
};