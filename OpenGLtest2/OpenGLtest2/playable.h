#pragma once

#include "character.h"
#include "camera.h"
#include "controller.h"

//�����I�u�W�F�N�g�̒��ł�����\�Ȃ��̂��Ǘ�����N���X
class Playable :public Character {
private:
	Camera* myCamera;
	Controller::JoyPad* myPad;

public:
	Playable(float pX, float pY, float pZ, std::string modelName);//�p��������A�����o�ϐ�����
	~Playable();
	//��̓I�ȏ����͂܂����
};