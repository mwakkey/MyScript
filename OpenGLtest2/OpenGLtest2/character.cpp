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
	glPushMatrix();//���[���h���W�n�̕ϊ��s���ޔ������Ă���
	action();
}

void Character::actionFinish() {
	glPopMatrix();//���[���h���W�n�ɖ߂�
}

