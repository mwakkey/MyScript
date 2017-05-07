
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <fstream>
#include "Image.h"
#include "vbo.h"

using namespace GL;

Image::Image(std::string filename, int width, int height)
	:iWidth(width),iHeight(height) {
	std::ifstream fstr(filename, std::ios::binary);

	const size_t fileSize = static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
	fstr.seekg(0, fstr.beg);
	texture = new char[fileSize];
	fstr.read(texture, fileSize);

}

Image::~Image() {
	delete[](texture);
}

unsigned int Image::loadImage() {
	//�摜��o�^���邽�߂ɋ󂫃e�N�X�`����ID���擾
	unsigned int texID;
	glGenTextures(1, &texID);

	//�擾�����e�N�X�`��ID�ɑ΂��đ�����s�����Ƃ�`���A�e�N�X�`���f�[�^��GPU�ɓ]��
	glBindTexture(GL_TEXTURE_2D,texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);

	//�e�N�X�`���ݒ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//�A���o�C���h
	glBindTexture(GL_TEXTURE_2D, 0);

	return texID;
}
