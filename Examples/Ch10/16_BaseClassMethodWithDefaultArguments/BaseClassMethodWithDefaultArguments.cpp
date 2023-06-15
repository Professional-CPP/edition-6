import std;

using namespace std;

class Base
{
public:
	virtual ~Base() = default;
	virtual void go(int i = 2) { println("Base's go with i={}", i); }
};

class Derived : public Base
{
public:
	void go(int i = 7) override { println("Derived's go with i={}", i); }
};

int main()
{
	Base myBase;
	Derived myDerived;
	Base& myBaseReferenceToDerived{ myDerived };
	myBase.go();
	myDerived.go();
	myBaseReferenceToDerived.go();
}
