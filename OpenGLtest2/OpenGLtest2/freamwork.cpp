#include "freamwork.h"


using namespace GameLib;

Freamwork* Freamwork::mInstance = 0;

Freamwork::Freamwork() {

}
Freamwork::~Freamwork() {

}

void Freamwork::createFreamwork() {
//���ɃC���X�^���X����������Ă���Ȃ�Ώ����𔲂���
	if (!mInstance) {
		mInstance = new Freamwork();
	}
}
void Freamwork::destroyFreamwork() {
	delete mInstance;
	mInstance = 0;
}

Freamwork* Freamwork::instance() {
	return mInstance;
}

void Freamwork::update() {
	//getInput();	����
	//updateGame();	��Ԃ̍X�V
	//draw();		�X�V��̏�Ԃ�`��
}