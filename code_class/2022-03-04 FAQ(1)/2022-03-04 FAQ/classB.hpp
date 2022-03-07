#ifndef _CLASSB_HPP
#define _CLASSB_HPP
#include "classA.hpp"

namespace ClassBNamespace {
    class ClassB {
        ClassANamespace::ClassA clsA;
    public:
        ClassB() = default;
        ~ClassB() = default;
        void Method1() {
            clsA.Method1();
            ClassANamespace::Functional1();
            return;
        }
    };
}

#endif