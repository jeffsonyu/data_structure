//
// Created by oreste on 2022/3/4.
//


#include "Professor.h"
#include "Student.h"

#include <memory>

int main()
{
	auto stu_ptr = new sjtu::Student[5];
	for (int i = 0; i < 5; i++)
	{
		std::string temp = "stu" + std::to_string(i);
		stu_ptr[i].setName(temp);
		temp = std::to_string(i);
		stu_ptr[i].setNumber(temp);
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << stu_ptr[i].getNumber() << "<" << stu_ptr[i].getNumber() << " : " << (stu_ptr[i]
			< stu_ptr[i]) << std::endl;

		std::cout << stu_ptr[i].getNumber() << ">=" << stu_ptr[i].getNumber() << " : " << (stu_ptr[i]
			>= stu_ptr[i]) << std::endl;

		std::cout << stu_ptr[i+1].getNumber() << ">=" << stu_ptr[i].getNumber() << " : " << (stu_ptr[i+1]
			>= stu_ptr[i]) << std::endl;
	}
	delete[] stu_ptr;


	// Unimplemented

	std::shared_ptr<sjtu::Student> stu_ptr2 = std::make_shared<sjtu::Student>();
	std::unique_ptr<sjtu::Student> stu_ptr3 = std::make_unique<sjtu::Student>();

	std::string temp_num = "123";
	std::string temp_name = "ABC";

	stu_ptr2->setNumber(temp_num);
	stu_ptr2->setName(temp_name);

	stu_ptr3->setNumber(temp_num);
	stu_ptr3->setName(temp_name);

	return 0;
}