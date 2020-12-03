#include "Utils.h"

long Utils::getCurrentTimeMs() {
	return chrono::duration_cast<chrono::milliseconds>(
		chrono::system_clock::now().time_since_epoch()
	).count();
}
