import std;

using namespace std;

int main()
{
	vector<string> stringVector(10, "hello");
	for (auto iter{ cbegin(stringVector) }; iter != cend(stringVector); ++iter) {
		println("{}", *iter);
	}
	
	for (const auto& element : stringVector) {
		println("{}", element);
	}
}
