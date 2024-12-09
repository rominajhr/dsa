#include<iostream>
using namespace std;

struct node{
    int num;
    node* nxt;
};

void newNode(node * &, int);
int findMax(node *);

int main(){
    node * HEAD = NULL;
    cout<<"Enter numbers(enter -1 for the end of array) :"<<endl;
    int n;
    cin>>n;
    while(n != -1){
        newNode(HEAD , n);
        cin>>n;
    }

    cout<<"MAX = "<<findMax(HEAD)<<endl;
}

void newNode(node * &head , int n){
    node * temp = new node;
    temp->num = n;
    temp->nxt = head;
    head = temp;
}

int findMax(node * head){
    int maximum = head->num;
    head = head->nxt;
    while(head){
        if(head->num > maximum)
            maximum = head->num;

        head = head->nxt;
    }

    return maximum;
}
