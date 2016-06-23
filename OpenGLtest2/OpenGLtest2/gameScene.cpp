
#include "gameScene.h"

GameScene::GameScene() :
	stateResult_(StateResult_Continue)
{
	setState(&GameScene::demo);
}

SceneBase::StateResult GameScene::update()
{
	void (GameScene::*oldState)() = stateFunc_;
	(this->*stateFunc_)();

	if (stateFunc_ != oldState) {
		;// �X�e�[�g�̐؂�ւ����������ꍇ�͉�ʂ��N���A����
	}
	return stateResult_;
}

void GameScene::demo()
{
	if (demoScene_.update()==StateResult::StateResult_Finish)
		setState(&GameScene::title);
}

//!< �^�C�g��
void GameScene::title()
{
	if (titleScene_.update() == StateResult_Finish) {
		switch (titleScene_.getSelectResult()) {
			case TitleScene::Select_GoDemo:
				setState(&GameScene::demo);
				break;
			case TitleScene::Select_GoGame:
				setState(&GameScene::game);
				break;
			case TitleScene::Select_Exit:
				setState(&GameScene::demo);
				stateResult_ = StateResult_Finish;
				break;
		}
	}
}

//!< �Q�[��
void GameScene::game()
{
	if (myGameScene_.update() == StateResult_Finish)
		setState(&GameScene::title);
}


void GameScene::setState(void (GameScene::*stateFunc)())
{
	stateFunc_ = stateFunc;
}