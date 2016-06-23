#pragma once
#include "sceneBase.h"

class DemoScene:public SceneBase
{
private:
	StateResult stateResult_;
	unsigned int	time_;			//!< �o�ߎ���

	void init(unsigned int ut);       // ������
	void start(unsigned int ut);       // �f�����Đ�
	void play(unsigned int ut);	//! �f����
	void end(unsigned int ut);	//! �I��


	void (DemoScene::*stateFunc_)(unsigned int);   // ���\�b�h�|�C���^
	void setState(void (DemoScene::*stateFunc)(unsigned int ut));  // �X�e�[�g�ݒ�

public:
	DemoScene();

	StateResult update();     // �X�V
};