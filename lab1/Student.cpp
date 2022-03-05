#include "Student.h"

namespace sjtu{
    Student::Student(std::string name_stu, 
                     int age_stu, 
                     int num_stu, 
                     std::string email_stu, 
                     int cla_stu){
        this->setname(name_stu);
        this->setage(age_stu);
        this->setnum(num_stu);
        this->setemail(email_stu);
        this->setclass(cla_stu);
    }

    void Student::setclass(int cla_stu){
        cla = cla_stu;
    }

    int Student::getclass() const{
        return cla;
    }

    sjtu::Student Student::operator+(sjtu::Student& stu1){

        int age_2 = this->getage() + stu1.getage();
        int num_2 = this->getnum() + stu1.getnum();
        int class_2 = this->getclass() + stu1.getclass();
        
        std::string name_2 = this->getname();
        std::string email_2 = this->getemail();
        sjtu::Student stu2 = sjtu::Student(name_2, age_2, num_2, email_2, class_2);

        return stu2;
    }

    void Student::print_info(){
        std::cout << "The student's name is: " << this->getname() << std::endl;
        std::cout << "The student's age is: " << this->getage() << std::endl;
        std::cout << "The student's num is: " << this->getnum() << std::endl;
        std::cout << "The student's email is: " << this->getemail() << std::endl;
        std::cout << "The student's class is: " << this->getclass() << std::endl;
    }
}