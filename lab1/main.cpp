#include "Student.h"
#include "Professor.h"
#include <memory>

int main(){
    sjtu::Student stu1 = sjtu::Student("Jeff", 
                                        20, 
                                        10033, 
                                       "jeff@sjtu.edu.cn", 
                                        2);

    sjtu::Student stu2 = sjtu::Student("Janny", 
                                        20, 
                                        10022, 
                                       "Janny@sjtu.edu.cn", 
                                        1);
                                
    sjtu::Professor prof1 = sjtu::Professor("WSB", 
                                        40, 
                                        20034, 
                                       "WSB@sjtu.edu.cn", 
                                        1);

    sjtu::Professor prof2 = sjtu::Professor("LCW", 
                                        38, 
                                        20035, 
                                       "LCW@sjtu.edu.cn", 
                                        2);
    stu1.setclass(10);
    prof2.setlevel(100);

    sjtu::Student stu3 = stu1 + stu2;
    sjtu::Professor prof3 = prof1 - prof2;

    stu3.print_info();
    prof3.print_info();
    
    return 0;
}