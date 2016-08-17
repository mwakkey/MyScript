#pragma once

#include "character.h"
#include "camera.h"
#include "controller.h"

//動くオブジェクトの中でも操作可能なものを管理するクラス
class Playable :public Character {
private:
	Camera* myCamera;
	Controller::JoyPad* myPad;

public:
	Playable(float pX, float pY, float pZ, std::string modelName);//継承元が先、メンバ変数が後
	~Playable();
	//具体的な処理はまた後日
};