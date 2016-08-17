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

	//(x,y,z)��objects[i]��characters[i]���C���X�^���X������֐�

	//�e���f�������f�����X�g�ɓo�^���ă��f��ID��^���Ă���VAO�Ɋi�[����
	void registerAllModels();
	
	void draw();
};