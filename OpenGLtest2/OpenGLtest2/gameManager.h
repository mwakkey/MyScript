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

	//各モデルをモデルリストに登録し、モデルIDを与える
	void registerModels();
};