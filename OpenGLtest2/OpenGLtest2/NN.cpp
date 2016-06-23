#include <Vector>
using namespace std;

	class NeuralNet {
	private:
		vector<int> x;
		vector<float> y;
		vector<vector<float>> h;

		float activatefunc(float x, float alpha) {
			return x > 0 ? x : alpha*x; //活性化関数RReLU
		}


	public:
		NeuralNet(int input, int output, int hidden, int layer) {
			x.resize(input);		//入力層の次元数
			y.resize(output);		//出力層の次元数
			h.resize(layer-2);		//隠れ層のレイヤー数
			for (int i = 0; i <layer-2;i++) {
				h[i].resize(hidden);	//それぞれの隠れ層の次元数
			}
		}

		void learning() {

		}

	};