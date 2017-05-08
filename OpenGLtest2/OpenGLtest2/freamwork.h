#pragma once

namespace GameLib {
	class Freamwork {
	private:
		Freamwork();
		Freamwork(const Freamwork&);
		~Freamwork();

		static Freamwork* mInstance;

		static bool pauseFlag;

	public:
		static void createFreamwork();
		static void destroyFreamwork();
		static Freamwork* instance();

		static void pause();
		static void update();
	};
}