import std;

using namespace std;

// Forward declarations.
class Bear;
class Fish;
class TRex;

class Animal
{
public:
	virtual bool eats(const Bear&) const = 0;
	virtual bool eats(const Fish&) const = 0;
	virtual bool eats(const TRex&) const = 0;
};

class Bear : public Animal
{
public:
	bool eats(const Bear&) const override { return false; }
	bool eats(const Fish&) const override { return true; }
	bool eats(const TRex&) const override { return false; }
};

class Fish : public Animal
{
public:
	bool eats(const Bear&) const override { return false; }
	bool eats(const Fish&) const override { return true; }
	bool eats(const TRex&) const override { return false; }
};

class TRex : public Animal
{
public:
	bool eats(const Bear&) const override { return true; }
	bool eats(const Fish&) const override { return true; }
	bool eats(const TRex&) const override { return true; }
};

int main()
{
	Bear myBear;
	Fish myFish;
	println("Bear eats fish? {}", myBear.eats(myFish));

	{
		Animal& animalRef{ myBear };
		println("Bear eats fish? {}", animalRef.eats(myFish));
	}

	{
		Animal& animalRef{ myFish };
		//println("Bear eats fish? {}", myBear.eats(animalRef)); // BUG! No member function Bear::eats(Animal&)
	}
}
