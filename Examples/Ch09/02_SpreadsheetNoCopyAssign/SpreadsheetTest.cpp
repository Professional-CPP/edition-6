import spreadsheet;

void printSpreadsheet(Spreadsheet s)
{
	// code omitted for brevity
}

int main()
{
	{
		Spreadsheet s1{ 4, 3 };
		printSpreadsheet(s1);
	}

	{
		Spreadsheet s1{ 2, 2 }, s2{ 4, 3 };
		s1 = s2;
	}
}
