# include "Person.h"

namespace sjtu{
    void Person::setname(std::string& name_p){
        name = name_p;
    }

    void Person::setage(int age_p){
        age = age_p;
    }

    void Person::setnum(int num_p){
        num = num_p;
    }

    void Person::setemail(std::string& email_p){
        email = email_p;
    }

    std::string Person::getname() const{
        return name;
    }

    int Person::getage() const{
        return age;
    }

    int Person::getnum() const{
        return num;
    }

    std::string Person::getemail() const{
        return email;
    }

    
}
