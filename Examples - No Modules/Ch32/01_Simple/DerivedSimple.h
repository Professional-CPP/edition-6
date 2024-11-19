#pragma once

#include "Simple.h"

// A class derived from the Simple class.
class DerivedSimple : public Simple
{
public:
	DerivedSimple() : Simple{} // Constructor
	{ /* Implementation of constructor */ }

	void publicMemberFunction() override // Overridden member function
	{
		// Implementation of overridden member function
		Simple::publicMemberFunction(); // Access the base class implementation
	}

	virtual void anotherMemberFunction() // New member function
	{ /* Implementation of new member function */ }
};
