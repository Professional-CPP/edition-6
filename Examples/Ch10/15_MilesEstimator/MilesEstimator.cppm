export module miles_estimator;

export class MilesEstimator
{
public:
	virtual ~MilesEstimator() = default;

	int getMilesLeft() const
	{
		return getMilesPerGallon() * getGallonsLeft();
	}

	virtual void setGallonsLeft(int gallons)
	{
		m_gallonsLeft = gallons;
	}

	virtual int getGallonsLeft() const
	{
		return m_gallonsLeft;
	}

private:
	int m_gallonsLeft{ 0 };

	virtual int getMilesPerGallon() const
	{
		return 20;
	}
};
