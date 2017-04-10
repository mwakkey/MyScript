#include "freamwork.h"


using namespace GameLib;

Freamwork* Freamwork::mInstance = 0;
bool Freamwork::pauseFlag = false;

Freamwork::Freamwork() {

}
Freamwork::~Freamwork() {

}

void Freamwork::createFreamwork() {
//既にインスタンスが生成されているならば処理を抜ける
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
	//if(!pauseFlag)
	//getInput();	入力
	//updateGame();	状態の更新
	//draw();		更新後の状態を描画
}

void Freamwork::pause() {
	pauseFlag = (pauseFlag == true ? false : true);
}