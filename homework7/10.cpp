#include<iostream>
using namespace std;

struct node{
    int num;
    node * nxt;
};

void newNode(node * &, int);
void printNode(node *);
void sorting(node *&);
void addNode(node * & , node * & , node *);

int main(){
    node * HEAD = NULL;
    cout<<"Enter numbers(enter -1 for the end of array) :"<<endl;
    int n;
    cin>>n;
    while(n != -1){
        newNode(HEAD , n);
        cin>>n;
    }

    cout<<"\nBefor sorting : ";
    printNode(HEAD);
    cout<<"\nAfter sorting : ";
    sorting(HEAD);
    printNode(HEAD);   
}

void newNode(node * &head , int n){
    node * temp = new node;
    temp->num = n;
    temp->nxt = head;
    head = temp;
}

void printNode(node * head){
    while(head){
        cout<<head->num<<" ";
        head = head->nxt;
    }
    cout<<endl;
}

void sorting(node *& head){
    node * p = head->nxt , * temp , * last = head;
    while(p){
        temp = p;
        p = p->nxt;
        addNode(head , last , temp);
    }
}

void addNode(node * & head , node * & last , node * n){
    node * p = head;
    while(p != last && n->num > p->nxt->num)
        p = p->nxt;
    if(p == head){
        if(head->num > n->num){
            last->nxt = n->nxt;
            n->nxt = head;
            head = n;
        }
        else{
            last->nxt = n->nxt;
            n->nxt = head->nxt;
            head->nxt = n;
        }
    }
    else{
        last->nxt = n->nxt;
        n->nxt = p->nxt;
        p->nxt = n;
    }
    
    if(p == last){
        last = n;
    }
}