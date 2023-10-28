import std;

using namespace std;

class Calculator
{
public:
	explicit Calculator(int a, int b) : m_a{ a }, m_b{ b } {}
	void operator()() { result = m_a * m_b; }
	int getResult() const { return result; }
private:
	int m_a{ 0 };
	int m_b{ 0 };
	int result{ 0 };
};

int main()
{
	Calculator calculator{ 21, 2 };
	jthread job{ ref(calculator) };
	job.join();
	println("21*2 = {}", calculator.getResult());
}
