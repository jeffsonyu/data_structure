//
// Created by oreste on 2022/3/4.
//

#include "Person.h"

namespace sjtu
{
	std::ostream& operator<<(std::ostream& out, const sjtu::Person& s)
	{
		out << s.toString();
		return out;
	}
	Person::Person(std::string& name, std::string& number, std::string& email, int age)
		: _name(name), _age(age), _number(number), _email(email)
	{
	}
	Person::Person()
	{
		_age = 0;
	}
	void Person::setName(std::string& name)
	{
		_name = name;
	}
	void Person::setAge(int age)
	{
		_age = age;
	}
	void Person::setNumber(std::string& number)
	{
		_number = number;
	}
	void Person::setEmail(std::string& email)
	{
		_email = email;
	}
	std::string Person::getName() const
	{
		return _name;
	}
	std::string Person::getNumber() const
	{
		return _number;
	}
	std::string Person::getEmail() const
	{
		return _email;
	}
	int Person::getAge() const
	{
		return _age;
	}
	std::string Person::toString() const
	{
		return "Name: " + _name + "\nAge: " + std::to_string(_age) + "\nID: " + _number + "\nEmail: " + _email;
	}
	bool Person::operator<(const Person& p) const
	{
		return _number < p._number;
	}
	bool Person::operator>(const Person& p) const
	{
		return _number > p._number;
	}
	bool Person::operator<=(const Person& p) const
	{
		return _number <= p._number;
	}
	bool Person::operator>=(const Person& p) const
	{
		return _number >= p._number;
	}
	bool Person::operator==(const Person& p) const
	{
		return _number == p._number;
	}
}