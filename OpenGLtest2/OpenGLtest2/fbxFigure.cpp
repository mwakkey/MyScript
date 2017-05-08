#include "fbxFigure.h"

FbxFigure::~FbxFigure() {
	delete[] vertexBuffer;
	delete[] indexBuffer;
	delete[] polygonSize;
	delete[] vertexColor;
}

void FbxFigure::getPolygonSize(FbxMesh* fbxMesh) {
	polygonSize = new int[polygonCount];
	for (int i = 0; i < polygonCount; ++i) {
		polygonSize[i] = fbxMesh->GetPolygonSize(i);
	}
}

void FbxFigure::getPolygon(FbxMesh* fbxMesh) {
	polygonCount = fbxMesh->GetPolygonCount();

	vertexCount = fbxMesh->GetControlPointsCount();
	indexCount = fbxMesh->GetPolygonVertexCount();
	FbxVector4* vertexAry = fbxMesh->GetControlPoints();	//���b�V���Ɋ܂܂�钸�_���W�̔z��(double)
	vertexBuffer = new Vertex[vertexCount];
	for (int i = 0; i < vertexCount; ++i) {
		vertexBuffer[i].x = (float)vertexAry[i][0];	//x���W��float�ɃL���X�g
		vertexBuffer[i].y = (float)vertexAry[i][1];	//y���W��float�ɃL���X�g
		vertexBuffer[i].z = (float)vertexAry[i][2];	//z���W��float�ɃL���X�g
	}
	delete(vertexAry);	//�o�b�t�@�Ƀf�[�^���i�[������f���[�g����

	int* indexAry = fbxMesh->GetPolygonVertices();	//�S�|���S�����_�̃C���f�b�N�X�z��
	indexBuffer = new int[indexCount];
	for (int i = 0; i < indexCount; ++i) {
		indexBuffer[i] = indexAry[i];
	}
	delete(indexAry);	//�o�b�t�@�Ƀf�[�^���i�[������f���[�g����

}

void FbxFigure::getNormal(FbxMesh* fbxMesh) {
	normalLayerCount = fbxMesh->GetElementNormalCount();

	for (int i = 0; i < normalLayerCount; ++i) {
		//�w�背�C���[�̖@���Z�b�g���擾
		FbxGeometryElementNormal* normal = fbxMesh->GetElementNormal(i);

		//�}�b�s���O���[�h�̎擾(eByControlPoint�̂Ƃ��̓C���f�b�N�X�o�b�t�@���g�p)
		//���b�V���Ɋւ����`
		FbxGeometryElement::EMappingMode mapping = normal->GetMappingMode();
		//���t�@�����X���[�h�̎擾
		//�f�[�^�̊i�[���@�Ɋւ����`
		FbxGeometryElement::EReferenceMode reference = normal->GetReferenceMode();

		//--- �}�b�s���O���[�h�̔��� ---//
		switch (mapping) {
		case FbxGeometryElement::eByControlPoint:
			//--- ���t�@�����X���[�h�̔��� ---//
			switch (reference) {
			case FbxGeometryElement::eDirect:
			{
				//--- �@�������擾 ---//
				int normalCount = normal->GetDirectArray().GetCount();

				//-----------------------------------------------------------------------
				// eDirect �̏ꍇ�f�[�^�͏��ԂɊi�[����Ă���̂ł��̂܂ܕێ�
				//-----------------------------------------------------------------------
				for (int i = 0; normalCount > i; i++) {
					//--- �@���̎擾 ---//
					vertexBuffer[i].normx = (float)normal->GetDirectArray().GetAt(i)[0];
					vertexBuffer[i].normy = (float)normal->GetDirectArray().GetAt(i)[1];
					vertexBuffer[i].normz = (float)normal->GetDirectArray().GetAt(i)[2];
				}
			}
			break;

			case FbxGeometryElement::eIndexToDirect:
				break;

			default:
				break;
			}

			break;
		case FbxGeometryElement::eByPolygonVertex:
			break;
		default:
			break;
		}
	}

}

