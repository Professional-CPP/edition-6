import std;

using namespace std;

class Animal
{
public:
	virtual void eat() = 0;
};

class Dog : public Animal
{
public:
	virtual void bark() { println("Woof!"); }
	void eat() override { println("The dog ate."); }
};

class Bird : public Animal
{
public:
	virtual void chirp() { println("Chirp!"); }
	void eat() override { println("The bird ate."); }
};

class DogBird : public Dog, public Bird
{
public:
	using Dog::eat;
};

int main()
{
	DogBird myConfusedAnimal;
	myConfusedAnimal.eat();
}
