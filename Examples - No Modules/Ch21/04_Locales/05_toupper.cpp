#include <locale>
#include <cctype>

using namespace std;

int main()
{
	auto upper{ toupper(L'é', locale{ "fr-FR" }) };  // É
}
