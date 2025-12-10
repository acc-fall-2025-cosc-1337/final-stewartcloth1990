#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <random>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

static int rollDie() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<int> dist(1, 6);
	return dist(gen);
}

TEST_CASE("Die rolls are between 1 and 6", "[dice]") {
	for (int i = 0; i < 10; ++i) {
		int roll = rollDie();
		REQUIRE(roll >= 1);
		REQUIRE(roll <= 6);
	}
}

TEST_CASE("Two dice sum between 2 and 12", "[dice]") {
	for (int i = 0; i < 10; ++i) {
		int roll = rollDie() + rollDie();
		REQUIRE(roll >= 2);
		REQUIRE(roll <= 12);
	}
}


static int shooter() {
	return rollDie() + rollDie();
}

TEST_CASE("Shooter returns a roll in range 2-12", "[shooter]") {
	for (int i = 0; i < 10; ++i) {
		int result = shooter();
		REQUIRE(result >= 2);
		REQUIRE(result <= 12);
	}
}