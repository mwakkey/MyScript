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
	glPushMatrix();//���[���h���W�n�̕ϊ��s���ޔ������Ă���
}
void Character::actionFinish(std::function<void(int modelID, int modelIndexCount)>& draw) {
	draw(modelID, model->myVertex.size());//�`��
	glPopMatrix();//���[���h���W�n�ɖ߂�
}