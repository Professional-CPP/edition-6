import std;

using namespace std;

int main()
{
	vector vectorOne{ 1, 2, 3, 5 };
	vector<int> vectorTwo;
	println("{:n}", vectorOne);

	// Oops, we forgot to add 4. Insert it in the correct place.
	vectorOne.insert(cbegin(vectorOne) + 3, 4);

	// Add elements 6 through 10 to vectorTwo.
	for (int i{ 6 }; i <= 10; ++i) {
		vectorTwo.push_back(i);
	}

	println("{:n}", vectorOne);
	println("{:n}", vectorTwo);

	// Add all elements from vectorTwo to the end of vectorOne.
	vectorOne.insert(cend(vectorOne), cbegin(vectorTwo), cend(vectorTwo));
	println("{:n}", vectorOne);

	// Add all vectorTwo elements to the end of vectorOne using C++23 append_range().
	// Note how much clearer this is compared to the previous call to insert().
	vectorOne.append_range(vectorTwo);
	println("{:n}", vectorOne);

	// Now erase the numbers 2 through 5 in vectorOne.
	vectorOne.erase(cbegin(vectorOne) + 1, cbegin(vectorOne) + 5);
	println("{:n}", vectorOne);

	// Clear vectorTwo entirely.
	vectorTwo.clear();

	// And add 10 copies of the value 100.
	vectorTwo.insert(cbegin(vectorTwo), 10, 100);
	println("{:n}", vectorTwo);

	// Decide we only want 9 elements.
	vectorTwo.pop_back();
	println("{:n}", vectorTwo);
}
