#include "stack.hh"
#include <iostream>

template <typename Elem>
stack<Elem>::stack(int size){
    maxSize = size;
    listSize = 0;
    arr = new Elem[maxSize];
}

template <typename Elem>
stack<Elem>::~stack(){
    delete [] arr;
}

template <typename Elem>
bool stack<Elem>::append(const Elem & item){
    if (listSize == maxSize) return false;
    arr[listSize] = item;
    listSize++;
    return true;
}

template <typename Elem>
Elem stack<Elem>::pop(){
    Elem temp = arr[listSize-1];
    arr[listSize-1] = 0;
    listSize--;
    return temp;
}

template <typename Elem>
void stack<Elem>::print(){
    cout << "The elements of the stack is: " << endl;
    cout << "| ";
    for (int i = 0; i < listSize; i++){
        cout << arr[i] << " ";
    }
    cout << "->" << endl;
}