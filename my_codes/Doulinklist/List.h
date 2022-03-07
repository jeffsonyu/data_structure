/**
 * @file List.h
 * @brief List ADT
 * 
 */
#ifndef LIST_H
#define LIST_H

/**
 * @brief List ADT
 * 
 * @tparam Elem 
 */
template <class Elem> class List {
public:
  /** @brief Clear the list */
  virtual void clear() = 0;
  /** @brief Insert an element to the list */
  virtual bool insertPos(const Elem&, int) = 0;
  /** @brief Append an element to the end of list */
  virtual bool append(const Elem&) = 0;
  /** @brief Remove an element from the list */
  virtual bool removePos(int) = 0;
  /** @brief Set the fence to the start*/
  virtual Elem getValuePos(int) = 0;
  /** @brief Print the list */
  virtual void print() = 0;
};

#endif
