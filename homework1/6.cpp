#include<iostream>
using namespace std;

int multi(int , int , int);

int main(){
    int a , b;

    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;

    cout<<"a * b = "<<multi(a , b , 1)<<endl;
}

int multi(int a , int b , int i){
    if(b == 0)
        return 0;
    if(i == b)
        return a;

    return a + multi(a , b , i + 1);
}