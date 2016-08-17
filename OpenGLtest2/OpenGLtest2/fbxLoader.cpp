#include "fbxLoader.h"

using namespace fbxsdk_2015_1;

FbxLoader::FbxLoader() {
	fbxManager = FbxManager::Create();
	fbxImporter = FbxImporter::Create(fbxManager,"");
	fbxScene = FbxScene::Create(fbxManager, "");
}

FbxLoader::~FbxLoader() {
	fbxManager->Destroy();
	fbxScene->Destroy();
}

void FbxLoader::fbxImport(const char* filePath) {
	if (!fbxImporter->Initialize(filePath)) {
		fbxManager->Destroy();
	}
}

void FbxLoader::fbxSceneImport() {
	if (!fbxImporter->Import(fbxScene)) {
		fbxManager->Destroy();
	}
	else{
		fbxImporter->Destroy();
	}
}
