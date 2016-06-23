
#include "demoScene.h"

DemoScene::DemoScene():
	stateResult_(StateResult_Continue)
{
	setState(&DemoScene::init);
}


void DemoScene::setState(void (DemoScene::*stateFunc)(unsigned int ut))
{
	stateFunc_=stateFunc;
}

SceneBase::StateResult DemoScene::update()
{
	(this->*stateFunc_)(1);    // メソッドポインタを実行
	return stateResult_;
}


//! 初期化
void DemoScene::init(unsigned int ut)
{
	time_ = 0;
	stateResult_ = StateResult_Continue;
	setState(&DemoScene::start);
}

//! デモスタート
void DemoScene::start(unsigned int ut)
{
	setState(&DemoScene::play);
}

//! デモ中
void DemoScene::play(unsigned int ut)
{
	//setPos(0, 2);
	if (time_ >= 60) {
		setState(&DemoScene::end);
	}
	//printf("[ %d ]", time_);
	time_ += ut;
}

//! 終了
void DemoScene::end(unsigned int ut)
{
	stateResult_ = StateResult_Finish;
	setState(&DemoScene::init);
}