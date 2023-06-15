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
	void dontTell() override { println("I'll tell all!"); }
};

int main()
{
	Blabber myBlabber;
	myBlabber.dontTell(); // Outputs "I'll tell all!"
}
