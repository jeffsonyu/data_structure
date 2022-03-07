#ifndef _CLASSA_HPP
#define _CLASSA_HPP

namespace ClassANamespace {
    class ClassD {};
    class ClassA {
    public:
        int Attr1;
        ClassD clsD;
        ClassA() = default;
        ~ClassA() = default;
        void Method1();
        void Method2() {
            clsD.Method1();
        }
    };
    void Functional1() {
        return;
    }
    class ClassD {
    public:
        void Method1() {};
    };
}

namespace ClassANamespace {
    inline void ClassA::Method1() {
        ClassD
            return;
    }
}
#endif