import spreadsheet;

using namespace std;

int main()
{
	Spreadsheet s1 { };
	Spreadsheet s2 { 5, 6 };
	Spreadsheet s3 { s2 };
	s1 = s3;
	s1 = move(s3);
}
