#include "Utils.h"

long Utils::getCurrentTimeMs() {
	return duration_cast<milliseconds>(
		system_clock::now().time_since_epoch()
	).count();
}
