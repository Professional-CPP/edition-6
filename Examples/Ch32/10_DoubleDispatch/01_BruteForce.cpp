import std;

using namespace std;

class Animal
{
public:
	virtual bool eats(const Animal& prey) const = 0;
};

class Bear : public Animal
{
public:
	bool eats(const Animal& prey) const override;
};

class Fish : public Animal
{
public:
	bool eats(const Animal& prey) const override;
};

class TRex : public Animal
{
public:
	bool eats(const Animal& prey) const override;
};

bool Bear::eats(const Animal& prey) const
{
	if (typeid(prey) == typeid(Bear)) { return false; }
	else if (typeid(prey) == typeid(Fish)) { return true; }
	else if (typeid(prey) == typeid(TRex)) { return false; }
	return false;
}

bool Fish::eats(const Animal& prey) const
{
	if (typeid(prey) == typeid(Bear)) { return false; }
	else if (typeid(prey) == typeid(Fish)) { return true; }
	else if (typeid(prey) == typeid(TRex)) { return false; }
	return false;
}

bool TRex::eats(const Animal& /*prey*/) const
{
	return true;
} 

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
