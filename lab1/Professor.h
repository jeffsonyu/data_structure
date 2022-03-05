#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"
#include <string>

namespace sjtu{
    class Professor: public Person{
        public:
            Professor(std::string name_prof, int age_prof, int num_prof, std::string email_prof, int level_prof);
            ~Professor() = default;

            void setlevel(int level);

            int getlevel() const;
            sjtu::Professor operator - (sjtu::Professor& prof1);

            void print_info();
        protected:
            int level;
    };
}

#endif