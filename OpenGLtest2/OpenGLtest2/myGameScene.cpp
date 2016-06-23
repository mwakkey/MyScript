
#include "myGameScene.h"

MyGameScene::MyGameScene():
	//curComment_(0),
	stateResult_(StateResult_Continue)
{
	setState(&MyGameScene::init);
}

SceneBase::StateResult MyGameScene::update()
{
	(this->*stateFunc_)(1);
	return stateResult_;
}

void MyGameScene::setState(void (MyGameScene::*stateFunc)(unsigned int))
{
	stateFunc_ = stateFunc;
}

//! 初期化
void MyGameScene::init(unsigned int dt)
{
	//time_g = 0;
	stateResult_ = StateResult_Continue;
	//curComment_ = 0;
	setState(&MyGameScene::idle);
}

//! アイドル状態
void MyGameScene::idle(unsigned int dt)
{
	// 文字列を表示
	//if (isDraw_g == false) {
	//	printf(message_g[curComment_].str);
	//	isDraw_g = true;
	//}

	// 指定の時間待つ
	//if (message_g[curComment_].time > time_g) {
	//	time_g += dt;
	//	return;
	//}

	// 次のメッセージへ
	//curComment_++;
	//time_g = 0;
	//isDraw_g = false;

	// 終端番兵に達したら終了
	//if (message_g[curComment_].time == 999) {
	//	setState(&MyGameScene::end);
	//}
}

//! 終了
void MyGameScene::end(unsigned int dt)
{
	stateResult_ = StateResult_Finish;
	setState(&MyGameScene::init);
}
