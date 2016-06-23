#pragma once
class SceneBase
{
public:
	enum StateResult
	{
		StateResult_Finish,     // �J�ڏI��
		StateResult_Continue    // �J�ڒ�
	};

	virtual StateResult update() = 0;   // �X�V
};
