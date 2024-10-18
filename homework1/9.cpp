#include<iostream>
using namespace std;

int f(int , int);

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    cout<<"\n"<<f(1 , n)<<endl;
}

int f(int i , int n){
    if(i == n)
        return 1;

    return 1 + (i + 1) * f(i + 1 , n);
}