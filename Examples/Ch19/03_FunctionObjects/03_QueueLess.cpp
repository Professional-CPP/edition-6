import std;

using namespace std;

int main()
{
	priority_queue<int> myQueue;

	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(2);
	myQueue.push(1);

	while (!myQueue.empty()) {
		print("{} ", myQueue.top());
		myQueue.pop();
	}
}
