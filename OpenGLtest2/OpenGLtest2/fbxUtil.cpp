#include "fbxUtil.h"


void fbxsdk_2015_1::probeNode(FbxNode* node) {
	if(node){
		if (isMesh(node)) {
			FbxMesh* mesh = node->GetMesh();
			if (mesh != NULL) {
				//ˆ—‚ðŒã‚Å’Ç‰Á
			}
			mesh->Destroy();
		}
		for (int i = 0; i < node->GetChildCount(); ++i) {
			probeNode(node->GetChild(i));
		}
	}
}

bool fbxsdk_2015_1::isMesh(FbxNode* node) {
	if (node) {
		int attrCount = node->GetNodeAttributeCount();

		for (int i = 0; i < attrCount; ++i) {
			FbxNodeAttribute::EType attrType = node->GetNodeAttributeByIndex(i)->GetAttributeType();
			if (attrType == FbxNodeAttribute::EType::eMesh) {
				return true;
			}
		}
	}
	return false;
}

bool fbxsdk_2015_1::isCamera(FbxNode* node) {
	if (node) {
		int attrCount = node->GetNodeAttributeCount();

		for (int i = 0; i < attrCount; ++i) {
			FbxNodeAttribute::EType attrType = node->GetNodeAttributeByIndex(i)->GetAttributeType();
			if (attrType == FbxNodeAttribute::EType::eCamera) {
				return true;
			}
		}
	}
	return false;
}
