#include<iostream>
using namespace std;

struct node{
    int num;
    node* nxt;
};

void newNode(node * &, int);
node * addnm(node * , node *);
void printNode(node *);

int main(){
    node *HEAD1 = NULL , *HEAD2 = NULL, *HEAD;
    int n , m , a;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter the values : ";
    while(n--){
        cin>>a;
        newNode(HEAD1 , a);
    }
    
    cout<<"\nEnter m : ";
    cin>>m;
    cout<<"Enter the values : ";
    while(m--){
        cin>>a;
        newNode(HEAD2 , a);
    }

    HEAD = addnm(HEAD1 , HEAD2);

    printNode(HEAD);


}

void newNode(node * &head , int n){
    if(head == NULL){
        head = new node;
        head->num = n;
        head->nxt = NULL;

        return;
    }

    node * h = head;
    while(h->nxt)
        h = h->nxt;

    node * temp = new node;
    temp->num = n;
    temp->nxt = NULL;
    h->nxt = temp;
}

node * addnm(node * h1 , node * h2){
    node * head , *temp;
    if(h1->num < h2->num){
        head = h1;
        h1 = h1->nxt;
    }
    else{
        head = h2;
        h2 = h2->nxt;
    }

    temp = head;
    while(h1 && h2){
        if(h1->num < h2->num){
            temp->nxt = h1;
            h1 = h1->nxt;
        }
        else{
            temp->nxt = h2;
            h2 = h2->nxt;
        }

        temp = temp->nxt;
    }
    if(h2)
        temp->nxt = h2;
    else if(h1)
        temp->nxt = h1;

    return head;
}

void printNode(node * head){
    while(head){
        cout<<head->num<<" ";
        head = head->nxt;
    }
    cout<<endl;
}