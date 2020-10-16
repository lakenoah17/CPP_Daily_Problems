//
// Created by noahs on 10/16/2020.
//

#include "Node.h"

//Constructs the node
//Params:
//  parent - pointer to the parent node
Node::Node(Node * parent){
    this->parent = parent;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->locked = false;
}

//Returns a pointer to the parent node
Node * Node::getParent(){
    return this->parent;
}

//Returns the left child of this node
Node * Node::getLeftChild(){
    return this->leftChild;
}

//Returns the right child of this node
Node * Node::getRightChild(){
    return this->rightChild;
}

//Sets the left child of this node
//Params:
//  leftChildToSet - the new node to be this nodes left child
void Node::setLeftChild(Node * leftChildToSet){
    this->leftChild = leftChildToSet;
}

//Sets the right child of this node
//Params:
//  rightChildToSet - the new node to be this nodes right child
void Node::setRightChild(Node * rightChildToSet){
    this->rightChild = rightChildToSet;
}

//Returns whether this node is locked or not
bool Node::isLocked() {
    return this->locked;
}

//Attempts to lock this node
//Returns: whether this node was locked or not
bool Node::lock(){
    //Checks if the node is already locked
    if (!this->locked){

        Node * currNode = this;

        //Checks all of the nodes ancestors to see if any are locked
        while(currNode != nullptr){
            //Returns if any are locked
            if (currNode->isLocked()){
                return false;
            }

            currNode = currNode->getParent();
        }

        //Finds whether children are locked or not
        this->locked = lockUtil(this);

        return this->locked;
    }

    return false;
}

//Finds any of currNode's children are locked or not
//Params:
//  currNode - the current node
//Returns: whether any of the nodes children were locked
bool Node::lockUtil(Node * currNode) {
    if (currNode == nullptr){
        return true;
    }

    if (currNode->isLocked()){
        return false;
    }

    return lockUtil(currNode->getLeftChild()) && lockUtil(currNode->getRightChild());
}

//Unlocks this node
//Returns: whether the node was unlocked or not
bool Node::unlock(){
    //If the node is already unlocked the node can't be unlocked
    if (this->locked){
        this->locked = false;
        return true;
    }
    return false;
}
