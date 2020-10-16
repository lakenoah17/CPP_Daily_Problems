//
// Created by noahs on 10/16/2020.
//

#include "Node.h"

Node::Node(Node * parent){
    this->parent = parent;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->locked = false;
}

Node * Node::getParent(){
    return this->parent;
}

Node * Node::getLeftChild(){
    return this->leftChild;
}

Node * Node::getRightChild(){
    return this->rightChild;
}

void Node::setLeftChild(Node * leftChildToSet){
    this->leftChild = leftChildToSet;
}

void Node::setRightChild(Node * rightChildToSet){
    this->rightChild = rightChildToSet;
}

bool Node::isLocked() {
    return this->locked;
}

bool Node::lock(){
    if (!this->locked){
        Node * currNode = this;

        while(currNode != nullptr){
            if (currNode->isLocked()){
                return false;
            }
            currNode = currNode->getParent();
        }

        this->locked = lockUtil(this);

        return this->locked;
    }

    return false;
}

bool Node::lockUtil(Node * currNode) {
    if (currNode == nullptr){
        return true;
    }

    if (currNode->isLocked()){
        return false;
    }

    return lockUtil(currNode->getLeftChild()) && lockUtil(currNode->getRightChild());
}

bool Node::unlock(){
    if (this->locked){
        this->locked = false;
        return true;
    }
    return false;
}
