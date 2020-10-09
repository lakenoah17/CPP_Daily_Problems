#include "Node.h"
#ifndef CPP_DAILY_PROBLEMS_REVERSELINKEDLIST_H
#define CPP_DAILY_PROBLEMS_REVERSELINKEDLIST_H

template <typename T>

class ReverseLinkedList {
    private:
        Node<T> head;

    public:
        ReverseLinkedList(Node<T> head);
        Node<T> getHead();
        void addNode(T data);
        Node<T> getIthLastNode(int i);

};


#endif //CPP_DAILY_PROBLEMS_REVERSELINKEDLIST_H
