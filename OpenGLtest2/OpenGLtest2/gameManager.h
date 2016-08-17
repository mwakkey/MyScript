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

	//Šeƒ‚ƒfƒ‹‚ðƒ‚ƒfƒ‹ƒŠƒXƒg‚É“o˜^‚µ‚Äƒ‚ƒfƒ‹ID‚ð—^‚¦‚Ä‚©‚çVAO‚ÉŠi”[‚·‚é
	void registerAllModels();
	
	void draw();
};