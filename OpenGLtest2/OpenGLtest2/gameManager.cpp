#include "gameManager.h"

GameManager::GameManager() {
	characters.resize(modelNames.size());
	vao = new GLVertexArray;
}

GameManager::~GameManager() {
	delete(vao);
	for (auto m : mlist) {
		delete(m);
	}
}

void GameManager::registerAllModels() {
	for (int i = 0; i < characters.size();++i) {
		characters[i].registerModel(mlist);
	}

	vao->initGLVertexArray(mlist.size());
	vao->buildVBO(GL_STATIC_DRAW, mlist, mlist.size());
}

void GameManager::draw() {
	for (int i = 0; i < characters.size(); ++i) {
		characters[i].act(vao->draw);
	}
}