import std;

using namespace std;

int main()
{
	bitset<10> myBitset;

	myBitset.set(3);
	myBitset.set(6);
	myBitset[8] = true;
	myBitset[9] = myBitset[3];

	if (myBitset.test(3)) {
		println("Bit 3 is set!");
	}
	println("{}", myBitset.to_string());
}
