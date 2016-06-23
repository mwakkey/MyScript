#pragma once

#include "sceneBase.h"

class MyGameScene :public SceneBase
{
private:
	StateResult stateResult_;
	//unsigned int curComment_;

	// �X�e�[�g���\�b�h�Q
	void init(unsigned int ut);	//!< ������
	void idle(unsigned int ut);	//!< �A�C�h�����
	void end(unsigned int ut);	//!< �I��

	void (MyGameScene::*stateFunc_)(unsigned int);	// �X�e�[�g���\�b�h�|�C���^
	void setState(void (MyGameScene::*stateFunc)(unsigned int));

public:
	MyGameScene();
	StateResult update();     // �X�V
};