#include<iostream>
using namespace std;

int bmm(int , int);

int main(){
    int a , b;
    cout<<"Enter two numbers : ";
    cin>>a>>b;

    cout<<bmm(a , b);

}

int bmm(int a , int b){
    for(int i = 2;i <= b / 2;i++){
        if(b % i == 0 && a % i == 0)
            return i * bmm(a / i , b / i);
    }

    return 1;
}