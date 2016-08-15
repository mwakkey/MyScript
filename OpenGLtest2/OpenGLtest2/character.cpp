#include "character.h"
#include "obj.h"
#include <GL/freeglut.h>


Character::Character(float pX, float pY, float pZ, std::string modelName) {
	pos[0] = pX;
	pos[1] = pY;
	pos[2] = pZ;

	ObjLoader::loadObj(modelName, model);
}
Character::~Character() {
	delete(model);
}

void Character::rotate(float angle,float x,float y,float z) {
	glRotatef(angle, x, y, z);
}

void Character::translate(float x, float y, float z) {
	glTranslatef(x, y, z);
}


void Character::actionStart() {
	glPushMatrix();//ワールド座標系の変換行列を退避させておく
}
void Character::actionFinish(std::function<void(int modelID, int modelIndexCount)>& draw) {
	draw(modelID, model->myVertex.size());//描画
	glPopMatrix();//ワールド座標系に戻す
}