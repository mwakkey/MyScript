#include "fbxLoader.h"
#include "fbxUtil.h"

using namespace fbxsdk_2015_1;

FbxLoader::FbxLoader() {
	fbxManager = FbxManager::Create();
	fbxImporter = FbxImporter::Create(fbxManager,"");
	fbxScene = FbxScene::Create(fbxManager, "");
}

FbxLoader::~FbxLoader() {
	fbxManager->Destroy();
}


void FbxLoader::fbxImport(const char* filePath) {
	if (!fbxImporter->Initialize(filePath)) {
		fbxManager->Destroy();
	}
}

void FbxLoader::fbxSceneImport() {
	if (!fbxImporter->Import(fbxScene)) {
		fbxManager->Destroy();
		rootNode - fbxScene->GetRootNode();
	}
	else{
		fbxImporter->Destroy();
	}

}

void FbxLoader::fbxMeshImport() {
	getAttrib(rootNode, fbxMesh);
	polygonNum = fbxMesh->GetPolygonCount();
	polygonVertexNum = fbxMesh->GetPolygonVertexCount();
	indexAry = fbxMesh->GetPolygonVertices();
	
	controlAry = fbxMesh->GetControlPoints();//’¸“_À•W”z—ñ

}
