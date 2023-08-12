import std;

using namespace std;

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int callCount{ 0 };

	auto count{ ranges::count_if(values,
		[&callCount](int value) {
			++callCount; 
			return value % 2 == 0;
		})
	};

	println("There are {} even elements in the vector.", count);
	println("Lambda was called {} times.", callCount);
}