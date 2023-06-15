import efficient_car_miles_estimator;
import std;

using namespace std;

int main()
{
	MilesEstimator myMilesEstimator;
	myMilesEstimator.setGallonsLeft(2);
	println("Normal estimator can go {} more miles.",
		myMilesEstimator.getMilesLeft());

	EfficientCarMilesEstimator myEstimator;
	myEstimator.setGallonsLeft(2);
	println("Efficient estimator can go {} more miles.",
		myEstimator.getMilesLeft());
}
