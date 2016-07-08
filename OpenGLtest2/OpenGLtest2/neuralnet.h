#pragma once

#include <vector>

class NeuralNet
{
private:
	std::vector<float> inLayer;
	std::vector<float> outLayer;
	std::vector<std::vector<float>> hidLayer;
	std::vector<std::vector<std::vector<float>>> weight;

	float activateFunc(float x, float alpha);
	void backpropagation();
	//データ入力
	//各層について
	//	z=0
	//	その層の各ニューロンについて
	//		その層が出力層でなければ
	//			次の層の各ニューロンについて(初期値b)
	//				+=現在の層のニューロンの活性：(現在層の出力活性*ニューロン間の重み)
	//%%出力層に到達する
	//for i=0;出力層のニューロン数まで
	//	delta[i]=(そのニューロンの活性導関数を出力値に適用したもの)*(そのニューロンの出力-教師情報)
	//for 前の各層について
	//	for i=0;その層のニューロン数-1まで
	//		unit=その層のi番目のニューロン
	//		b(_unit) = b - trainingRate * delta[i]
	//	その層が入力層でなければ
	//		for j=0;一つ前の層のニューロン数-1まで
	//			unit=一つ前の層のj番目のニューロン
	//			for k=0;今の層のニューロン数-1まで
	//				sigma = sigma+delta[k]*(ニューロンjからkへの重み)
	//			delta[j] = ニューロンjの活性導関数*sigma
	//			(ニューロンjからiへの重み) = (ニューロンjからiへの重み)-trainingRate*delta[j]*一つ前の層の活性

public:
	NeuralNet(int input, int output, int hidden, int layer);

	void learning();

};