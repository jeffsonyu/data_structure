/**
 * @file LList.h
 * @brief Singly-linked list declaration
 * 
 */

#ifndef LLIST_H
#define LLIST_H

#include "List.h"
#include <iostream>

#define DEFAULT_LIST_SIZE 100

using namespace std;

/**
 * @brief Singly-linked list node
 * 
 * @tparam Elem 
 */
template <class Elem> class Link {
public:
    /** @brief Value for this node*/
    Elem element;
    /** @brief Pointer to next node*/
    Link* next;

    /**
     * @brief Construct a new Link object
     * 
     * @param elemval Value of the element
     * @param nextval Point to the next element 
     */
    Link(const Elem& elemval, Link* nextval = nullptr)
    {
        element = elemval;  next = nextval;
    }
    /**
     * @brief Construct a new Link object
     * 
     * @param nextval Point to the next element 
     */
    Link(Link* nextval = nullptr) { next = nextval; }
};

/**
 * @brief Single-linked list
 * 
 * @tparam Elem 
 */
template <class Elem> class DList : public List<Elem> {
private:
    /** @brief Point to list header*/
    Link<Elem>* head;
    /** @brief Pointer to last Elem in list*/
    Link<Elem>* tail;
    /** @brief Last element on left side*/
    Link<Elem>* fence;
    /** @brief Size of left partition*/
    int leftcnt;
    /** @brief Size of right partition*/
    int rightcnt;
    /** @brief Initialization routine*/
    void init();
    /** @brief Return link nodes to free store*/
    void removeall();
public:
    DList(int size = DEFAULT_LIST_SIZE) { init(); }
    ~DList() { removeall(); }
    void clear() { removeall(); init(); }
    bool insert(const Elem&);
    bool append(const Elem&);
    bool remove(Elem&);
    void setStart();
    void setEnd();
    void prev();
    void next();
    int leftLength() const;
    int rightLength() const;
    bool setPos(int pos);
    bool getValue(Elem& it) const;
    void print() const;
};

/**
 * @brief Initialization routine
 * 
 * @tparam Elem 
 */
template <class Elem>
void DList<Elem>::init() {
    fence = tail = head = new Link<Elem>;
	leftcnt = rightcnt = 0;
}

/**
 * @brief Return link nodes to free store
 * 
 * @tparam Elem 
 */
template <class Elem>
void DList<Elem>::removeall() {
    while (head != NULL) {
        fence = head;
        head = head->next;
        delete fence;
    }
}

/**
 * @brief Insert at front of right partition
 * 
 * @tparam Elem 
 * @param item 
 * @return true 
 * @return false 
 */
template <class Elem>
bool DList<Elem>::insert(const Elem& item) {
    fence->next = new Link<Elem>(item, fence->next);
    if (tail == fence) tail = fence->next;
    rightcnt++;
    return true;
}

/**
 * @brief Append Elem to end of the list
 * 
 * @tparam Elem 
 * @param item 
 * @return true 
 * @return false 
 */
template <class Elem>
bool DList<Elem>::append(const Elem& item) {
    tail = tail->next = new Link<Elem>(item, NULL);
    rightcnt++;
    return true;
}

/**
 * @brief Remove and return first Elem in right partition
 * 
 * @tparam Elem 
 * @param it 
 * @return true 
 * @return false 
 */
template <class Elem> bool DList<Elem>::remove(Elem& it) {
    if (fence->next == NULL) return false;
    it = fence->next->element;          // Remember value
    Link<Elem>* ltemp = fence->next;    // Remember link node
    fence->next = ltemp->next;          // Remove from list
    if (tail == ltemp) tail = fence;    // Reset tail    
    delete ltemp;                       // Reclaim space
    rightcnt--;
    return true;
}

/**
 * @brief Set The fence to start position
 * 
 * @tparam Elem 
 */
template <class Elem> void DList<Elem>::setStart() {
    fence = head; rightcnt += leftcnt; leftcnt = 0;
}

/**
 * @brief Set The fence to end position
 * 
 * @tparam Elem 
 */
template <class Elem> void DList<Elem>::setEnd() {
    fence = tail; leftcnt += rightcnt; rightcnt = 0;
}

/**
 * @brief Move the fence to previous position; no change if left is empty
 * 
 * @tparam Elem 
 * @note Complexity is O(n)
 */
template <class Elem> void DList<Elem>::prev() {
    Link<Elem>* temp = head;
    if (fence == head) return; // No prev Elem
    while (temp->next != fence) temp = temp->next;
    fence = temp; leftcnt--; rightcnt++;
}

/**
 * @brief Move fence one step right; no change if right is empty
 * 
 * @tparam Elem 
 */
template <class Elem> void DList<Elem>::next() {
    if (fence != tail) // Don't move fence if right empty
    {
        fence = fence->next; rightcnt--; leftcnt++;
    }
}

/**
 * @brief Get the count of left partition
 * 
 * @tparam Elem Type of template
 * @return int Result
 */
template <class Elem> int DList<Elem>::leftLength() const { 
    return leftcnt; 
}

/**
 * @brief Get the count of right partition
 * 
 * @tparam Elem Type of template
 * @return int Result
 */
template <class Elem> int DList<Elem>::rightLength() const { 
    return rightcnt; 
}

/**
 * @brief Set the size of left partition to pos
 * 
 * @tparam Elem Type of template
 * @param pos The position
 * @return true Succeed
 * @return false Failed
 */
template <class Elem>
bool DList<Elem>::setPos(int pos) {
    if ((pos < 0) || (pos > rightcnt + leftcnt)) return false;

    /** @warning The old implementation is wrong
     * @code
     * fence = head;
     * for (int i = 0; i < pos; i++) fence = fence->next;
     * return true;
     * @endcode
     */
    setStart();
    for (int i = 0; i < pos; i++) next();
    return true;
}

/**
 * @brief Get the value of first Elem in right partition
 * 
 * @tparam Elem 
 * @param it A copy of item
 * @return true Succed
 * @return false Failed
 */
template <class Elem>
bool DList<Elem>::getValue(Elem& it) const {
    if (rightLength() == 0) return false;
    it = fence->next->element;
    return true;
}


/**
 * @brief Print the list
 * 
 * @tparam Elem 
 */
template <class Elem>
void DList<Elem>::print() const {
    Link<Elem>* temp = head;
    cout << "< ";
    while (temp != fence) {
        cout << temp->next->element << " ";
        temp = temp->next;
    }
    cout << "| ";
    while (temp->next != NULL) {
        cout << temp->next->element << " ";
        temp = temp->next;
    }
    cout << ">\n";
}
#endif