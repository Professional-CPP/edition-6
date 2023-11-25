import std;

using namespace std;

// WRONG IMPLEMENTATION, LOSES VALUE OF WEIGHT.
//	class Animal
//	{
//	public:
//		explicit Animal(double weight) : m_weight{ weight } {}
//		virtual double getWeight() const { return m_weight; }
//	protected:
//		Animal() = default;
//	private:
//		double m_weight{ 0.0 };
//	};
//	
//	class Dog : public virtual Animal
//	{
//	public:
//		explicit Dog(double weight, string name) : Animal{ weight }, m_name{ move(name) } {}
//	private:
//		string m_name;
//	};
//	
//	class Bird : public virtual Animal
//	{
//	public:
//		explicit Bird(double weight, bool canFly) : Animal{ weight }, m_canFly{ canFly } {}
//	private:
//		bool m_canFly{ false };
//	};
//	
//	class DogBird : public Dog, public Bird
//	{
//	public:
//		explicit DogBird(double weight, string name, bool canFly)
//			: Dog{ weight, move(name) }, Bird{ weight, canFly } {}
//	};


// CORRECT IMPLEMENTATION.
class Animal
{
public:
	explicit Animal(double weight) : m_weight{ weight } {}
	virtual double getWeight() const { return m_weight; }
protected:
	Animal() = default;
private:
	double m_weight{ 0.0 };
};

class Dog : public virtual Animal
{
public:
	explicit Dog(double weight, string name) : Animal{ weight }, m_name{ move(name) } {}
protected:
	explicit Dog(string name) : m_name{ move(name) } {}
private:
	string m_name;
};

class Bird : public virtual Animal
{
public:
	explicit Bird(double weight, bool canFly) : Animal{ weight }, m_canFly{ canFly } {}
protected:
	explicit Bird(bool canFly) : m_canFly{ canFly } {}
private:
	bool m_canFly{ false };
};

class DogBird : public Dog, public Bird
{
public:
	explicit DogBird(double weight, string name, bool canFly)
		: Animal { weight }, Dog{ move(name) }, Bird{ canFly } {}
};

int main()
{
	DogBird dogBird{ 22.33, "Bella", true };
	println("Weight: {}", dogBird.getWeight());
}