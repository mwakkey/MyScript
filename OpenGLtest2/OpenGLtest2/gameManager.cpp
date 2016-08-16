#include "gameManager.h"

GameManager::GameManager() {
	characters.resize(modelNames.size());
}

void GameManager::registerModels() {
	for (int i = 0; i < characters.size();++i) {
		characters[i].registerModel(mlist);
	}

}