import std;

using namespace std;

class BaseStatic
{
public:
	static void beStatic() {
		println("BaseStatic being static.");
	}
};

class DerivedStatic : public BaseStatic
{
public:
	static void beStatic() {
		println("DerivedStatic keepin' it static.");
	}
};

int main()
{
	{
		BaseStatic::beStatic();
		DerivedStatic::beStatic();
	}

	{
		DerivedStatic myDerivedStatic;
		BaseStatic& ref{ myDerivedStatic };
		myDerivedStatic.beStatic();
		ref.beStatic();
	}
}
