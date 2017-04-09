#pragma once
#include <string>

namespace GameLib{
//�摜�f�[�^��RAW�`���Ŏ擾���AOpenGL�ŕ`�悷��
	class Image {
	private:
		char* texture;
//		int channel;//RGB��RGBa�Ȃǃ`���l����
		int iWidth, iHeight;//�摜�t�@�C���̏c���T�C�Y
		int textureID;

		int imageNum;//�摜�t�@�C�����̃e�N�X�`������(�e�N�X�`���͉����ɕ��Ԃ��̂Ƃ���)

	public:
		Image(const std::string, int);
		~Image();

		//�ǂݍ��񂾃e�N�X�`����GPU��ɓo�^����
		void loadImage();

		//position�͈̔͂�uv�ŋ�؂����̈��uid�Ԗڂ̃e�N�X�`����\�����
		//���W�z��͎��v����(�e�N�X�`�����W�͏㉺�t)
		void draw(float position[], float uv[], int uid);
	};

}