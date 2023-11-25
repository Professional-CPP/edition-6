import std;

using namespace std;

class Animal { public: virtual ~Animal() = default; };
class Dog : public Animal {};
class Bird : public Animal {};

void speak(const Animal& animal)
{
	if (typeid(animal) == typeid(Dog)) {
		println("Woof!");
	} else if (typeid(animal) == typeid(Bird)) {
		println("Chirp!");
	}
}

int main()
{
	speak(Dog{});
	speak(Bird{});
}
