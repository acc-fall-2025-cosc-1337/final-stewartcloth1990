#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <random>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

TEST_CASE("POINTPHASE returns point, seven_out, and nopoint outcomes"){

	Die d1;
	Die d2;
	Shooter shooter;

	int test_point = 5;
	PointPhase pointPhase(test_point);

	bool saw_point = false;
	bool saw_seven_out = false;
	bool saw_nopoint = false;

	// Simulate rolls until all outcomes are seen
	for (int i = 0; i < 50; ++i) {
		Roll* roll = shooter.throw_dice(d1, d2);
		RollOutcome outcome = pointPhase.get_outcome(roll);
		
		if(outcome == RollOutcome::point) 
		{	saw_point = true;	}
		else if(outcome == RollOutcome::seven_out) 
		{	saw_seven_out = true;	}
		else if(outcome == RollOutcome::nopoint) 
		{	saw_nopoint = true;	}

		if(saw_point && saw_seven_out && saw_nopoint) {
			break; // Exit early if all outcomes have been seen
		}
	}

	REQUIRE(saw_point);
	REQUIRE(saw_seven_out);
	REQUIRE(saw_nopoint);

}