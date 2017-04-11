
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <fstream>
#include "Image.h"

using namespace GameLib;

Image::Image(std::string filename,int imageNum)
	:imageNum(5){
	std::ifstream fstr(filename, std::ios::binary);

	const size_t fileSize = static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
	fstr.seekg(0, fstr.beg);
	texture = new char[fileSize];
	fstr.read(texture, fileSize);
	
}

Image::~Image() {
	delete[](texture);
}

void Image::loadImage() {
	//�摜��o�^���邽�߂ɋ󂫃e�N�X�`����ID���擾
	GLuint texID;
	glGenTextures(1, &texID);

	//�擾�����e�N�X�`��ID�ɑ΂��đ�����s�����Ƃ�`���A�e�N�X�`���f�[�^��GPU�ɓ]��
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D,texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);

	//�e�N�X�`���ݒ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//�A���o�C���h
	glBindTexture(GL_TEXTURE_2D, 0);

	textureID=texID;
}

void Image::draw(float position[], float uv[], int uid) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glVertexPointer(2, GL_FLOAT, 0, position); //���_�z����`

	float w = 1.0f / imageNum;
	uv[0] = uv[0] + uid*w;
	uv[2] = uv[2] + uid*w;
	uv[4] = uv[4] + uid*w;
	uv[6] = uv[6] + uid*w;
	glTexCoordPointer(2, GL_FLOAT, 0, uv); //�e�N�X�`�����W�z����`


	glBindTexture(GL_TEXTURE_2D, textureID); //�`�悷��e�N�X�`��(��ID)���w��

	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY); //���_�z���L����
	glEnableClientState(GL_TEXTURE_COORD_ARRAY); //�e�N�X�`�����W�z���L����

	glDrawArrays(GL_QUADS, 0, 4);



	glFlush();//���s����Ă��Ȃ�OpenGL�̖��߂�S�Ď��s����

}