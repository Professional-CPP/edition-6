import std;

const std::string message{ "Test" };

const std::string& getString()
{
	return message;
}

int main()
{
	auto s1{ getString() };
	const auto& s2{ getString() };
	decltype(getString()) s3{ getString() };
	decltype(auto) s4{ getString() };
}
