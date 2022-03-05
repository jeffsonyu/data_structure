/**
 * @file AList.h
 * @brief Array-based list declaratoin
 * 
 */
#ifndef ALIST_H
#define ALIST_H

#include "List.h"
#include <iostream>

#define DEFAULT_LIST_SIZE 100

using namespace std;

/**
 * @brief Array-based list
 * 
 * @tparam Elem 
 */
template <class Elem>
class AList : public List<Elem> 
{
private:
	/** @brief Maximum size of list */
	int maxSize;
	/** @brief Actual elem count */
	int listSize;
	/** @brief Position of fence */
	int fence;
	/** @brief Array holding list */
	Elem* listArray; 
public:
	AList(int size = DEFAULT_LIST_SIZE);
	~AList();
	void clear();
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
 * @brief Construct a new AList<Elem>::AList object
 * 
 * @tparam Elem 
 * @param size Size of the list
 */
template <class Elem>
AList<Elem>::AList(int size) {
    maxSize = size;
    listSize = fence = 0;
    listArray = new Elem[maxSize];
}


/**
 * @brief Destroy the AList<Elem>::AList object
 * The listArray will be destroyed
 * 
 * @tparam Elem 
 */
template <class Elem>
AList<Elem>::~AList() {
    delete[] listArray;
}

/**
 * @brief Clear the list
 * The listArray is first destoryed, then reallocated
 * 
 * @tparam Elem 
 */
template <class Elem>
void AList<Elem>::clear() {
    delete[] listArray;
    listSize = fence = 0;
    /** @note By using `new` there is no need to worry about memory outage */ 
    listArray = new Elem[maxSize];
}

// 
/**
 * @brief Insert at front of right partition
 * 
 * @tparam Elem 
 * @param item The item to be inserted
 * @return true The item is successfully inserted
 * @return false @ref maxSize is reached
 */
template <class Elem>
bool AList<Elem>::insert(const Elem& item) {
    if (listSize == maxSize) return false;
    for (int i = listSize; i > fence; i--) /// Shift Elems up to make room
        listArray[i] = listArray[i - 1];
    listArray[fence] = item;
    listSize++; /// Increment list size
    return true;
}

/**
 * @brief Append Elem to end of the list
 * 
 * @tparam Elem 
 * @param item 
 * @return true The item is successfully appended
 * @return false @ref maxSize is reached
 */
template <class Elem>
bool AList<Elem>::append(const Elem& item) {
    if (listSize == maxSize) return false;
    listArray[listSize++] = item;
    return true;
}

// 
/**
 * @brief Remove and return first Elem in right partition
 * 
 * @tparam Elem 
 * @param it A copy of the removed item
 * @return true Suceeed
 * @return false Failed
 */
template <class Elem>
bool AList<Elem>::remove(Elem& it) {
    if (rightLength() == 0) return false;
    /** @note The removed item is copied to parameter `it` */
    it = listArray[fence]; // Copy Elem
    for (int i = fence; i < listSize - 1; i++)
        // Shift them down
        listArray[i] = listArray[i + 1];
    listSize--;    // Decrement size
    return true;
}

/**
 * @brief Set The fence to start position
 * 
 * @tparam Elem 
 */
template <class Elem>
void AList<Elem>::setStart() {
    fence = 0;
}

/**
 * @brief Set The fence to end position
 * 
 * @tparam Elem 
 */
template <class Elem>
void AList<Elem>::setEnd() {
    fence = listSize;
}

/**
 * @brief Move the fence to previous position
 * 
 * @tparam Elem 
 */
template <class Elem>
void AList<Elem>::prev() {
    if (fence != 0) fence--;
}

/**
 * @brief  Move fence one step right
 * 
 * @tparam Elem 
 */
template <class Elem>
void AList<Elem>::next() {
    if (fence <= listSize) fence++;
}

/**
 * @brief Return the left length of the list
 * 
 * @note Left length is defined as the distanct between the beginning of list to @ref fence
 * @tparam Elem 
 * @return int Left length of the fence
 */
template <class Elem>
int AList<Elem>::leftLength() const {
    return fence;
}

/**
 * @brief Return the left length of the list
 * 
 * @note Right length is defined as the distanct between the @ref fence to the end of list
 * @tparam Elem 
 * @return int Right length of the list
 */
template <class Elem>
int AList<Elem>::rightLength() const {
    return listSize - fence;
}

/**
 * @brief Set the fence to a position 
 * 
 * @tparam Elem 
 * @param pos The position
 * @return true Succeed
 * @return false Failed
 */
template <class Elem>
bool AList<Elem>::setPos(int pos) {
    if ((pos >= 0) && (pos <= listSize)) fence = pos;
    return (pos >= 0) && (pos <= listSize);
}

/**
 * @brief Get the value of the fence
 * 
 * @tparam Elem 
 * @param it A copy of current item
 * @return true Succed
 * @return false Failed
 */
template <class Elem>
bool AList<Elem>::getValue(Elem& it) const {
    if (rightLength() == 0) return false;
    else { it = listArray[fence]; return true; }
}

/**
 * @brief Print the list
 * 
 * @tparam Elem 
 */
template <class Elem>
void AList<Elem>::print() const {
    int temp = 0;
    cout << "< ";
    while (temp < fence) cout << listArray[temp++] << " ";
    cout << "| ";
    while (temp < listSize) cout << listArray[temp++] << " ";
    cout << ">\n";
}

#endif