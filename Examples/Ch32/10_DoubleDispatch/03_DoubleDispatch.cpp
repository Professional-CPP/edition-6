import std;

using namespace std;

// Forward declarations.
class Fish;
class Bear;
class TRex;

class Animal
{
public:
	virtual bool eats(const Animal& prey) const = 0;

	virtual bool eatenBy(const Bear&) const = 0;
	virtual bool eatenBy(const Fish&) const = 0;
	virtual bool eatenBy(const TRex&) const = 0;
};

class Bear : public Animal
{
public:
	bool eats(const Animal& prey) const override { return prey.eatenBy(*this); }

	bool eatenBy(const Bear&) const override { return false; }
	bool eatenBy(const Fish&) const override { return false; }
	bool eatenBy(const TRex&) const override { return true; }
};

class Fish : public Animal
{
public:
	bool eats(const Animal& prey) const override { return prey.eatenBy(*this); }

	bool eatenBy(const Bear&) const override { return true; }
	bool eatenBy(const Fish&) const override { return true; }
	bool eatenBy(const TRex&) const override { return true; }
};

class TRex : public Animal
{
public:
	bool eats(const Animal& prey) const override { return prey.eatenBy(*this); }

	bool eatenBy(const Bear&) const override { return false; }
	bool eatenBy(const Fish&) const override { return false; }
	bool eatenBy(const TRex&) const override { return true; }
};


int main()
{
	Fish myFish;
	Bear myBear;
	TRex myDino;

	println("Fish eats bear? {}", myFish.eats(myBear));
	println("Fish eats dino? {}", myFish.eats(myDino));
	println("Dino eats bear? {}", myDino.eats(myBear));
	println("Bear eats fish? {}", myBear.eats(myFish));
}
