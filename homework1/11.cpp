#include<iostream>
#include<string.h>
using namespace std;

void coins(int , int , int , int);

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<10<<" "<<5<<" "<<2<<endl;
    coins(n , 0 , 0 , 0);
}

void coins(int n , int d , int p , int t){
    if(n - 10 >= 0 && p == 0 && t == 0)
        coins(n - 10 , d + 1 , p , t);
    if(n - 5 >= 0 && t == 0)
        coins(n - 5 , d , p + 1 , t);
    if(n - 2 >= 0)
        coins(n - 2 , d , p , t + 1);
    
    if(!n)
        cout<<d<<" "<<p<<" "<<t<<endl;
}