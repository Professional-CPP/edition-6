import std;

using namespace std;

class Secret
{
protected:
	virtual void dontTell() { println("I'll never tell."); }
};

class Blabber : public Secret
{
public:
	using Secret::dontTell;
};

int main()
{
	Blabber myBlabber;
	myBlabber.dontTell(); // Outputs "I'll never tell."

	Secret& ref{ myBlabber };
	Secret* ptr{ &myBlabber };
	//ref.dontTell();  // Error! Attempt to access protected member function.
	//ptr->dontTell(); // Error! Attempt to access protected member function.
}
