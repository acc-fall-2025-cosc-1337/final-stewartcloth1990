#ifndef ROLL_H
#define ROLL_H

class Die; // forward declaration

class Roll {
public:
    Roll(Die& die1, Die& die2);
    void roll_dice();
    int roll_value() const;

private:
    Die& die1;
    Die& die2;
    int rolled_value;
};

#endif // ROLL_H