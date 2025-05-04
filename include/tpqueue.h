// Copyright 2022 NNTU-CS
#include <stdexept>

#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
struct Node {
  T data;
  Node* next;
}

template<typename T>
class TPQueue {
  private:
    Node<T>* head;
  public:
    TPQueue(): head(nullptr) {}
    ~TPQueue() {
      while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
      }
    }
    void push(const T& sym) {
      Node<T>* newNode = new Node<T>{sym, nullptr};
      if (head == nullptr || sym.prior > head->data.prior) {
        newNode->next = head;
        head = newNode;
        return;
      }
      Node<T>* current = head;
      while (current->next != nullptr && current->next->data.prior >= sym.prior) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
    T pop() {
      if (head == nullptr) {
        throw std::runtime_error("Queue is empty");
      }
      Node<T>* temp = head;
      T result = head->data;
      head = head->next;
      delete temp;
      return result;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
