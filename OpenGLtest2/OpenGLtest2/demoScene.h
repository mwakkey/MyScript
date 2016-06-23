#pragma once
#include "sceneBase.h"

class DemoScene:public SceneBase
{
private:
	StateResult stateResult_;
	unsigned int	time_;			//!< 経過時間

	void init(unsigned int ut);       // 初期化
	void start(unsigned int ut);       // デモを再生
	void play(unsigned int ut);	//! デモ中
	void end(unsigned int ut);	//! 終了


	void (DemoScene::*stateFunc_)(unsigned int);   // メソッドポインタ
	void setState(void (DemoScene::*stateFunc)(unsigned int ut));  // ステート設定

public:
	DemoScene();

	StateResult update();     // 更新
};