#include "reverseString.h"
import std;

using namespace std;

// A wrapper class for the C reverseString library.
class ReverseString
{
public:
	ReverseString(string_view s)
	{
		char* reversedString{ reverseString(const_cast<char*>(s.data())) };
		m_reversedString = reversedString;
		freeString(reversedString);
	}

	const string& getReversedString() const
	{
		return m_reversedString;
	}

private:
	string m_reversedString;
};



int main()
{
	ReverseString reverser{ "Hello World!" };

	println("{}", reverser.getReversedString());
}