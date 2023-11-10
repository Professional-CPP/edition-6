import std;

using namespace std;

class Error
{
public:
	explicit Error(string message) : m_message{ move(message) } { }
	const string& getMessage() const { return m_message; }

private:
	string m_message;
};

expected<vector<int>, Error> getData(bool fail)
{
	if (fail) {
		return unexpected{ Error{ "An error occurred." } };
	} else {
		return vector{ 11, 22, 33 };
	}
}

void handleResult(const expected<vector<int>, Error>& result)
{
	if (!result.has_value()) {
		println("Error: {}", result.error().getMessage());
	} else {
		println("{:n}", result.value());
	}
}

int main()
{
	handleResult(getData(false));
	handleResult(getData(true));
}
