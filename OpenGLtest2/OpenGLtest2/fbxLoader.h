#pragma once
#include <fbxsdk.h>

class FbxLoader {
private:
	fbxsdk_2015_1::FbxManager* fbxManager;
	fbxsdk_2015_1::FbxImporter* fbxImporter;
	fbxsdk_2015_1::FbxScene* fbxScene;//3D��Ԃ��\������I�u�W�F�N�g�̃R���e�i

	fbxsdk_2015_1::FbxNode* rootNode;
public:
	FbxLoader();
	~FbxLoader();

	void fbxImport(const char* filePath);//FBX�t�@�C����ǂݍ���(���s������Manager������)
	void fbxSceneImport();//FBX�V�[����ǂݍ���(���s������Manager���A����������Importer������)

	

};