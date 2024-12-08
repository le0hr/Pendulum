#include <iostream>
#include <cmath>

using namespace std;

namespace pendul {
	class Pendulum
	{
	public:
		int len;
		int Amplitude;
		int gravity = 9.8;
		int radius = 5;

		pair<int, int> move(int dt) {
			return make_pair( static_cast<int>(Amplitude * cos(sqrt(gravity) * dt / sqrt(len))), static_cast<int>(sqrt(len * len - pow(Amplitude * cos(sqrt(gravity) * dt / sqrt(len)), 2))) );
		}
	};


}