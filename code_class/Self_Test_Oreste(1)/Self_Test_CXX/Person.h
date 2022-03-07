//
// Created by oreste on 2022/3/4.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

namespace sjtu
{
	class Person
	{
	public:
		// Constructors
		Person(std::string& name, std::string& number, std::string& email, int age = 0);
		Person();
		// Setters
		void setName(std::string& name);
		void setAge(int age);
		void setNumber(std::string& number);
		void setEmail(std::string& email);
		// Getters
		[[nodiscard]] std::string getName() const;
		[[nodiscard]] std::string getNumber() const;
		[[nodiscard]] std::string getEmail() const;
		[[nodiscard]] int getAge() const;
		// IO
		[[nodiscard]] virtual std::string toString() const;
		// Operators
		bool operator <(const Person& p) const;
		bool operator >(const Person& p) const;
		bool operator <=(const Person& p) const;
		bool operator >=(const Person& p) const;
		bool operator ==(const Person& p) const;
		friend std::ostream& operator<<(std::ostream& out, const sjtu::Person& s);
	protected:
		std::string _name;
		int _age;
		std::string _number;
		std::string _email;
	};

}
#endif //PERSON_H
