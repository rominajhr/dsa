#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1 , q2;
    public :
        void push(int n){
            q1.push(n);
        }

        int pop(){
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int top = q1.front();
            q1.pop();
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }

            return top;

        }
};

int main(){
    Stack s;
    int n , a;
    cout<<"Enter the number of elememnt you want to enter : ";
    cin>>n;
    cout<<"Enter elements : ";
    for(int i = 0;i < n;i++){
        cin>>a;
        s.push(a);
    }
    cout<<"\nStack : ";
    for(int i = 0;i < n;i++){
        cout<<s.pop()<<" ";
    }
    cout<<endl;
}