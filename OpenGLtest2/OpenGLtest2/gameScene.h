#pragma once

#include "sceneBase.h"
#include "demoScene.h"
#include "titleScene.h"
#include "myGameScene.h"


class GameScene : public SceneBase
{
private:
	StateResult stateResult_;
	DemoScene   demoScene_;    // �f��
	TitleScene  titleScene_;   // �^�C�g��
	MyGameScene myGameScene_;  // �Q�[��
	
	void (GameScene::*stateFunc_)();   // ���\�b�h�|�C���^
	void setState(void (GameScene::*stateFunc)());
	void demo();   // �f��
	void title();  // �^�C�g��
	void game();   // �Q�[��
	

public:
	GameScene();

	StateResult update();  // �X�V

};