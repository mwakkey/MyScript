#pragma once
#include "character.h"
#include "glVertexArray.h"
#include <vector>

class GameManager {
private:
	std::vector<Model*> mlist;
	std::vector<std::string> objectNames;
	std::vector<Object> objects;
	std::vector<std::string> characterNames;
	std::vector<Character> characters;
	
	GLVertexArray* vao;
public:
	GameManager(std::vector<std::string>& objectFiles, std::vector<std::string>& characterFiles);
	~GameManager();

	//(x,y,z)にobjects[i]やcharacters[i]をインスタンス化する関数

	//各モデルをモデルリストに登録してモデルIDを与えてからVAOに格納する
	void registerAllModels();
	
	void draw();
};