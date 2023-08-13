export module toyota;

export import icar;
import std;

export class Toyota : public ICar
{
};

export class ToyotaSedan : public Toyota
{
public:
	std::string info() const override { return "Toyota Sedan"; }
};

export class ToyotaSuv : public Toyota
{
public:
	std::string info() const override { return "Toyota SUV"; }
};
