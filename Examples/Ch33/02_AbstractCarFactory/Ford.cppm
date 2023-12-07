export module ford;

export import icar;
import std;

export class Ford : public ICar
{
};

export class FordSedan : public Ford
{
public:
	std::string info() const override { return "Ford Sedan"; }
};

export class FordSuv : public Ford
{
public:
	std::string info() const override { return "Ford SUV"; }
};
