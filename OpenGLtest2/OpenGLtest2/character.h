#pragma once
#include "object.h"
#include <functional>

//���f���f�[�^�����I�u�W�F�N�g�̂����A�������̂��Ǘ�����N���X
class Character :public Object {//�A�N�Z�X�w��q�𖾎�����
protected:
	//���炩�̃A�N�V�������q�N���X(��̓I�ȃL�����N���X)�Ŏ�����action�Ɋi�[����
	std::function<void()> action;
public:
	Character() {}
	Character(float pX, float pY, float pZ, std::string modelName);//�p�����̃R���X�g���N�^���Ă�


	void rotate(float angle, float x, float y, float z);
	void translate(float x, float y, float z);

	//�L�����N�^�[���A�N�V��������֐�
	void actionStart();
	void actionFinish();
	
};