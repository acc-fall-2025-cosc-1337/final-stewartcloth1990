#include "die.h"
#include <cstdlib>
#include <ctime>

int Die::roll() {
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		seeded = true;
	}
	return (std::rand() % sides) + 1;
}

//