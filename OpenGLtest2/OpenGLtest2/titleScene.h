#pragma once

#include "sceneBase.h"

class TitleScene :SceneBase
{
public:
	// タイトルでの選択項目
	enum Select
	{
		Select_None,
		Select_GoDemo,		//! デモへ
		Select_GoGame,		//! ゲームへ
		Select_Exit			//! ゲーム終了
	};

private:
	StateResult stateResult_;
	Select select_;

	// ステートメソッド群
	void init(unsigned int ut);	//!< 初期化
	void idle(unsigned int ut);	//!< アイドル状態
	void end(unsigned int ut);	//!< 終了

	void (TitleScene::*stateFunc_)(unsigned int);	// ステートメソッドポインタ
	void setState(void (TitleScene::*stateFunc)(unsigned int));
	

public:
	TitleScene();
	//! タイトルの選択結果を取得
	Select getSelectResult();

	StateResult update();
};