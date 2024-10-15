#pragma once

#include "MilesEstimator.h"

class EfficientCarMilesEstimator : public MilesEstimator
{
private:
	int getMilesPerGallon() const override
	{
		return 35;
	}
};
