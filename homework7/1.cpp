#include<iostream>
using namespace std;

struct node{
    int num;
    node* nxt;
};

void newNode(node * &, int);
node * findMax(node *);
void deleteMax(node * &);
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

    deleteMax(HEAD);
    printNode(HEAD);
}

void newNode(node * &head , int n){
    node * temp = new node;
    temp->num = n;
    temp->nxt = head;
    head = temp;
}

node * findMax(node * head){
    node * temp = NULL;
    int maximum = head->num;
    while(head->nxt){
        if(head->nxt->num > maximum){
            temp = head;
            maximum = head->nxt->num;
        }

        head = head->nxt;
    }

    return temp;
}

void deleteMax(node *& head){
    node * temp = findMax(head);
    if(temp == NULL)
        head = head->nxt;
    else
        temp->nxt = temp->nxt->nxt;
}

void printNode(node * head){
    while(head){
        cout<<head->num<<" ";
        head = head->nxt;
    }
    cout<<endl;
}
