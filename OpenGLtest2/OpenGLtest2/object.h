#pragma once
#include "model.h"
#include <string>

class Object {
protected:
	Model* model;
	int modelID;

public:
	Object() {}
	Object(float pX, float pY, float pZ , std::string modelName);//インスタンス生成時にモデルIDが付与される
	~Object();//ポリモーフィズムを用いるならば基底クラスのデストラクタをvirtualにする

	void registerModel(std::vector<Model*>& mlist);

	int getModelID();
	int getMoredVertexCount();
};