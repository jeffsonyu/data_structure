#include "queue.hh"
#include <iostream>

template <typename Elem>
queue<Elem>::queue(int size){
    maxSize = size;
    listSize = 0;
    arr = new Elem[maxSize];
}

template <typename Elem>
queue<Elem>::~queue(){
    delete [] arr;
}

template <typename Elem>
bool queue<Elem>::appendleft(const Elem & item){
    if (listSize == maxSize) return false;
    for (int i = listSize; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = item;
    listSize++;
}

template <typename Elem>
Elem queue<Elem>::pop(){
    Elem temp = arr[listSize-1];
    arr[listSize-1] = 0;
    listSize--;
    return temp;
}

template <typename Elem>
void queue<Elem>::print(){
    cout << "The elements of the queue is: " << endl;
    cout << "-> ";
    for (int i = 0; i < listSize; i++){
        cout << arr[i] << " ";
    }
    cout << "->" << endl;
}