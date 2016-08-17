#pragma once
#include "character.h"
#include "glVertexArray.h"
#include <vector>

class GameManager {
private:
	std::vector<std::string> modelNames;
	std::vector<Model*> mlist;
	std::vector<Character> characters;
	
	GLVertexArray* vao;
public:
	GameManager();
	~GameManager();

	//�e���f�������f�����X�g�ɓo�^���ă��f��ID��^���Ă���VAO�Ɋi�[����
	void registerAllModels();
	
	void draw();
};