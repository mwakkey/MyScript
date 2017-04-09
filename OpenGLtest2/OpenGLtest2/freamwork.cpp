#include "freamwork.h"


using namespace GameLib;

Freamwork* Freamwork::mInstance = 0;

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
	//getInput();	入力
	//updateGame();	状態の更新
	//draw();		更新後の状態を描画
}