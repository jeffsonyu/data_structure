//
// Created by oreste on 2022/3/4.
//

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

namespace sjtu
{
	class Student : public Person
	{
	public:
		// Constructor
		Student(std::string& name, std::string& number, std::string& email, std::string& className, int age = 0);
		Student() = default;
		// Setter
		void setClass(std::string& className);
		// Getter
		[[nodiscard]] std::string getClass() const;
		// IO
		[[nodiscard]] std::string toString() const override;
		friend std::ostream& operator<<(std::ostream& out, const sjtu::Student& s);
	private:
		std::string _class;
	};
}

#endif //STUDENT_H
