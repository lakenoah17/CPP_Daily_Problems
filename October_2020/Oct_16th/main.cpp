#include "iostream"
#include "Node.h"
//This problem was asked by Google.
//
//Implement locking in a binary tree. A
// binary tree node can be locked or unlocked
// only if all of its descendants or ancestors
// are not locked.
//
//Design a binary tree node class with the
// following methods:
//
//is_locked, which returns whether the node is
//      locked
//lock, which attempts to lock the node. If it
//      cannot be locked, then it should return
//      false. Otherwise, it should lock it and
//      return true.
//unlock, which unlocks the node. If it cannot
//      be unlocked, then it should return false.
//      Otherwise, it should unlock it and return
//      true.
//You may augment the node to add parent pointers
// or any other property you would like. You may
// assume the class is used in a single-threaded
// program, so there is no need for actual locks
// or mutexes. Each method should run in O(h),
// where h is the height of the tree.

int main(){
    Node * root = new Node(nullptr);

    Node * left1 = new Node(root);
    Node * right1 = new Node(root);

    Node * left21 = new Node(left1);
    Node * right21 = new Node(left1);

    Node * left22 = new Node(right1);
    Node * right22 = new Node(right1);

    root->setLeftChild(left1);
    root->setRightChild(right1);

    left1->setLeftChild(left21);
    left1->setRightChild(right21);

    right1->setLeftChild(left22);
    right1->setRightChild(right22);

    std::cout<<root->lock()<<'\n';
    std::cout<<root->isLocked()<<'\n';

    std::cout<<'\n';

    std::cout<<left1->lock()<<'\n';
    std::cout<<left1->isLocked()<<'\n';

    std::cout<<'\n';

    std::cout<<root->unlock()<<'\n';
    std::cout<<root->isLocked()<<'\n';

    std::cout<<'\n';

    std::cout<<left1->lock()<<'\n';
    std::cout<<left1->isLocked()<<'\n';

    std::cout<<'\n';

    std::cout<<right1->lock()<<'\n';
    std::cout<<right1->isLocked()<<'\n';

    std::cout<<'\n';

    std::cout<<root->lock()<<'\n';
    std::cout<<root->isLocked()<<'\n';

    std::cout<<right21->lock()<<'\n';
    std::cout<<right21->isLocked()<<'\n';

    left1->unlock();

    std::cout<<right21->lock()<<'\n';
    std::cout<<right21->isLocked()<<'\n';


}

