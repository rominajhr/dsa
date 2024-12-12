#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int>s1 , s2;
    public:
        void enQueue(int n){
            s1.push(n);
        }

        int deQueue(){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int top = s2.top();
            s2.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }

            return top;
        }
};

int main(){
    Queue q;
    int n , a;
    cout<<"Enter the number of elememnt you want to enter : ";
    cin>>n;
    cout<<"Enter elements : ";
    for(int i = 0;i < n;i++){
        cin>>a;
        q.enQueue(a);
    }
    cout<<"\nQueue : ";
    for(int i = 0;i < n;i++){
        cout<<q.deQueue()<<" ";
    }
    cout<<endl;
}
