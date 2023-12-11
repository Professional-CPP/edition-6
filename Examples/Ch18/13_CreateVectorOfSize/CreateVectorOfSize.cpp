import std;

using namespace std;

vector<int> createVectorOfSize(size_t size)
{
	vector<int> vec(size);
	for (int contents{ 0 }; auto& i : vec) { i = contents++; }
	return vec;
}

int main()
{
	vector<int> myVector;
	myVector = createVectorOfSize(123);
}
