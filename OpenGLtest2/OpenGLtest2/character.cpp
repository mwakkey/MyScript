#include "character.h"
#include "obj.h"

Character::Character(float p[3], std::string modelName) {
	pos[0] = p[0];
	pos[1] = p[1];
	pos[2] = p[2];

	ObjLoader::loadObj(modelName, model);
}
Character::~Character() {
	delete(model);
}