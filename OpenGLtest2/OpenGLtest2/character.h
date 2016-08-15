#pragma once
#include "model.h"
#include <string>


class Character {
private:
	float pos[3];
	Model* model;

public:
	Character(float p[3],std::string modelName);
	~Character();
};