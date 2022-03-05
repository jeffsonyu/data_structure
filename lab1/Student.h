#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

namespace sjtu{
    class Student: public Person{
        public:
            Student(std::string name_stu, int age_stu, int num_stu, std::string email, int cla_stu);
            ~Student() = default;

            void setclass(int cla_stu);

            int getclass() const;

            sjtu::Student operator + (sjtu::Student& stu1);

            void print_info();
        protected:
            int cla;
    };
}

#endif