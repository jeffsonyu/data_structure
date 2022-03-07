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
  virtual bool insert(const Elem&) = 0;
  /** @brief Append an element to the end of list */
  virtual bool append(const Elem&) = 0;
  /** @brief Remove an element from the list */
  virtual bool remove(Elem&) = 0;
  /** @brief Set the fence to the start*/
  virtual void setStart() = 0;
  /** @brief Set the fence to the end*/
  virtual void setEnd() = 0;
  /** @brief Move the fence to previous position*/
  virtual void prev() = 0;
  /** @brief Move the fence to next position*/
  virtual void next() = 0;
  /** @brief Get the left length of list*/
  virtual int leftLength() const = 0;
  /** @brief Get the right length of list*/
  virtual int rightLength() const = 0;
  /** @brief Set the fence to a certain position*/
  virtual bool setPos(int pos) = 0;
  /** @brief Get the value corresponds to current fence*/
  virtual bool getValue(Elem&) const = 0;
  /** @brief Print the list */
  virtual void print() const = 0;
};

#endif
