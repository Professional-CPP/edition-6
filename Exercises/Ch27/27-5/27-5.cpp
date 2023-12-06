import std;

using namespace std;

int main()
{
	constexpr unsigned numberOfRobots{ 2 };
	constexpr unsigned numberOfIterations{ 3 };
	unsigned iterationCount{ 1 };

	vector<jthread> robots;

	auto completionCallback{ [&]() noexcept {
		if (iterationCount == numberOfIterations) {
			println("Finished {} iterations, stopping robots...", numberOfIterations);
			for (auto& robot : robots) { robot.request_stop(); }
		} else {
			++iterationCount;
			println("All robots finished. Preparing iteration {}...", iterationCount);
			this_thread::sleep_for(1s);
			println("Iteration {} ready to start. Waking up robots.", iterationCount);
		}
	} };

	barrier robotSynchronization{ numberOfRobots, completionCallback };
	latch threadStartedLatch{ numberOfRobots };
	latch threadWaiter{ 1 };

	auto robotThreadFunction{ [&](stop_token token, string_view name) {
		println("   Thread for robot {} started.", name);
		threadStartedLatch.count_down();
		threadWaiter.wait();
		while (!token.stop_requested()) {
			println("   {} started work.", name);
			this_thread::sleep_for(1s);
			println("   {} finished.", name);
			robotSynchronization.arrive_and_wait();
		}
		println("   {} shutting down.", name);
	} };

	println("Creating {} robot threads.", numberOfRobots);
	for (unsigned i{ 0 }; i < numberOfRobots; ++i) {
		robots.emplace_back(robotThreadFunction, format("Robot_{}", i));
	}
	threadStartedLatch.wait();
	println("All robots have been created and are waiting.");

	println("Preparing iteration {}...", iterationCount);
	this_thread::sleep_for(1s);
	println("Iteration {} ready to start. Waking up robots.", iterationCount);
	threadWaiter.count_down();

	for (auto& robot : robots) { robot.join(); }
	println("Done with all work.");
}
