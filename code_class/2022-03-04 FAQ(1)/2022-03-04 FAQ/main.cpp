#include "classA.hpp"
#include "classB.hpp"
#define USE_CLASSC 1

#if USE_CLASSC
#include "classC.hpp"
#endif

int main() {
    ClassANamespace::ClassA clsA;
    ClassBNamespace::ClassB clsB;
    clsA.Method1();
    clsB.Method1();

#if USE_CLASSC
    ClassCNamespace::ClassC clsC;
    clsC.Method1();

#endif

    return 0;
}