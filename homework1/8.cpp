#include<iostream>
#include<string.h>
using namespace std;

void truthTable(int , string);

int main(){
    int n;
    cout<<"Enter the number of colums : ";
    cin>>n;

    cout<<"\n~~~ truth table ~~~\n\n";
    truthTable(n , "");
    cout<<endl;
}

void truthTable(int n , string s){
    if(n == 1){
        cout<<s + '0'<<endl;
        cout<<s + '1'<<endl;
    }
    else{
        truthTable(n - 1 , s + "0");
        truthTable(n - 1 , s + "1");
    }
}