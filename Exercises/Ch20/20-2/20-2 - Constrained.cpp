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
	ranges::sort(values);

	// Print initial sorted sequence.
	println("{:n}", values);

	// Loop over all permutations.
	while (ranges::next_permutation(values).found) {
		println("{:n}", values);
	}
}