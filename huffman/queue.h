#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<string.h>
using namespace std;

class Node{
    public:
        int num;
        char ch;
        Node* nxt;
        Node* left;
        Node* right;
        Node(int n = 0 , char c = '\0', Node* next = NULL){
            num = n ; ch = c ; nxt = next;
            left = NULL;right = NULL;
        }
        Node(Node * node1, Node * node2){
            num = node1->num + node2->num;
            ch = '\0';
            nxt = NULL;
            left = node1;
            right = node2;
        }


};


class Queue{
    Node* front;
    public:
        Queue(){front = NULL;}
        void enQueue(Node *);
        Node* deQueue();
        bool isEmpty();
};

#endif