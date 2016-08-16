#include "character.h"
#include "obj.h"
#include <GL/freeglut.h>


Character::Character(float pX, float pY, float pZ, std::string modelName) {
	ObjLoader::loadObj(modelName, model);
	//モデルデータを読み込み、位置を初期化する
	model->posInit(pX, pY, pZ);
}
Character::~Character() {
	delete(model);
}

void Character::registerModel(std::vector<Model*>& mlist) {
	mlist.push_back(model);
	modelID = mlist.size() - 1;
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