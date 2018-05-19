#include <cstdlib>
#include <ctime>

#include "randomInt.h"
using namespace std;

long randomInt(int range) {
	return rand() % range;
}
