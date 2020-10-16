//
// Created by noahs on 10/16/2020.
//

#ifndef CPP_DAILY_PROBLEMS_NODE_H
#define CPP_DAILY_PROBLEMS_NODE_H


class Node {
    private:
        Node *parent;
        Node *leftChild;
        Node *rightChild;
        bool locked;
    public:
        Node(Node * parent);
        Node * getParent();
        Node * getLeftChild();
        Node * getRightChild();
        void setLeftChild(Node * leftChild);
        void setRightChild(Node * rightChild);
        bool isLocked();
        bool lock();
        bool lockUtil(Node * currNode);
        bool unlock();
};


#endif //CPP_DAILY_PROBLEMS_NODE_H
