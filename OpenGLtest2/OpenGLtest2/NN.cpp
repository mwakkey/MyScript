#include <Vector>
using namespace std;

	class NeuralNet {
	private:
		vector<int> x;
		vector<float> y;
		vector<vector<float>> h;

		float activatefunc(float x, float alpha) {
			return x > 0 ? x : alpha*x; //Šˆ«‰»ŠÖ”RReLU
		}


	public:
		NeuralNet(int input, int output, int hidden, int layer) {
			x.resize(input);		//“ü—Í‘w‚ÌŸŒ³”
			y.resize(output);		//o—Í‘w‚ÌŸŒ³”
			h.resize(layer-2);		//‰B‚ê‘w‚ÌƒŒƒCƒ„[”
			for (int i = 0; i <layer-2;i++) {
				h[i].resize(hidden);	//‚»‚ê‚¼‚ê‚Ì‰B‚ê‘w‚ÌŸŒ³”
			}
		}

		void learning() {

		}

	};