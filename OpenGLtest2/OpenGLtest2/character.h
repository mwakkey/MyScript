#pragma once
#include "model.h"
#include <string>
#include <functional>

class Character {
private:
	Model* model;
	int modelID;


public:
	Character(float pX, float pY, float pZ , std::string modelName);
	~Character();

	void registerModel(std::vector<Model*>& mlist);

	void rotate(float angle, float x, float y, float z);
	void translate(float x, float y, float z);

	//何らかのアクションを子クラスで関数(std::function)形式で実装し、それを下の2関数で挟む
	void actionStart();
	void actionFinish(std::function<void(int modelID,int modelIndexCount)>& draw);
};