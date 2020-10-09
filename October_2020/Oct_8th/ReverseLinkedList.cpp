#include "ReverseLinkedList.h"
#include "Node.h"

template <typename T>
ReverseLinkedList<T>::ReverseLinkedList(Node<T> head){
    this->head = head;
}

template <typename T>
Node<T> ReverseLinkedList<T>::getHead(){
    return this->head;
}

template <typename T>
void ReverseLinkedList<T>::addNode(T data){
    Node<T> nodeToAdd = new Node<T>(data);
    nodeToAdd.setPrevious(head);
    head = nodeToAdd;
}

template <typename T>
Node<T> ReverseLinkedList<T>::getIthLastNode(int i){
    Node<T> currNode = this->head;

    for (int j = 0; j < i; ++j) {
        currNode = currNode.getPrevious();
    }

    return currNode;
}