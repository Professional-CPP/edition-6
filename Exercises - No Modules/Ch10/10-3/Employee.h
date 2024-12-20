#pragma once

#include "Person.h"
#include <string>
#include <utility>
#include <format>

namespace HR
{
	class Employee : public Person
	{
	public:
		Employee(int id, std::string firstName, std::string lastName)
			: Person{ std::move(firstName), std::move(lastName) }
			, m_id{ id }
		{
		}

		virtual int getID() const { return m_id; }
		virtual void setID(int id) { m_id = id; }

		std::string toString() const override
		{
			return std::format("Employee with ID={} which is {}",
				getID(), Person::toString());
		}

	private:
		int m_id{ 0 };
	};
}
