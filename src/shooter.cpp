#include "shooter.h"
#include "roll.h"
#include "die.h"
#include <iostream>


Roll* Shooter::throw_dice(Die& die1, Die& die2) {
    Roll* r = new Roll(die1, die2);
    r->roll_dice();
    rolls.push_back(r);
    return r;
}

void Shooter::display_rolled_values() const {
    for (const Roll* r : rolls) {
        if (r) std::cout << r->roll_value() << '\n';
    }
}

Shooter::~Shooter() {
    for (Roll* r : rolls) {
        delete r;
    }
    rolls.clear();
}