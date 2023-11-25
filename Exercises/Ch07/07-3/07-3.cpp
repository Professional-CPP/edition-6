import std;

using namespace std;

class Point
{
public:
	Point(double x, double y, double z)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{
	}

	double getX() const { return m_x; }
	double getY() const { return m_y; }
	double getZ() const { return m_z; }

private:
	double m_x;
	double m_y;
	double m_z;
};

//// Note: This function is only an observer of the given point.
////       It does not take ownership of the point, hence using
////       shared_ptr as the type for the parameter makes no sense.
////       A reference-to-const is recommended for this function.
void printPoint(const Point& point)
{
	print("{:g}, {:g}, {:g}",
		point.getX(), point.getY(), point.getZ());
}

int main()
{
	//// Use make_unique() to create a unique_ptr to store a
	//// dynamically allocated Point instance.
	//// Don't use a raw pointer.
	//// You could use shared_ptr, but since we don't need
	//// shared ownership in this program, unique_ptr is
	//// the recommended solution.
	auto point{ make_unique<Point>(1.2, 2.3, 4.5) };
	printPoint(*point);
}
