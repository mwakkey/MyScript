#pragma once

namespace GameLib {
	class Freamwork {
	private:
		Freamwork();
		Freamwork(const Freamwork&);
		~Freamwork();

		static Freamwork* mInstance;

	public:
		static void createFreamwork();
		static void destroyFreamwork();
		static Freamwork* instance();

		static void update();
	};
}