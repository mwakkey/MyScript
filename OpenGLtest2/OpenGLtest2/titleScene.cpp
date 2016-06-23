
#include "titleScene.h"

TitleScene::TitleScene():
	stateResult_(StateResult_Continue),
	select_(Select_None)
{
	setState(&TitleScene::init);
}

SceneBase::StateResult TitleScene::update()
{
	(this->*stateFunc_)(1);
	return stateResult_;
}

void TitleScene::setState(void (TitleScene::*stateFunc)(unsigned int))
{
	stateFunc_ = stateFunc;
}

TitleScene::Select TitleScene::getSelectResult()
{
	return select_;
}


//! ������
void TitleScene::init(unsigned int ut)
{
	//time_g = 0;
	select_ = Select_None;
	stateResult_ = StateResult_Continue;
	setState(&TitleScene::idle);
}

//! �ҋ@���
void TitleScene::idle(unsigned int ut)
{
	//if (time_g == 0) {
	//	printf(titleMessage);
	//}

	// timeOut�܂Ōo�߂�����f���ɖ߂�
	//if (time_g >= timeOut) {
		select_ = Select_GoDemo;
		setState(&TitleScene::end);
		return;
	//}

	// S�������ꂽ��Q�[���X�^�[�g
	//if (get_S_Key()) {
		select_ = Select_GoGame;
		setState(&TitleScene::end);
		return;
	//}

	// E�������ꂽ��Q�[���I��
	//if (get_E_Key()) {
		select_ = Select_Exit;
		setState(&TitleScene::end);
		return;
	//}
	//time_g += dt;
}

//! �I������
void TitleScene::end(unsigned int ut)
{
	stateResult_ = StateResult_Finish;
	setState(&TitleScene::init);
}