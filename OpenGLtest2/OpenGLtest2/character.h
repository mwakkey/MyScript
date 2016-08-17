#pragma once
#include "model.h"
#include <string>
#include <functional>

class Character {
private:
	Model* model;
	int modelID;

protected:
	std::function<void()> action;

public:
	Character(float pX, float pY, float pZ , std::string modelName);
	~Character();

	void registerModel(std::vector<Model*>& mlist);

	void rotate(float angle, float x, float y, float z);
	void translate(float x, float y, float z);

	//キャラクターがアクションする関数
	void act(std::function<void(int modelID, int modelIndexCount)>& draw);
	//何らかのアクションを子クラスで実装しactionに格納、それを下の2関数で挟む
	void actionStart();
	void actionFinish(std::function<void(int modelID,int modelIndexCount)>& draw);
};