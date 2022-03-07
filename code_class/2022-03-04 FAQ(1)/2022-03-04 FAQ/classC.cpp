#include "classC.hpp"
#include "classA.hpp"

namespace ClassCNamespace {
    void ClassC::Method1() {
        clsA.Method1();
        ClassANamespace::Functional1();
        return;
    }
}