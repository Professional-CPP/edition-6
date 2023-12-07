export module icar;

import std;

export class ICar
{
public:
	virtual ~ICar() = default;  // Always a virtual destructor!
	virtual std::string info() const = 0;
};
