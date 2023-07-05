import std;

using namespace std;

class Gregarious
{
public:
	virtual void talk() { println("Gregarious says hi!"); }
};

class Shy : public Gregarious
{
protected:
	void talk() override { println("Shy reluctantly says hello."); }
};

int main()
{
	{
		Shy myShy;
		//myShy.talk();  // Error! Attempt to access protected member function.
	}

	{
		Shy myShy;
		Gregarious& ref{ myShy };
		ref.talk();
	}
}
