#include<iostream>
using namespace std;

struct node
{
    int num;
    node * nxt;
    node * pre;
};

class Queue{
    node * front;
    node * last;
    public:
        Queue(){
            front = NULL;
            last = NULL;
        }
        void enQueue(int n){
            node * temp = new node;
            temp->num = n;
            if(front == NULL){
                last = front = temp;
                temp->nxt = NULL;
                temp->pre = NULL;
            }
            else{
                last->nxt = temp;
                temp->pre = last;
                temp->nxt = NULL;
                last = temp;
            }
        }

        int deQueue(){
            if(this->isEmpty())
                return 0;
            node * minimum = front , *p = front->nxt;
            while(p){
                if(p->num < minimum->num)
                    minimum = p;

                p = p->nxt;
            }

            int de = minimum->num;

            if(minimum == front){
                front = front->nxt;
                if(front)
                    front->pre = NULL;
            }
            else if(minimum == last){
                last = last->pre;
                last->nxt = NULL;
            }
            else{
                minimum->pre->nxt = minimum->nxt;
                minimum->nxt->pre = minimum->pre;
            }

            if(last == NULL || front == NULL){
                last = NULL;
                front = NULL;
            }

            

            delete minimum;

            return de;
        }

        bool isEmpty(){
            return front==NULL;
        }
};

int main(){

    Queue queue;
    cout<<"Enter numbers(enter -1 for the end of array) :"<<endl;
    int n;
    cin>>n;
    while(n != -1){
        queue.enQueue(n);
        cin>>n;
    }

    cout<<"\nQueue : ";
    while(!queue.isEmpty()){
        cout<<queue.deQueue()<<" ";
    }
    cout<<endl;

}