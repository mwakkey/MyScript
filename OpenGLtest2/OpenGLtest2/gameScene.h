#pragma once

#include "sceneBase.h"
#include "demoScene.h"
#include "titleScene.h"
#include "myGameScene.h"


class GameScene : public SceneBase
{
private:
	StateResult stateResult_;
	DemoScene   demoScene_;    // デモ
	TitleScene  titleScene_;   // タイトル
	MyGameScene myGameScene_;  // ゲーム
	
	void (GameScene::*stateFunc_)();   // メソッドポインタ
	void setState(void (GameScene::*stateFunc)());
	void demo();   // デモ
	void title();  // タイトル
	void game();   // ゲーム
	

public:
	GameScene();

	StateResult update();  // 更新

};