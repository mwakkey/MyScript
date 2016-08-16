#pragma once
#include "character.h"
#include <vector>

class GameManager {
private:
	std::vector<std::string> modelNames;
	std::vector<Model*> mlist;
	std::vector<Character> characters;
public:
	GameManager();

	//�e���f�������f�����X�g�ɓo�^���A���f��ID��^����
	void registerModels();
};