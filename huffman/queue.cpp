#include<iostream>
#include<string.h>
#include"queue.h"
using namespace std;

void Queue::enQueue(Node * node){                               //add nodes inorder
    if(front == NULL){
        front = node;
        return;
    }

    Node* cur = front;
    while(cur->nxt != NULL && cur->nxt->num < node->num)
        cur = cur->nxt;

    if(cur == front && cur->num >= node->num){
        node->nxt = cur;
        front = node;        
    }
    else{
        node->nxt = cur->nxt;
        cur->nxt = node;
    }
}

Node * Queue::deQueue(){
    Node* temp = front;
    front = front->nxt;
    return temp;
}

bool Queue::isEmpty(){
    if(front == NULL)
        return true;

    return false;
}