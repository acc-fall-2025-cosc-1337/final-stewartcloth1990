#ifndef DIE_H
#define DIE_H

class Die {
public:
	Die() = default;
	// Roll the die and return a value in the range [1, sides]
	int roll();

private:
	// number of sides on the die, default initialized to 6
	int sides{6};
};

#endif // DIE_H
