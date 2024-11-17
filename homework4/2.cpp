#include<iostream>
using namespace std;

class priorityQueue{
    int size , r;
    int* a;

    public:
        priorityQueue(int n){
            size = n;
            a = new int[n];
            r = -1;
        }

        ~priorityQueue(){
            delete a;
        }

        int enQueue(int n){
            if(this->isFull())
                return 0;
            r++;
            a[r] = n;

            return 1;
        }

        int deQueue(){
            if(this->isEmpty())
                return -1;

            int maxi = a[0] , ind = 0;
            for(int i = 1;i <= r;i++){
                if(a[i] > maxi){
                    ind = i;
                    maxi = a[i];
                }

            }

            for(int i = ind + 1;i <= r;i++)
                a[i - 1] = a[i];
            r--;

            return maxi;
        }

        bool isEmpty(){
            if(r == -1)
                return true;

            return false;
        }

        bool isFull(){
            if(r == size - 1)
                return true;

            return false;
        }
};

int main(){
    int n;
    cout<<"\nEnter size of the queue : ";
    cin>>n;
    priorityQueue q(n);
    cout<<"\nEnter the queue(enter -1 for the end of it) : ";
    cin>>n;    
    while(n != -1){
        q.enQueue(n);
        cin>>n;
    }

    cout<<"\n\nThe priority queue : "<<endl;
    do{
        n = q.deQueue();
        cout<<n<<" ";
    }while(n != -1);
    cout<<endl;
}
