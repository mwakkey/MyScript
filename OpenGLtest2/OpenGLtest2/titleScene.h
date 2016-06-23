#pragma once

#include "sceneBase.h"

class TitleScene :SceneBase
{
public:
	// �^�C�g���ł̑I������
	enum Select
	{
		Select_None,
		Select_GoDemo,		//! �f����
		Select_GoGame,		//! �Q�[����
		Select_Exit			//! �Q�[���I��
	};

private:
	StateResult stateResult_;
	Select select_;

	// �X�e�[�g���\�b�h�Q
	void init(unsigned int ut);	//!< ������
	void idle(unsigned int ut);	//!< �A�C�h�����
	void end(unsigned int ut);	//!< �I��

	void (TitleScene::*stateFunc_)(unsigned int);	// �X�e�[�g���\�b�h�|�C���^
	void setState(void (TitleScene::*stateFunc)(unsigned int));
	

public:
	TitleScene();
	//! �^�C�g���̑I�����ʂ��擾
	Select getSelectResult();

	StateResult update();
};