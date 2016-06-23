
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
	(this->*stateFunc_)(1);    // ���\�b�h�|�C���^�����s
	return stateResult_;
}


//! ������
void DemoScene::init(unsigned int ut)
{
	time_ = 0;
	stateResult_ = StateResult_Continue;
	setState(&DemoScene::start);
}

//! �f���X�^�[�g
void DemoScene::start(unsigned int ut)
{
	setState(&DemoScene::play);
}

//! �f����
void DemoScene::play(unsigned int ut)
{
	//setPos(0, 2);
	if (time_ >= 60) {
		setState(&DemoScene::end);
	}
	//printf("[ %d ]", time_);
	time_ += ut;
}

//! �I��
void DemoScene::end(unsigned int ut)
{
	stateResult_ = StateResult_Finish;
	setState(&DemoScene::init);
}