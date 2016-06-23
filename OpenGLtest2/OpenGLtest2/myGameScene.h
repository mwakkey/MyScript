#pragma once

#include "sceneBase.h"

class MyGameScene :public SceneBase
{
private:
	StateResult stateResult_;
	//unsigned int curComment_;

	// ステートメソッド群
	void init(unsigned int ut);	//!< 初期化
	void idle(unsigned int ut);	//!< アイドル状態
	void end(unsigned int ut);	//!< 終了

	void (MyGameScene::*stateFunc_)(unsigned int);	// ステートメソッドポインタ
	void setState(void (MyGameScene::*stateFunc)(unsigned int));

public:
	MyGameScene();
	StateResult update();     // 更新
};