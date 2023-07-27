import std;

using namespace std;

void threadFunction(stop_token token, int id)
{
	while (!token.stop_requested()) {
		println("Thread {} doing some work.", id);
		this_thread::sleep_for(500ms);
	}
	println("Stop requested for thread {}.", id);
}

int main()
{
	jthread job1{ threadFunction, 1 };
	jthread job2{ threadFunction, 2 };

	this_thread::sleep_for(2s);
	println("main() is ending.");
	
	job1.request_stop();
	job2.request_stop();
}