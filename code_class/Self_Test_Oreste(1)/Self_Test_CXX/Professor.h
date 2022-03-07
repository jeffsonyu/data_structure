//
// Created by oreste on 2022/3/4.
//

#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"

namespace sjtu
{
	class Professor : public Person
	{
	public:
		// Constructor
		Professor(std::string& name, std::string& number, std::string& email, std::string& level, int age = 0);
		Professor() = default;
		// Setter
		void setLevel(std::string& level);
		// Getter
		[[nodiscard]] std::string getLevel() const;
		// IO
		[[nodiscard]] std::string toString() const override;
		friend std::ostream& operator<<(std::ostream& out, const sjtu::Professor& s);
	private:
		std::string _level;
	};
}
#endif //PROFESSOR_H
