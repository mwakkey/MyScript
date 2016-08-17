#pragma once
#include <fbxsdk.h>


namespace fbxsdk_2015_1 {
	void probeNode(FbxNode* node);//FbxSceneが保持する様々なノードを探索する
	bool isMesh(FbxNode* node);//指定ノードがメッシュ(3Dオブジェクト)につながっているかどうか判定
	bool isCamera(FbxNode* node);
};