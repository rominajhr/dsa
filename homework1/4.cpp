#include<iostream>
using namespace std;

void binary(int);

int main(){
    int num;
    cout<<"Enter a number : ";
    cin>>num;

    cout<<"binary : ";
    binary(num);
    cout<<endl;
}

void binary(int num){
    if(num == 1)
        cout<< 1;
    else{
        binary(num / 2);
        cout<< num % 2;
    }
}