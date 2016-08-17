#pragma once
#include "model.h"
#include <string>

class Object {
protected:
	Model* model;
	int modelID;

public:
	Object() {}
	Object(float pX, float pY, float pZ , std::string modelName);//�C���X�^���X�������Ƀ��f��ID���t�^�����
	~Object();//�|�����[�t�B�Y����p����Ȃ�Ί��N���X�̃f�X�g���N�^��virtual�ɂ���

	void registerModel(std::vector<Model*>& mlist);

	int getModelID();
	int getMoredVertexCount();
};