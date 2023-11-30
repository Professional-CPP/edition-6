import std;

using namespace std;

int main()
{
	locale userLocale{ "" };
	auto& facet{ use_facet<numpunct<char>>(userLocale) };
	println("Decimal separator: {}", facet.decimal_point());
}