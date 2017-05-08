#pragma once
#include <fbxsdk.h>

class FbxLoader {
private:
	fbxsdk_2015_1::FbxManager* fbxManager;
	fbxsdk_2015_1::FbxImporter* fbxImporter;
	fbxsdk_2015_1::FbxScene* fbxScene;//3D空間を構成するオブジェクトのコンテナ
	fbxsdk_2015_1::FbxNode* rootNode;//fbxSceneのルートノード
	fbxsdk_2015_1::FbxMesh* fbxMesh;

public:
	FbxLoader();
	~FbxLoader();
	
	void fbxImport(const char* filePath);//FBXファイルを読み込む(失敗したらManagerを消去)
	void fbxSceneImport();//FBXシーンを読み込む(失敗したらManagerを、成功したらImporterを消去)

	void fbxMeshImport();//fbxSceneからメッシュ情報を読み込んでfbxMesh等に格納する
	
};