#include "fbxUtil.h"


void fbxsdk_2015_1::getAttrib(FbxNode* node, FbxMesh* attrib) {
	if(node){
		if (isMesh(node)) {
			attrib = node->GetMesh();
			return;
		}
		for (int i = 0; i < node->GetChildCount(); ++i) {
			getAttrib(node->GetChild(i), attrib);
		}
	}
}

void fbxsdk_2015_1::getAttrib(FbxNode* node, FbxCamera* attrib) {
	if (node) {
		if (isCamera(node)) {
			attrib = node->GetCamera();
			return;
		}
		for (int i = 0; i < node->GetChildCount(); ++i) {
			getAttrib(node->GetChild(i), attrib);
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
