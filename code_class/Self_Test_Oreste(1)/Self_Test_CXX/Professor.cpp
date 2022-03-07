//
// Created by oreste on 2022/3/4.
//

#include "Professor.h"

namespace sjtu
{
	std::ostream& operator<<(std::ostream& out, const sjtu::Professor& s)
	{
		out << s.toString();
		return out;
	}
	Professor::Professor(std::string& name, std::string& number, std::string& email, std::string& level, int age)
		: Person(name, number, email, age), _level(level)
	{
	}
	void Professor::setLevel(std::string& level)
	{
		_level = level;
	}
	std::string Professor::getLevel() const
	{
		return _level;
	}
	std::string Professor::toString() const
	{
		return "Name: " + _name + "\nAge: " + std::to_string(_age) + "\nID: " + _number + "\nEmail: " + _email
			+ "\nLevel: " + _level;
	}
}