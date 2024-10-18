#include<iostream>
#include<string.h>
using namespace std;

void powerSet(string , int , string);

int main(){
    string str;
    cout<<"Enter a string : ";
    cin>>str;

    powerSet(str , 0 , "");
}

void powerSet(string str , int i , string cur){
    if(i == str.length()){
        cout<<cur<<endl;
        return;
    }

    powerSet(str , i + 1 , cur + str[i]);
    powerSet(str , i + 1 , cur);
}