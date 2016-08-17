#include "object.h"
#include "objLoader.h"

Object::Object(float pX, float pY, float pZ, std::string modelName) {
	ObjLoader::loadObj(modelName, model);
	//モデルデータを読み込み、位置を初期化する
	model->posInit(pX, pY, pZ);
}
Object::~Object() {
	delete(model);
}

void Object::registerModel(std::vector<Model*>& mlist) {
	mlist.push_back(model);
	modelID = mlist.size() - 1;
}

int Object::getModelID() {
	return modelID;
}

int Object::getMoredVertexCount() {
	return model->myVertex.size();
}