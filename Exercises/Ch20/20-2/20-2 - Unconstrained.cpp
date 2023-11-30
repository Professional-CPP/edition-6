import std;

using namespace std;

int main()
{
	vector<int> values;
	while (true) {
		print("Enter a number to add (0 to stop): ");
		int number;
		cin >> number;
		if (number == 0) {
			break;
		}
		values.push_back(number);
	}

	// The permutation algorithms require the sequence to be sorted.
	sort(begin(values), end(values));

	// Print initial sorted sequence.
	println("{:n}", values);

	// Loop over all permutations.
	while (next_permutation(begin(values), end(values))) {
		println("{:n}", values);
	}
}