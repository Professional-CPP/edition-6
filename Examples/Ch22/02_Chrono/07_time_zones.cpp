import std;

using namespace std;
using namespace std::chrono;

int main()
{
	// Set the global locale to the user's local (see Chapter 21).
	locale::global(locale{ "" });


	// List all time zones in the database.
	const auto& database{ get_tzdb() };
	for (const auto& timezone : database.zones) {
		println("{}", timezone.name());
	}


	// Create some time zones.
	auto* brussels{ locate_zone("Europe/Brussels") };
	auto* gmt{ locate_zone("GMT") };
	auto* current{ current_zone() };


	// Convert current time (UTC), to time in Brussels, and time in current zone.
	auto nowUTC{ system_clock::now() };                 // In UTC.
	auto nowInBrussels{ brussels->to_local(nowUTC) };   // In Brussels' time zone.
	auto nowInCurrentZone{ current->to_local(nowUTC) }; // In current time zone.
	println("Now UTC:        {:L%c}", nowUTC);
	println("Now Brussels:   {:L%c}", nowInBrussels);
	println("Now in current: {:L%c}", nowInCurrentZone);


	// Construct a UTC time.
	auto t{ sys_days{ 2020y / June / 22d } + 9h + 35min + 10s }; // 2020-06-22 09:35:10 UTC
	// Convert UTC time to Brussels' local time.
	auto converted{ brussels->to_local(t) };
	println("Converted: {:L}", converted);


	// Construct a local time in the Brussels' time zone.
	zoned_time<hours> brusselsTime{ brussels, local_days { 2020y / June / 22d } + 9h };
	// Convert to New York time.
	zoned_time<hours> newYorkTime{ "America/New_York", brusselsTime };
	println("Brussels: {:L}", brusselsTime.get_local_time());
	println("New York: {:L}", newYorkTime.get_local_time());
}
