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

	//各モデルをモデルリストに登録してモデルIDを与えてからVAOに格納する
	void registerAllModels();
	
	void draw();
};