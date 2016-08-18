#pragma once
#include <fbxsdk.h>


namespace fbxsdk_2015_1 {
	void getAttrib(FbxNode* node, FbxMesh* attrib);//FbxSceneからMeshを取得する
	void getAttrib(FbxNode* node, FbxCamera* attrib);


	bool isMesh(FbxNode* node);//指定ノードがメッシュ(3Dオブジェクト)につながっているかどうか判定
	bool isCamera(FbxNode* node);
};