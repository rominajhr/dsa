#include<iostream>
using namespace std;

int division(int , int);

int main(){
    int a , b;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    cout<<"\na/b = "<<division(a , b)<<endl;
}

int division(int a , int b){
    if(b == 0)
        return -1;
    if(a < b)
        return 0;

    return division(a - b , b) + 1;
}

