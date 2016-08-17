#include "character.h"
#include <GL/freeglut.h>

Character::Character(float pX, float pY, float pZ, std::string modelName)
	:Object(pX, pY, pZ, modelName){}


void Character::rotate(float angle, float x, float y, float z) {
	glRotatef(angle, x, y, z);
}

void Character::translate(float x, float y, float z) {
	glTranslatef(x, y, z);
}



void Character::actionStart() {
	glPushMatrix();//ワールド座標系の変換行列を退避させておく
	action();
}

void Character::actionFinish() {
	glPopMatrix();//ワールド座標系に戻す
}

