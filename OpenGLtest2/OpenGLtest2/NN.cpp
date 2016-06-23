#include <Vector>
using namespace std;

	class NeuralNet {
	private:
		vector<int> x;
		vector<float> y;
		vector<vector<float>> h;

		float activatefunc(float x, float alpha) {
			return x > 0 ? x : alpha*x; //�������֐�RReLU
		}


	public:
		NeuralNet(int input, int output, int hidden, int layer) {
			x.resize(input);		//���͑w�̎�����
			y.resize(output);		//�o�͑w�̎�����
			h.resize(layer-2);		//�B��w�̃��C���[��
			for (int i = 0; i <layer-2;i++) {
				h[i].resize(hidden);	//���ꂼ��̉B��w�̎�����
			}
		}

		void learning() {

		}

	};