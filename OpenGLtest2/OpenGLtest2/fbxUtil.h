#pragma once
#include <fbxsdk.h>


namespace fbxsdk_2015_1 {
	void getAttrib(FbxNode* node, FbxMesh* attrib);//FbxScene����Mesh���擾����
	void getAttrib(FbxNode* node, FbxCamera* attrib);


	bool isMesh(FbxNode* node);//�w��m�[�h�����b�V��(3D�I�u�W�F�N�g)�ɂȂ����Ă��邩�ǂ�������
	bool isCamera(FbxNode* node);
};