void FbxFigure::getUV(FbxMesh* fbxMesh) {
	//UV�Z�b�g�̐����擾
	int UVLayerCount = fbxMesh->GetElementUVCount();
	for (int i = 0; i < UVLayerCount; ++i) {
		//UV�o�b�t�@���擾
		FbxGeometryElementUV* UV = fbxMesh->GetElementUV(i);
		//--- �}�b�s���O���[�h�̎擾
		FbxGeometryElement::EMappingMode mapping = UV->GetMappingMode();
		//--- ���t�@�����X���[�h�̎擾 ---//
		FbxGeometryElement::EReferenceMode reference = UV->GetReferenceMode();

		//--- UV�����擾 ---//
		int uvCount = UV->GetDirectArray().GetCount();

		//--- �}�b�s���O���[�h�̔��� ---//
		switch (mapping) {
		case FbxGeometryElement::eByControlPoint:
			break;

		case FbxGeometryElement::eByPolygonVertex:
			//--- ���t�@�����X���[�h�̔��� ---//
			switch (reference) {
			case FbxGeometryElement::eDirect:
				break;
			case FbxGeometryElement::eIndexToDirect:
			{
				FbxLayerElementArrayTemplate<int>* uvIndex = &UV->GetIndexArray();
				int uvIndexCount = uvIndex->GetCount();

				//--- UV��ێ� ---// 
				Point2 temp;
				for (int i = 0; uvIndexCount > i; i++) {

					temp.x = (float)UV->GetDirectArray().GetAt(uvIndex->GetAt(i))[0];

					temp.y = 1.0f - (float)UV->GetDirectArray().GetAt(uvIndex->GetAt(i))[1];

					uvSet.uvBuffer.push_back(temp);
				}

				//--- UVSet�����擾 ---//
				uvSet.uvSetName = UV->GetName();
			}
			break;
			default:
				break;
			}
			break;
		case FbxGeometryElement::eByEdge:
			break;
		case FbxGeometryElement::eByPolygon:
			break;
		default:
			break;
		}
	}

}
void FbxFigure::getTextureNames(FbxMesh* fbxMesh) {
	FbxNode* node = fbxMesh->GetNode();
	int materialCount = node->GetMaterialCount();
	for (int i = 0; i < materialCount; ++i) {
		FbxSurfaceMaterial* material = node->GetMaterial(i);
		//����������(sDiffuse,sSpecular,sBump,sNormalMap��)
		FbxProperty prop = material->FindProperty(FbxSurfaceMaterial::sDiffuse);
		//�v���p�e�B�ɃA�^�b�`���ꂽ�e�N�X�`���̎�ނ𔻕�
		//FbxLayeredTexture,FbxFileTexture,FbxProceduralTexture

		//FbxLayeredTexture:�����̃e�N�X�`�����u�����h�g�p����ꍇ
		int layeredTextureCount = prop.GetSrcObjectCount<FbxLayeredTexture>();
		//�A�^�b�`���ꂽ�e�N�X�`����FbxLayeredTexture�̏ꍇ
		if (layeredTextureCount > 0) {
			for (int j = 0; j < layeredTextureCount; ++j) {
				FbxLayeredTexture* layeredTexture = prop.GetSrcObject<FbxLayeredTexture>(j);
				int textureCount = layeredTexture->GetSrcObjectCount<FbxFileTexture>();

				for (int k = 0; textureCount > k; k++) {
					FbxFileTexture* texture = prop.GetSrcObject<FbxFileTexture>(k);

					if (texture) {
						std::string textureName = texture->GetRelativeFileName();
	
						//UVSet�����擾
						std::string UVSetName = texture->UVSet.Get().Buffer();
						if (uvSet.uvSetName == UVSetName) {
							//UVSet�����r���đΉ����Ă���e�N�X�`���Ȃ�ێ�����
							uvSet.textures.push_back(textureName);
						}
					}
				}
				
			}
		}else {//�A�^�b�`�����g���ꂽ�e�N�X�`����FbxFileTexture�̏ꍇ
			//FbxFileTexture:�e�N�X�`�����ꖇ�����g�p���Ȃ��ꍇ
			int fileTextureCount = prop.GetSrcObjectCount<FbxFileTexture>();
			if (fileTextureCount > 0) {
				for (int j = 0; fileTextureCount > j; ++j) {
					FbxFileTexture* texture = prop.GetSrcObject<FbxFileTexture>(j);
					if (texture) {
						//�e�N�X�`�������擾
						std::string textureName = texture->GetRelativeFileName();

						//UVSet�����擾
						std::string UVSetName = texture->UVSet.Get().Buffer();
						if (uvSet.uvSetName == UVSetName) {
							//UVSet�����r���đΉ����Ă���e�N�X�`���Ȃ�ێ�����
							uvSet.textures.push_back(textureName);
						}
					}
				}
			}
		}
	}
}

void FbxFigure::getVertexColor(FbxMesh* fbxMesh) {
	//���_�J���[�Z�b�g�̐����擾
	int colorLayerCount = fbxMesh->GetElementVertexColorCount();
	for (int i = 0; i < colorLayerCount; ++i) {
		FbxGeometryElementVertexColor* color = fbxMesh->GetElementVertexColor(i);

		//--- �}�b�s���O���[�h�̎擾
		FbxGeometryElement::EMappingMode mappingMode = color->GetMappingMode();
		//--- ���t�@�����X���[�h�̎擾 ---//
		FbxGeometryElement::EReferenceMode referenceMode = color->GetReferenceMode();

		//--- �}�b�s���O���[�h�̔��� ---//
		switch (mappingMode) {
		case FbxGeometryElement::eByControlPoint:
			break;
		case FbxGeometryElement::eByPolygon:
			break;
		case FbxGeometryElement::eByPolygonVertex:
			//--- ���t�@�����X���[�h�̔��� ---//
			switch (referenceMode) {
			case FbxGeometryElement::eIndexToDirect:
			{
				FbxLayerElementArrayTemplate<int>* index = &color->GetIndexArray();
				int indexCount = index->GetCount();

				vertexColor = new ColorRGBA[indexCount];

				//--- ���_�̐��������_�J���[���擾 ---//
				for (int j = 0; indexCount > j; j++) {
					vertexColor[j].r = (float)color->GetDirectArray().GetAt(index->GetAt(j))[0];
					vertexColor[j].g = (float)color->GetDirectArray().GetAt(index->GetAt(j))[1];
					vertexColor[j].b = (float)color->GetDirectArray().GetAt(index->GetAt(j))[2];
					vertexColor[j].a = (float)color->GetDirectArray().GetAt(index->GetAt(j))[3];
				}
			}
			break;
			case FbxGeometryElement::eDirect:
				break;
			case FbxGeometryElement::eIndex:
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}


}