#pragma once
#include <string>

namespace GL{
//�摜�f�[�^��RAW�`���Ŏ擾���AOpenGL�ɓo�^����
	class Image {
	private:
		char* texture;
//		int channel;//RGB��RGBa�Ȃǃ`���l����
		int iWidth, iHeight;//�摜�t�@�C���̏c���T�C�Y

	public:
		Image(const std::string, int, int);
		~Image();

		//�ǂݍ��񂾃e�N�X�`����GPU��ɓo�^����
		unsigned int loadImage();
	};

}