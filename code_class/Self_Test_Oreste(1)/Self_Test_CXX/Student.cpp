//
// Created by oreste on 2022/3/4.
//

#include "Student.h"

namespace sjtu
{
	std::ostream& operator<<(std::ostream& out, const sjtu::Student& s)
	{
		out << s.toString();
		return out;
	}
	Student::Student(std::string& name, std::string& number, std::string& email, std::string& className, int age)
		: Person(name, number, email, age), _class(className)
	{
	}
	void Student::setClass(std::string& className)
	{
		_class = className;
	}
	std::string Student::getClass() const
	{
		return _class;
	}
	std::string Student::toString() const
	{
		return "Name: " + _name + "\nAge: " + std::to_string(_age) + "\nID: " + _number + "\nEmail: " + _email
			+ "\nClass: " + _class;
	}
}