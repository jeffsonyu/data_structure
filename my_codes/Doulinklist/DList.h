#ifndef DLIST_H
#define DLIST_H

#include "List.h"
#include <iostream>

#define DEFAULT_LIST_SIZE 100

using namespace std;

template <typename Elem>
class Link{
    public:

        Elem element;
        Link* next;
        Link* prev;

};

template <typename Elem>
class DList : public List<Elem>{
    public:
        DList(int size = DEFAULT_LIST_SIZE) { init(); }
        ~DList() { removeall(); }
        void clear() { removeall(); init(); }
        bool insertPos(const Elem&, int);
        bool append(const Elem&);
        bool removePos(int);
        Elem getValuePos(int);
        void print();
    private:
        int listSize;
        Link<Elem>* head;
        Link<Elem>* tail;
        void init();
        void removeall();
};

template <typename Elem>
void DList<Elem>::init() {
    head = new Link<Elem>;
    head->next = nullptr;
    head->prev = nullptr;
    tail = head;
    listSize = 0;
}

template <typename Elem>
void DList<Elem>::removeall(){

    Link<Elem>* temp = new Link<Elem>;
    while (head != NULL){
        temp = head;
        head = head->next;
        temp->prev = nullptr;
        delete temp;
    }
    listSize = 0;
}

template <typename Elem>
bool DList<Elem>::insertPos(const Elem& item, int pos){

    if (listSize == DEFAULT_LIST_SIZE) return false;

    Link<Elem>* ins = new Link<Elem>;
    Link<Elem>* node = head;
    for (int i = 0; i < pos-1; i++){
        node = node->next;
    }

    ins->element = item;
    ins->next = node->next;
    ins->prev = node;
    node->next = ins;

    listSize++;

    return true;
}

template <typename Elem>
bool DList<Elem>::append(const Elem& item){
    
    if (listSize == DEFAULT_LIST_SIZE) return false;

    Link<Elem>* ins = new Link<Elem>;

    ins->element = item;
    ins->next = nullptr;
    ins->prev = tail;
    tail->next = ins;
    tail = ins;

    listSize++;

    return true;
}

template <typename Elem>
bool DList<Elem>::removePos(int pos){

    if (listSize == DEFAULT_LIST_SIZE) return false;

    Link<Elem>* node = head;
    for (int i = 0; i < pos; i++){
        node = node->next;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
    listSize--;
    
    return true;
}

template <typename Elem>
Elem DList<Elem>::getValuePos(int pos){
    Link<Elem>* node = head;
    for (int i = 0; i < pos; i++){
        node = node->next;
    }

    return node->element;
}

template <typename Elem>
void DList<Elem>::print(){

    cout << "The elements of the list are: " << endl;
    cout << "Head";

    Link<Elem>* node = head;
    for (int i = 0; i < listSize; i++){
        node = node->next;
        cout << " - " << node->element;
    }

    cout << " - End" << endl;

}

#endif