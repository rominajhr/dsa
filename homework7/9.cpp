#include<iostream>
using namespace std;

struct node{
    int num;
    node * nxt;
};

void newNode(node *& , int);
void copyNode(node *);
void printNode(node *);

int main(){

    node * HEAD = NULL;
    cout<<"Enter numbers(enter -1 for the end of array) :"<<endl;
    int n;
    cin>>n;
    while(n != -1){
        newNode(HEAD , n);
        cin>>n;
    }

    copyNode(HEAD);
    printNode(HEAD);

}

void newNode(node * &head , int n){
    node * temp = new node;
    temp->num = n;
    temp->nxt = head;
    head = temp;
}

void copyNode(node * head){
    while(head){
        node * temp = new node;
        temp->num = head->num;
        temp->nxt = head->nxt;
        head->nxt = temp;
        head = head->nxt->nxt;
    }
}

void printNode(node * head){
    while(head){
        cout<<head->num<<" ";
        head = head->nxt;
    }
    cout<<endl;
}