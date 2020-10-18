#include <iostream>
//This problem was asked by Google.
//
//Given a singly linked list and an
// integer k, remove the kth last
// element from the list. k is
// guaranteed to be smaller than
// the length of the list.
//
//The list is very long, so making
// more than one pass is prohibitively
// expensive.
//
//Do this in constant space and in one pass.

struct Node{
    int data;
    Node *next;
};

Node* findKthLastNode(Node * head, int k);

int main(){
    Node * last = new Node;
    last->data = 1;
    last->next = nullptr;

    Node * last2 = new Node;
    last2->data = 2;
    last2->next = last;

    Node * last3 = new Node;
    last3->data = 3;
    last3->next = last2;

    Node * last4 = new Node;
    last4->data = 4;
    last4->next = last3;

    Node * last5 = new Node;
    last5->data = 5;
    last5->next = last4;

    Node * last6 = new Node;
    last6->data = 6;
    last6->next = last5;

    Node * last7 = new Node;
    last7->data = 7;
    last7->next = last6;

    Node * last8 = new Node;
    last8->data = 8;
    last8->next = last7;

    Node * head = new Node;
    head->data = 9;
    head->next = last8;

    std::cout<<findKthLastNode(head, 10)->data;
}

Node* findKthLastNode(Node * head, int k){
    Node * lastNode = head;
    for (int i = 1; i < k; ++i) {
        lastNode = lastNode->next;
    }

    while (lastNode->next != nullptr){
        head = head->next;
        lastNode = lastNode->next;
    }

    return head;
}



