#include "Node.h"
#include "ReverseLinkedList.h"

template <typename T>
Node<T>::Node(T data){
    this->data = data;
}

template <typename T>
T Node<T>::getData() {
    return this->data;
}

template <typename T>
void Node<T>::setPrevious(Node<T> nodeToSet) {
    this->prev = *nodeToSet;
}

template <typename T>
Node<T> Node<T>::getPrevious(){
    return *this->prev;
}