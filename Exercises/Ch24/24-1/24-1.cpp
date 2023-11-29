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

variant<vector<int>, Error> getData(bool fail)
{
	if (fail) {
		return Error{ "An error occurred." };
	} else {
		return vector{ 11, 22, 33 };
	}
}

void handleResult(const variant<vector<int>, Error>& result)
{
	if (holds_alternative<Error>(result)) {
		println("Error: {}", get<Error>(result).getMessage());
	} else {
		auto& data{ get<vector<int>>(result) };
		println("{:n}", data);
	}
}

int main()
{
	handleResult(getData(false));
	handleResult(getData(true));
}
