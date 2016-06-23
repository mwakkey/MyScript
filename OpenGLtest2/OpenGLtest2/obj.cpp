
#include <GL/glut.h>
#include "obj.h"

MODEL::MODEL()
{}
MODEL::MODEL(char* FileName)
{
	OBJ_Load(FileName);
}

void MODEL::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	if (Tridata.size()>1) {
		glVertexPointer(3, GL_FLOAT, sizeof(Tri), &Tridata[0].TriVer.x);
		glNormalPointer(GL_FLOAT, sizeof(Tri), &Tridata[0].TriNor.x);
		glDrawArrays(GL_TRIANGLES, 0, Tridata.size());
	}
	if (Quaddata.size()>1) {
		glVertexPointer(3, GL_FLOAT, sizeof(Quad), &Quaddata[0].QuadVer.x);
		glNormalPointer(GL_FLOAT, sizeof(Quad), &Quaddata[0].QuadNor.x);
		glDrawArrays(GL_QUADS, 0, Quaddata.size());
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}

//OBJ�t�@�C���ǂݍ���
bool MODEL::OBJ_Load(char* FileName)
{
	Vector4I Face[3];//�ꎞ����p
	std::vector <Vector3f> Vertex;//���_
	std::vector <Vector3f> Normal;//�@��
	std::vector <UV> uv;//UV
	std::vector <unsigned int> TriVerID;
	std::vector <unsigned int> TriNorID;
	std::vector <unsigned int> TriUVID;
	std::vector <unsigned int> QuadVerID;
	std::vector <unsigned int> QuadNorID;
	std::vector <unsigned int> QuadUVID;

	char key[255] = { 0 };
	//OBJ�t�@�C�����J���ē��e��ǂݍ���
	FILE* fp = NULL;
	fopen_s(&fp, FileName, "rt");

	//�ǂݍ���
	fseek(fp, SEEK_SET, 0);

	while (!feof(fp)) {
		//�L�[���[�h
		ZeroMemory(key, sizeof(key));
		fscanf_s(fp, "%s ", key, sizeof(key));
		//�}�e���A��
		if (strcmp(key, "mtllib") == 0) {
			fscanf_s(fp, "%s ", key, sizeof(key));
			LoadMaterialFromFile(key);
		}
		//���_
		if (strcmp(key, "v") == 0) {
			fscanf_s(fp, "%f %f %f", &vec3d.x, &vec3d.y, &vec3d.z);
			Vertex.push_back(vec3d);
		}
		//�@��
		if (strcmp(key, "vn") == 0) {
			fscanf_s(fp, "%f %f %f", &vec3d.x, &vec3d.y, &vec3d.z);
			Normal.push_back(vec3d);
		}
		//�e�N�X�`��
		if (strcmp(key, "vt") == 0) {
			fscanf_s(fp, "%f %f", &vec2d.u, &vec2d.v);
			uv.push_back(vec2d);
		}
		//�ʂ̃C���f�b�N�X 0=���_ 1=UV 2=�@��
		if (strcmp(key, "f") == 0) {
			Face[0].w = -1;
			Face[1].w = -1;
			Face[2].w = -1;
			fscanf_s(fp, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &Face[0].x, &Face[1].x, &Face[2].x, &Face[0].y, &Face[1].y, &Face[2].y, &Face[0].z, &Face[1].z, &Face[2].z, &Face[0].w, &Face[1].w, &Face[2].w);
			if ((Face[0].w == -1) && (Face[1].w == -1) && (Face[2].w == -1)) {
				//�O�p��
				TriVerID.push_back(Face[0].x - 1);
				TriVerID.push_back(Face[0].y - 1);
				TriVerID.push_back(Face[0].z - 1);
				TriUVID.push_back(Face[1].x - 1);
				TriUVID.push_back(Face[1].y - 1);
				TriUVID.push_back(Face[1].z - 1);
				TriNorID.push_back(Face[2].x - 1);
				TriNorID.push_back(Face[2].y - 1);
				TriNorID.push_back(Face[2].z - 1);
			}
			else {
				//�l�p��
				QuadVerID.push_back(Face[0].x - 1);
				QuadVerID.push_back(Face[0].y - 1);
				QuadVerID.push_back(Face[0].z - 1);
				QuadVerID.push_back(Face[0].w - 1);
				QuadUVID.push_back(Face[1].x - 1);
				QuadUVID.push_back(Face[1].y - 1);
				QuadUVID.push_back(Face[1].z - 1);
				QuadUVID.push_back(Face[1].w - 1);
				QuadNorID.push_back(Face[2].x - 1);
				QuadNorID.push_back(Face[2].y - 1);
				QuadNorID.push_back(Face[2].z - 1);
				QuadNorID.push_back(Face[2].w - 1);
			}
		}
	}
	for (int i = 0; i<(signed)TriVerID.size(); i++) {
		Tri.TriVer = Vertex[TriVerID[i]];
		Tri.TriNor = Normal[TriNorID[i]];
		Tri.TriUV = uv[TriUVID[i]];
		Tridata.push_back(Tri);
	}
	printf("%d", Tridata.size());
	for (int i = 0; i<(signed)QuadVerID.size(); i++) {
		Quad.QuadVer = Vertex[QuadVerID[i]];
		Quad.QuadNor = Normal[QuadNorID[i]];
		Quad.QuadUV = uv[QuadUVID[i]];
		Quaddata.push_back(Quad);
	}
	Vertex.clear();
	Normal.clear();
	uv.clear();
	TriVerID.clear();
	TriNorID.clear();
	TriUVID.clear();
	QuadVerID.clear();
	QuadNorID.clear();
	QuadUVID.clear();
	return true;
}
bool MODEL::LoadMaterialFromFile(char *FileName)
{
	return true;
}