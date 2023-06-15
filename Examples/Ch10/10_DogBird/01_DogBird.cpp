import std;

using namespace std;

class Dog
{
public:
	virtual void bark() { println("Woof!"); }
	virtual void eat() { println("The dog ate."); }
};

class Bird
{
public:
	virtual void chirp() { println("Chirp!"); }
	virtual void eat() { println("The bird ate."); }
};

class DogBird : public Dog, public Bird
{
public:
	//void eat() override
	//{
	//	Dog::eat();          // Explicitly call Dog's version of eat()
	//}

	//using Dog::eat;       // Explicitly inherit Dog's version of eat()
};

int main()
{
	DogBird myConfusedAnimal;

	myConfusedAnimal.bark();
	myConfusedAnimal.chirp();
	//myConfusedAnimal.eat();                   // Error! Ambiguous call to member function eat()
	dynamic_cast<Dog&>(myConfusedAnimal).eat(); // Calls Dog::eat()
	myConfusedAnimal.Dog::eat();                // Calls Dog::eat()
}
