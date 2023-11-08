#include "reverseString.h"
import std;

using namespace std;

// A wrapper class for the C reverseString library.
class ReverseString
{
public:
	explicit ReverseString(const string& s)
	{
		char* reversedString{ reverseString(const_cast<char*>(s.c_str())) };
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