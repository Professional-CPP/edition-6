#include <print>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

void beeper(duration<int> delay)
{
	while (true) {
		print("\a");
		this_thread::sleep_for(delay);
	}
}

int main()
{
	jthread beepThread{ beeper, 3s };
}