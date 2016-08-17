#pragma once
#include "object.h"
#include <functional>

//モデルデータをもつオブジェクトのうち、動くものを管理するクラス
class Character :public Object {//アクセス指定子を明示する
protected:
	//何らかのアクションを子クラス(具体的なキャラクラス)で実装しactionに格納する
	std::function<void()> action;
public:
	Character() {}
	Character(float pX, float pY, float pZ, std::string modelName);//継承元のコンストラクタを呼ぶ


	void rotate(float angle, float x, float y, float z);
	void translate(float x, float y, float z);

	//キャラクターがアクションする関数
	void actionStart();
	void actionFinish();
	
};