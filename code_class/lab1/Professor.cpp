#include "Professor.h"

namespace sjtu{
    Professor::Professor(std::string name_prof, 
                         int age_prof, 
                         int num_prof, 
                         std::string email_prof, 
                         int level_prof){
        this->setname(name_prof);
        this->setage(age_prof);
        this->setnum(num_prof);
        this->setemail(email_prof);
        this->setlevel(level_prof);
    }

    void Professor::setlevel(int level_prof){
        level = level_prof;
    }

    int Professor::getlevel() const{
        return level;
    }

    sjtu::Professor Professor::operator - (sjtu::Professor& prof1){

        int age_2 = this->getage() - prof1.getage();
        int num_2 = this->getnum() - prof1.getnum();
        int level_2 = this->getlevel() - prof1.getlevel();
        
        std::string name_2 = this->getname();
        std::string email_2 = this->getemail();
        sjtu::Professor prof2 = sjtu::Professor(name_2, age_2, num_2, email_2, level_2);

        return prof2;
    }

    void Professor::print_info(){
        std::cout << "The professor's name is: " << this->getname() << std::endl;
        std::cout << "The professor's age is: " << this->getage() << std::endl;
        std::cout << "The professor's num is: " << this->getnum() << std::endl;
        std::cout << "The professor's email is: " << this->getemail() << std::endl;
        std::cout << "The professor's level is: " << this->getlevel() << std::endl;
    }
}