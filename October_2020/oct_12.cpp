#include <math.h>
#include <iostream>
//This problem was asked by Google.
//
//Given two singly linked lists that
// intersect at some point, find the
// intersecting node. The lists are
// non-cyclical.
//
//For example, given
// A = 3 -> 7 -> 8 -> 10
// and
// B = 99 -> 1 -> 8 -> 10,
// return the node with value 8.
//
//In this example, assume nodes with
// the same value are the exact same
// node objects.
//
//Do this in O(M + N) time (where M
// and N are the lengths of the lists)
// and constant space.

struct Node{
    int data;
    Node *next;
};

struct LinkedList{
    int length;
    Node *head;
};

int findIntersect(struct LinkedList *list1, struct LinkedList *list2);

int main(){
    Node *node1 = new Node;
    node1->data = 10;
    node1->next = nullptr;

    Node *node2 = new Node;
    node2->data = 8;
    node2->next = node1;

    Node *node3 = new Node;
    node3->data = 7;
    node3->next = node2;

    Node *node4 = new Node;
    node4->data = 3;
    node4->next = node3;

    Node *node5 = new Node;
    node5->data = 1;
    node5->next = node2;

    Node *node6 = new Node;
    node6->data = 99;
    node6->next = node5;

    auto *list1 = new LinkedList;
    list1->head = node4;
    list1->length = 4;

    auto *list2 = new LinkedList;
    list2->head = node6;
    list2->length = 4;

    std::cout<<findIntersect(list1, list2);
}

int findIntersect(struct LinkedList *list1, struct LinkedList *list2){
    int diffInLen = abs(list1->length - list2->length);
    
    struct Node *list1CurrNode = list1->head;
    struct Node *list2CurrNode = list2->head;

    int runLen = (list1->length > list2->length) ? list1->length : list2->length;

    for (int i = 0; i < runLen; ++i) {
        if (i >= diffInLen){
            if (list2CurrNode->data == list1CurrNode->data){
                return list2CurrNode->data;
            }

            list2CurrNode = list2CurrNode->next;
        }
        list1CurrNode = list1CurrNode->next;
    }

    return -1;
}

