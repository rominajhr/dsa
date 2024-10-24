#include<iostream>
using namespace std;

void f(int [] , int [] , int , int , int);

int main(){
    int n , m , A[100] , B[100] , k;
    cout<<"Enter the size of array A : ";
    cin>>m;
    cout<<"Enter array A : ";
    for(int i = 0;i < m ;i++)
        cin>>A[i];
    cout<<"\nEnter the size of array B : ";
    cin>>n;
    cout<<"Enter array B : ";
    for(int i = 0;i < n;i++)
        cin>>B[i];

    cout<<"\nEnter the sum you are looking for : ";
    cin>>k;

    f(A , B , m , n , k);
}

void f(int A[] , int B[] , int m , int n , int k){
    int i = 0 , j = 0 , x = A[i] + B[j];
    while(x != k && i < m && j < n){
        if(x < k)
            i++;
        else
            j++;

        x = A[i] + B[j];
    }

    cout<<"\n\nThe sum of "<<i + 1<<"th element of A and "<<j + 1<<"th element of B is equal to "<<k<<endl;
    cout<<A[i]<<" + "<<B[j]<<" = "<<k<<endl;
    
}