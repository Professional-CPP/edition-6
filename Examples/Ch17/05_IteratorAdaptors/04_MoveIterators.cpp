import std;

using namespace std;

class MoveableClass
{
public:
	MoveableClass() {
		println("Default constructor");
	}
	MoveableClass(const MoveableClass& src) {
		println("Copy constructor");
	}
	MoveableClass(MoveableClass&& src) noexcept {
		println("Move constructor");
	}
	MoveableClass& operator=(const MoveableClass& rhs) {
		println("Copy assignment operator");
		return *this;
	}
	MoveableClass& operator=(MoveableClass&& rhs) noexcept {
		println("Move assignment operator");
		return *this;
	}
};

int main()
{
	vector<MoveableClass> vecSource;
	MoveableClass mc;
	vecSource.push_back(mc);
	vecSource.push_back(mc);
	println("----");

	// Copy the elements from vecSource to vecOne
	vector<MoveableClass> vecOne{ cbegin(vecSource), cend(vecSource) };
	println("----");
	
	// Move the elements from vecSource to vecTwo
	//vector<MoveableClass> vecTwo{ make_move_iterator(begin(vecSource)),
	//						   make_move_iterator(end(vecSource)) };

	// Using class template argument deduction.
	vector<MoveableClass> vecTwo{ move_iterator { begin(vecSource) },
							   move_iterator { end(vecSource) } };

	println("----");
}
