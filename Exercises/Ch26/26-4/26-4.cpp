import std;

using namespace std;

template<typename T, typename... Args>
void push_back_values(vector<T>& values, Args&&... args)
{
	(values.push_back(std::forward<Args>(args)), ...);
}

template<typename T, typename... Args>
void insert_values(vector<T>& values, Args&&... args)
{
	values.insert(end(values), { std::forward<Args>(args)... });
}


int main()
{
	vector<int> values1;
	push_back_values(values1, 9, 8, 7, 6);
	println("{:n}", values1);

	vector<double> values2;
	push_back_values(values2, 1.1, 2, 3.3, 4);
	/// The difference with push_back_values() is that for insert_values()
	/// all second to last argument types must be of the exact type stored
	/// in the vector, double in this example.
	insert_values(values2, 11.1, 22.2, 33.3, 44.4);
	println("{:n}", values2);

	vector<string> values3;
	push_back_values(values3, "Hello", "World", "!");
	println("{:n}", values3);
}