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
	virtual void tell() { dontTell(); }
};

int main()
{
	Blabber myBlabber;
	myBlabber.tell(); // Outputs "I'll never tell."
}
