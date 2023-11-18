import std;

using namespace std;

template <input_iterator Iter, copy_constructible StartValue,
	invocable<const StartValue&, const StartValue&> Operation>
auto accumulateData(Iter begin, Iter end, const StartValue& startValue, Operation op)
{
	auto accumulated{ startValue };
	for (Iter iter{ begin }; iter != end; ++iter) {
		accumulated = op(accumulated, *iter);
	}
	return accumulated;
}

bool allTrue(const vector<bool>& flags)
{
	return accumulateData(begin(flags), end(flags), true, logical_and<>{});
}

bool anyTrue(const vector<bool>& flags)
{
	return accumulateData(begin(flags), end(flags), false, logical_or<>{});
}

int main()
{
	vector<bool> myVector;
	while (true) {
		print("Enter a value 0 or 1 to add (-1 to stop): ");
		int value;
		cin >> value;
		if (value == -1) {
			break;
		}
		myVector.push_back(value == 1);
	}

	println("allTrue? {}", allTrue(myVector));
	println("anyTrue? {}", anyTrue(myVector));
}
