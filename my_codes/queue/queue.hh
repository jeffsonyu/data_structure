#ifndef QUEUE_HH
#define QUEUE_HH

#include <iostream>

#define DEFAULT_LIST_SIZE 100

using namespace std;

template <typename Elem>
class queue{
    public:
        queue(int size = DEFAULT_LIST_SIZE);
        ~queue();
        bool appendleft(const Elem&);
        Elem pop();
        void print();

    private:
        int maxSize;
        int listSize;
        Elem* arr;
};

#endif

