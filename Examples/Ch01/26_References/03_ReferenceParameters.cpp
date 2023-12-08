void addOneA(int i)
{
	i++;  // Has no real effect because this is a copy of the original
}

void addOneB(int& i)
{
	i++;  // Actually changes the original variable
}

void swap(int& first, int& second)
{
	int temp{ first };
	first = second;
	second = temp;
}

int main()
{
	int myInt{ 7 };
	addOneA(myInt);
	addOneB(myInt);



	int x{ 5 }, y{ 6 };
	swap(x, y);

	//  swap(3, 4); // DOES NOT COMPILE

	int* xp{ &x }, * yp{ &y };
	swap(*xp, *yp);
}
