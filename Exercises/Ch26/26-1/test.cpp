import key_value_pair;
import std;

using namespace std;

int main()
{
	KeyValuePair<int, double> kv1{ 11, 2.33 };
	println("{} = {}", kv1.getKey(), kv1.getValue());

	KeyValuePair kv2{ "John Doe"s, 123456 };
	println("{} = {}", kv2.getKey(), kv2.getValue());

	KeyValuePair<int, const char*> kv3{ 123, "New York" };
	println("{} = {}", kv3.getKey(), kv3.getValue());
}
