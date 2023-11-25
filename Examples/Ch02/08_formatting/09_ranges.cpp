import std;

using namespace std;

int main()
{
	vector values{ 11, 22, 33 };
	println("{}", values);         // [11, 22, 33]
	println("{:n}", values);       // 11, 22, 33

	println("{{{:n}}}", values);   // {11, 22, 33}

	println("{:*^16}", values);    // **[11, 22, 33]**
	println("{:*^16n}", values);   // ***11, 22, 33***

	println("{::*^6}", values);    // [**11**, **22**, **33**]

	println("{:n:*^6}", values);   // **11**, **22**, **33**

	vector strings{ "Hello"s, "World!\t2023"s };
	println("{}", strings);        // ["Hello", "World!\t2023"]
	println("{:}", strings);       // ["Hello", "World!\t2023"]
	println("{::}", strings);      // [Hello, World!    2023]
	println("{:n:}", strings);     // Hello, World!    2023

	vector chars{ 'W', 'o', 'r', 'l', 'd', '\t', '!' };
	println("{}", chars);          // ['W', 'o', 'r', 'l', 'd', '\t', '!']
	println("{::#x}", chars);      // [0x57, 0x6f, 0x72, 0x6c, 0x64, 0x9, 0x21]
	println("{:s}", chars);        // World    !
	println("{:?s}", chars);       // "World\t!"

	pair p{ 11, 22 };
	println("{}", p);              // (11, 22)
	println("{:n}", p);            // 11, 22
	println("{:m}", p);            // 11: 22

	vector<vector<int>> vv{ {11, 22}, {33, 44, 55} };
	println("{}", vv);             // [[11, 22], [33, 44, 55]]
	println("{:n}", vv);           // [11, 22], [33, 44, 55]
	println("{:n:n}", vv);         // 11, 22, 33, 44, 55
	println("{:n:n:*^4}", vv);     // *11*, *22*, *33*, *44*, *55*
}
