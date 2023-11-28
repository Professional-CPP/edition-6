import std;

using namespace std;
using namespace std::chrono;

int getNumberOfDaysBetweenDates(const sys_days& date1, const sys_days& date2)
{
	return (date2 - date1).count();
}

int main()
{
	// Set the global locale to the user's local (see Chapter 21).
	locale::global(locale{ "" });

	auto date1{ 2019y / June / 22d };
	auto date2{ 2020y / June / 22d };
	println("The number of days between {:L} and {:L} is {}.",
		date1, date2, getNumberOfDaysBetweenDates(date1, date2));
}
