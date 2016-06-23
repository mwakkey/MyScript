
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

//! ������
void MyGameScene::init(unsigned int dt)
{
	//time_g = 0;
	stateResult_ = StateResult_Continue;
	//curComment_ = 0;
	setState(&MyGameScene::idle);
}

//! �A�C�h�����
void MyGameScene::idle(unsigned int dt)
{
	// �������\��
	//if (isDraw_g == false) {
	//	printf(message_g[curComment_].str);
	//	isDraw_g = true;
	//}

	// �w��̎��ԑ҂�
	//if (message_g[curComment_].time > time_g) {
	//	time_g += dt;
	//	return;
	//}

	// ���̃��b�Z�[�W��
	//curComment_++;
	//time_g = 0;
	//isDraw_g = false;

	// �I�[�ԕ��ɒB������I��
	//if (message_g[curComment_].time == 999) {
	//	setState(&MyGameScene::end);
	//}
}

//! �I��
void MyGameScene::end(unsigned int dt)
{
	stateResult_ = StateResult_Finish;
	setState(&MyGameScene::init);
}
