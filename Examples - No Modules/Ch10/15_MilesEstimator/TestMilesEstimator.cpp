#include "MilesEstimator.h"
#include "EfficientCarMilesEstimator.h"
#include <print>

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
