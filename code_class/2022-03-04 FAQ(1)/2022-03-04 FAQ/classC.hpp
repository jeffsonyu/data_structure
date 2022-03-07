#ifndef _CLASSC_HPP
#define _CLASSC_HPP

#include "classA.hpp"

namespace ClassCNamespace {
    class ClassC {
        ClassANamespace::ClassA clsA;
    public:
        ClassC() = default;
        ~ClassC() = default;
        void Method1();
    };
}

#endif