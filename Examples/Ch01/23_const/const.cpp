import std;

const int versionNumberMajor{ 2 };
const int versionNumberMinor{ 1 };
const std::string productName{ "Super Hyper Net Modulator" };
const double PI{ 3.141592653589793238462 };

void func(const int /*param*/)
{
	// Not allowed to change param...
}

void constIntOne()
{
	const int* ip;
	ip = new int[10];
	//  ip[4] = 5; // DOES NOT COMPILE!
}

void constIntTwo()
{
	int const* ip;
	ip = new int[10];
	//  ip[4] = 5; // DOES NOT COMPILE!
}

void constPtrOne()
{
	int* const ip{ nullptr };
	//  ip = new int[10]; // DOES NOT COMPILE!
	ip[4] = 5;	// Error: dereferencing a null pointer
}

void constPtrTwo()
{
	int* const ip{ new int[10] };
	ip[4] = 5;
}

void constIntPtrOne()
{
	int const* const ip{ nullptr };
}

void constIntPtrTwo()
{
	const int* const ip{ nullptr };
}

void manyLevelConst()
{
	const int* const* const* const ip{ nullptr };
}

int main()
{
	int* ip;
	ip = new int[10];
	ip[4] = 5;
}
