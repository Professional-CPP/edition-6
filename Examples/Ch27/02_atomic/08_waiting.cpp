import std;

using namespace std;

int main()
{
	atomic<int> value{ 0 };

	jthread job{ [&value] {
		println("Thread starts waiting.");
		value.wait(0);
		println("Thread wakes up, value = {}", value.load());
	} };

	this_thread::sleep_for(2s);

	println("Main thread is going to change value to 1.");
	value = 1;
	value.notify_all();

	// No need to manually call join(), as we are using jthread.
}