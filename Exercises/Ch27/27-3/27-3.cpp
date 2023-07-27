import std;

using namespace std;
using namespace std::chrono;

atomic<bool> isBeepingEnabled{ true };

void beeper(duration<int> delay)
{
	while (true) {
		if (isBeepingEnabled) {
			print("\a");
		}
		this_thread::sleep_for(delay);
	}
}

int main()
{
	jthread beepThread{ beeper, 3s };
	
	while (true) {
		print("Press enter to pause beeping");
		cin.ignore();
		isBeepingEnabled = !isBeepingEnabled;

		print("Press enter to resume beeping");
		cin.ignore();
		isBeepingEnabled = !isBeepingEnabled;
	}
}
