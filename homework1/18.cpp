#include<iostream>
#include<string.h>
using namespace std;

bool isDuplicate(string);

int main(){
    string s;
    cout<<"Enter a string : ";
    cin>>s;

    if(isDuplicate(s))
        cout<<"\nIt's Duplicate."<<endl;
    else
        cout<<"\nIt's not Duplicate."<<endl;
}

bool isDuplicate(string s){
    int size = s.length();

    if(!size)
        return true;
    if(size == 1)
        return false;


    string s1 = "";
    for(int i = 0;i < size/2;i++){
        if(s[i] != s[size/2 + i])
            return false;
        if(i)
            s1 += s[i];
    }
    
    return isDuplicate(s1);
}