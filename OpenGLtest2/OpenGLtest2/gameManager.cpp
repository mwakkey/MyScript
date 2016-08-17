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
		characters[i].actionStart();//�ϊ��s��̑ޔ��ƃA�N�V�����̎��s
		vao->draw(characters[i].getModelID(), characters[i].getMoredVertexCount());//�`��
		characters[i].actionFinish();//�ϊ��s��̕���
	}
	//�����ɕω��̂Ȃ�objects���`�悪�K�v�H(���̏ꍇ�͂��ׂ�characters�ɂ���)
}