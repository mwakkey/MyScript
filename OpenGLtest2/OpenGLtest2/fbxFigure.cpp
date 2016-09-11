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
	FbxVector4* vertexAry = fbxMesh->GetControlPoints();	//メッシュに含まれる頂点座標の配列(double)
	vertexBuffer = new Vertex[vertexCount];
	for (int i = 0; i < vertexCount; ++i) {
		vertexBuffer[i].x = (float)vertexAry[i][0];	//x座標をfloatにキャスト
		vertexBuffer[i].y = (float)vertexAry[i][1];	//y座標をfloatにキャスト
		vertexBuffer[i].z = (float)vertexAry[i][2];	//z座標をfloatにキャスト
	}
	delete(vertexAry);	//バッファにデータを格納したらデリートする

	int* indexAry = fbxMesh->GetPolygonVertices();	//全ポリゴン頂点のインデックス配列
	indexBuffer = new int[indexCount];
	for (int i = 0; i < indexCount; ++i) {
		indexBuffer[i] = indexAry[i];
	}
	delete(indexAry);	//バッファにデータを格納したらデリートする

}

void FbxFigure::getNormal(FbxMesh* fbxMesh) {
	normalLayerCount = fbxMesh->GetElementNormalCount();

	for (int i = 0; i < normalLayerCount; ++i) {
		//指定レイヤーの法線セットを取得
		FbxGeometryElementNormal* normal = fbxMesh->GetElementNormal(i);

		//マッピングモードの取得(eByControlPointのときはインデックスバッファを使用)
		//メッシュに関する定義
		FbxGeometryElement::EMappingMode mapping = normal->GetMappingMode();
		//リファレンスモードの取得
		//データの格納方法に関する定義
		FbxGeometryElement::EReferenceMode reference = normal->GetReferenceMode();

		//--- マッピングモードの判別 ---//
		switch (mapping) {
		case FbxGeometryElement::eByControlPoint:
			//--- リファレンスモードの判別 ---//
			switch (reference) {
			case FbxGeometryElement::eDirect:
			{
				//--- 法線数を取得 ---//
				int normalCount = normal->GetDirectArray().GetCount();

				//-----------------------------------------------------------------------
				// eDirect の場合データは順番に格納されているのでそのまま保持
				//-----------------------------------------------------------------------
				for (int i = 0; normalCount > i; i++) {
					//--- 法線の取得 ---//
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
	//UVセットの数を取得
	int UVLayerCount = fbxMesh->GetElementUVCount();
	for (int i = 0; i < UVLayerCount; ++i) {
		//UVバッファを取得
		FbxGeometryElementUV* UV = fbxMesh->GetElementUV(i);
		//--- マッピングモードの取得
		FbxGeometryElement::EMappingMode mapping = UV->GetMappingMode();
		//--- リファレンスモードの取得 ---//
		FbxGeometryElement::EReferenceMode reference = UV->GetReferenceMode();

		//--- UV数を取得 ---//
		int uvCount = UV->GetDirectArray().GetCount();

		//--- マッピングモードの判別 ---//
		switch (mapping) {
		case FbxGeometryElement::eByControlPoint:
			break;

		case FbxGeometryElement::eByPolygonVertex:
			//--- リファレンスモードの判別 ---//
			switch (reference) {
			case FbxGeometryElement::eDirect:
				break;
			case FbxGeometryElement::eIndexToDirect:
			{
				FbxLayerElementArrayTemplate<int>* uvIndex = &UV->GetIndexArray();
				int uvIndexCount = uvIndex->GetCount();

				//--- UVを保持 ---// 
				Point2 temp;
				for (int i = 0; uvIndexCount > i; i++) {

					temp.x = (float)UV->GetDirectArray().GetAt(uvIndex->GetAt(i))[0];

					temp.y = 1.0f - (float)UV->GetDirectArray().GetAt(uvIndex->GetAt(i))[1];

					uvSet.uvBuffer.push_back(temp);
				}

				//--- UVSet名を取得 ---//
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
		//属性を検索(sDiffuse,sSpecular,sBump,sNormalMap等)
		FbxProperty prop = material->FindProperty(FbxSurfaceMaterial::sDiffuse);
		//プロパティにアタッチされたテクスチャの種類を判別
		//FbxLayeredTexture,FbxFileTexture,FbxProceduralTexture

		//FbxLayeredTexture:複数のテクスチャをブレンド使用する場合
		int layeredTextureCount = prop.GetSrcObjectCount<FbxLayeredTexture>();
		//アタッチされたテクスチャがFbxLayeredTextureの場合
		if (layeredTextureCount > 0) {
			for (int j = 0; j < layeredTextureCount; ++j) {
				FbxLayeredTexture* layeredTexture = prop.GetSrcObject<FbxLayeredTexture>(j);
				int textureCount = layeredTexture->GetSrcObjectCount<FbxFileTexture>();

				for (int k = 0; textureCount > k; k++) {
					FbxFileTexture* texture = prop.GetSrcObject<FbxFileTexture>(k);

					if (texture) {
						std::string textureName = texture->GetRelativeFileName();
	
						//UVSet名を取得
						std::string UVSetName = texture->UVSet.Get().Buffer();
						if (uvSet.uvSetName == UVSetName) {
							//UVSet名を比較して対応しているテクスチャなら保持する
							uvSet.textures.push_back(textureName);
						}
					}
				}
				
			}
		}else {//アタッチメントされたテクスチャがFbxFileTextureの場合
			//FbxFileTexture:テクスチャを一枚しか使用しない場合
			int fileTextureCount = prop.GetSrcObjectCount<FbxFileTexture>();
			if (fileTextureCount > 0) {
				for (int j = 0; fileTextureCount > j; ++j) {
					FbxFileTexture* texture = prop.GetSrcObject<FbxFileTexture>(j);
					if (texture) {
						//テクスチャ名を取得
						std::string textureName = texture->GetRelativeFileName();

						//UVSet名を取得
						std::string UVSetName = texture->UVSet.Get().Buffer();
						if (uvSet.uvSetName == UVSetName) {
							//UVSet名を比較して対応しているテクスチャなら保持する
							uvSet.textures.push_back(textureName);
						}
					}
				}
			}
		}
	}
}

void FbxFigure::getVertexColor(FbxMesh* fbxMesh) {
	//頂点カラーセットの数を取得
	int colorLayerCount = fbxMesh->GetElementVertexColorCount();
	for (int i = 0; i < colorLayerCount; ++i) {
		FbxGeometryElementVertexColor* color = fbxMesh->GetElementVertexColor(i);

		//--- マッピングモードの取得
		FbxGeometryElement::EMappingMode mappingMode = color->GetMappingMode();
		//--- リファレンスモードの取得 ---//
		FbxGeometryElement::EReferenceMode referenceMode = color->GetReferenceMode();

		//--- マッピングモードの判別 ---//
		switch (mappingMode) {
		case FbxGeometryElement::eByControlPoint:
			break;
		case FbxGeometryElement::eByPolygon:
			break;
		case FbxGeometryElement::eByPolygonVertex:
			//--- リファレンスモードの判別 ---//
			switch (referenceMode) {
			case FbxGeometryElement::eIndexToDirect:
			{
				FbxLayerElementArrayTemplate<int>* index = &color->GetIndexArray();
				int indexCount = index->GetCount();

				vertexColor = new ColorRGBA[indexCount];

				//--- 頂点の数だけ頂点カラーを取得 ---//
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