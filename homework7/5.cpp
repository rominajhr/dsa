#include<iostream>
using namespace std;

struct node{
    int num;
    node* nxt;
};

class Stack{
    node * head;
    public : 
        Stack(){head = NULL;}
        void push(int n){
            node * temp = new node;
            temp->num = n;
            temp->nxt = head;
            head = temp;
        }


        int pop(){
            if(this->isEmpty())
                return - 1;
            int value = head->num;
            head = head->nxt;
            return value;
        }


        bool isEmpty(){
            if(!head)
                return true;

            return false;
        }
};

int main(){
    int n , a;
    Stack st;
    cout<<"Enter the number of values you want to enter : ";
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a;
        st.push(a);
    }
    cout<<"\ntesting pop : ";
    while(!st.isEmpty())
        cout<<st.pop()<< " ";

    cout<<endl;

}

