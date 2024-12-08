#include "reverseString.h"
#include <print>
#include <memory>
#include <string>

using namespace std;

// A wrapper class for the C reverseString library.
class ReverseString
{
public:
	explicit ReverseString(const string& s)
	{
		unique_ptr<char[], decltype(&freeString)> reversedString{
			reverseString(s.c_str()),
			freeString };
		m_reversedString = reversedString.get();
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