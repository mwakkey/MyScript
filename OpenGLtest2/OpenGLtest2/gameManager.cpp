#include "gameManager.h"

GameManager::GameManager(std::vector<std::string>& objectFiles, std::vector<std::string>& characterFiles) {
	objectNames = objectFiles;
	objects.resize(objectNames.size());
	characterNames = characterFiles;
	characters.resize(characterNames.size());
	vao = new GLVertexArray;
}

GameManager::~GameManager() {
	delete(vao);
	for (auto m : mlist) {
		delete(m);
	}
}

void GameManager::registerAllModels() {
	for (int i = 0; i < objects.size();++i) {
		objects[i].registerModel(mlist);
	}
	for (int i = 0; i < characters.size(); ++i) {
		characters[i].registerModel(mlist);
	}

	vao->initGLVertexArray(mlist.size());
	vao->buildVBO(GL_STATIC_DRAW, mlist, mlist.size());
}

void GameManager::draw() {
	for (int i = 0; i < characters.size(); ++i) {
		characters[i].actionStart();//変換行列の退避とアクションの実行
		vao->draw(characters[i].getModelID(), characters[i].getMoredVertexCount());//描画
		characters[i].actionFinish();//変換行列の復元
	}
	//動きに変化のないobjectsも描画が必要？(その場合はすべてcharactersにする)
}