//
// Created by oreste on 2022/3/4.
//

#include "Professor.h"
#include "Student.h"

int main()
{
	auto stu_ptr = new sjtu::Student[5];
	for(int i = 0; i < 5; i++)
	{
		std::string temp = "stu" + std::to_string(i);
		stu_ptr[i].setName(temp);
		temp = std::to_string(i);
		stu_ptr[i].setNumber(temp);

		std::cout << stu_ptr[i] << std::endl << std::endl;
	}
	return 0;
}