import std;

using namespace std;
using namespace std::chrono;

int main()
{
	// Set the global locale to the user's local (see Chapter 21).
	locale::global(locale{ "" });



	year y1{ 2020 };
	auto y2{ 2020y };

	month m1{ 6 };
	auto m2{ June };

	day d1{ 22 };
	auto d2{ 22d };

	// Create a date for 2020-06-22.
	year_month_day fulldate1{ 2020y, June, 22d };
	auto fulldate2{ 2020y / June / 22d };
	auto fulldate3{ 22d / June / 2020y };

	// Create a date for the 3rd Monday of June 2020.
	year_month_day fulldate4{ Monday[3] / June / 2020 };

	// Create a month_day for June 22 of an unspecified year.
	auto june22{ June / 22d };
	// Create a year_month_day for June 22, 2020.
	auto june22_2020{ 2020y / june22 };

	// Create a month_day_last for the last day of a June of an unspecified year.
	auto lastDayOfAJune{ June / last };
	// Create a year_month_day_last for the last day of June for the year 2020.
	auto lastDayOfJune2020{ 2020y / lastDayOfAJune };

	// Create a year_month_weekday_last for the last Monday of June 2020.
	auto lastMondayOfJune2020{ 2020y / June / Monday[last] };



	// Get today as sys_days.
	auto today{ floor<days>(system_clock::now()) };

	// Convert date to time_point.
	system_clock::time_point t1{ sys_days{2020y / June / 22d } };

	// Convert time_point to date.
	year_month_day yearmonthday{ floor<days>(t1) };
	year_month_day today2{ floor<days>(system_clock::now()) };



	// Full date with time: 2020-06-22 09:35:10 UTC.
	auto t2{ sys_days{ 2020y / June / 22d } + 9h + 35min + 10s };



	// Output to streams is supported.
	cout << yearmonthday << endl;
	// println() / print() / format() / ... are supported.
	println("{:L}", yearmonthday);

	println("{:L}", lastMondayOfJune2020);
	year_month_day lastMondayOfJune2020YMD{ sys_days{ lastMondayOfJune2020 } };
	println("{:L}", lastMondayOfJune2020YMD);

	locale::global(locale{ "nl-NL" });
	println("Monday in Dutch is {:L%A}", Monday);



	// Arithmetic with dates.
	// Add 5 days to t2.
	auto t3{ t2 + days{ 5 } };
	// Add 1 year to t3.
	auto t4{ t3 + years{ 1 } };

	// Careful with arithmetic and serial types!
	auto t5{ sys_days { 2020y / June / 22d } + 9h + 35min + 10s };
	auto t6{ t5 + years { 1 } };   // Add 1 year to t5
	println("t5 = {:L}", t5);        // 2020-06-22 09:35:10
	println("t6 = {:L}", t6);        // 2021-06-22 15:24:22

	// Arithmetic and field-based types.
	// Split t5 into days and remaining seconds.
	sys_days t5_days{ time_point_cast<days>(t5) };
	seconds t5_seconds{ t5 - t5_days };
	// Convert the t5_days serial type to field-based type.
	year_month_day t5_ymd{ t5_days };
	// Add 1 year.
	year_month_day t7_ymd{ t5_ymd + years{ 1 } };
	// Convert back to a serial type.
	auto t7{ sys_days{ t7_ymd } + t5_seconds };
	println("t7 = {:L}", t7);        // 2021-06-22 09:35:10
}