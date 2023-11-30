import std;

using namespace std;

int main()
{
	vector values{ 500.0, 10.0, 2.0 };
	auto foldedLeft{ ranges::fold_left_first(values, divides<>{}) };
	auto foldedRight{ ranges::fold_right_last(values, divides<>{}) };
	println("foldedLeft = {}", foldedLeft.value_or(0.0));
	println("foldedRight = {}", foldedRight.value_or(0.0));
}
