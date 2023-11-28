import std;

using namespace std;
using namespace std::chrono;

seconds getDurationSinceMidnight()
{
	// Get the current local time.
	auto now{ current_zone()->to_local(system_clock::now()) };
	// Truncate the current time to a precision of days.
	auto today{ floor<days>(now) };
	// Calculate the difference with a precision of seconds.
	return duration_cast<seconds>(now - today);
}

int main()
{
	auto numberOfSecondsSinceMidnight{ getDurationSinceMidnight() };
	println("Seconds since midnight: {:L}", numberOfSecondsSinceMidnight);

	hh_mm_ss hms{ numberOfSecondsSinceMidnight };
	println("Converted: {}:{}:{}", hms.hours(), hms.minutes(), hms.seconds());
}