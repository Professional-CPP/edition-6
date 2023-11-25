import std;

using namespace std;

class Matrix
{
public:
	Matrix() = default; // Implicitly constexpr

	constexpr explicit Matrix(unsigned rows, unsigned columns)
		: m_rows{ rows }, m_columns{ columns }
	{
	}

	constexpr unsigned getSize() const
	{
		return m_rows * m_columns;
	}

private:
	unsigned m_rows{ 0 }, m_columns{ 0 };
};


int main()
{
	constexpr Matrix matrix{ 8, 2 };
	int linearizedMatrix[matrix.getSize()];
	println("Size of linearizedMatrix = {}", size(linearizedMatrix));

	constexpr Matrix matrixDefault;
}