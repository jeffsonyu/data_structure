#ifndef PERSON_H
#define PERSON_H


#include<iostream>
#include<string>

namespace sjtu{

    class Person{
        public:
            void setname(std::string& name_p);
            void setage(int age_p);
            void setnum(int num_p);
            void setemail(std::string& email_p);

            std::string getname() const;
            int getage() const;
            int getnum() const;
            std::string getemail() const;

            virtual void print_info() = 0;
        protected:
            std::string name;
            int age;
            int num;
            std::string email;
    };
}

#endif