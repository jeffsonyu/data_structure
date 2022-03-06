#ifndef STACK_HH
#define STACK_HH

#include <iostream>
#define DEFAULT_LIST_SIZE 100

using namespace std;

template <typename Elem>
class stack{
    public:
        stack(int size = DEFAULT_LIST_SIZE);
        ~stack();
        bool append(const Elem&);
        Elem pop();
        void print();
        
    private:
        int maxSize;
        int listSize;
        Elem* arr;
};

#endif