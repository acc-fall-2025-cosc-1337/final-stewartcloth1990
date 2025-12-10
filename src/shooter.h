// File: src/shooter.h
#ifndef SHOOTER_H
#define SHOOTER_H

#include <vector>

class Roll;
class Die;

class Shooter {
public:
    Shooter() = default;
    Roll* throw_dice(Die& die1, Die& die2);
    void display_rolled_values() const;
    ~Shooter();

private:
    std::vector<Roll*> rolls;
};

#endif // SHOOTER_H