export module efficient_car_miles_estimator;

export import miles_estimator;

export class EfficientCarMilesEstimator : public MilesEstimator
{
private:
	int getMilesPerGallon() const override
	{
		return 35;
	}
};
