import std;

using namespace std;

class Animal
{
public:
	virtual void eat() = 0;
	virtual void sleep() { println("zzzzz...."); }
};

class Dog : public virtual Animal
{
public:
	virtual void bark() { println("Woof!"); }
	void eat() override { println("The dog ate."); }
};

class Bird : public virtual Animal
{
public:
	virtual void chirp() { println("Chirp!"); }
	void eat() override { println("The bird ate."); }
};

class DogBird : public Dog, public Bird
{
public:
	void eat() override { Dog::eat(); }
};

int main()
{
	DogBird myConfusedAnimal;
	myConfusedAnimal.sleep();  // Not ambiguous because of virtual base class
}
