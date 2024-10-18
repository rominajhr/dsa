#include<iostream>
using namespace std;

void h(int , char , char , char);

int main(){
    int n;
    cout<<"Enter the number of disks : ";
    cin>>n;

    h(n , 's' , 'a' , 'd');
}

void h (int n , char s , char a , char d){
    if(n == 1)
        cout<<s << " -> " << d<<endl;
    else{
        h(n - 1 , s , d , a);
        cout<<s << " -> " << d<<endl;
        h(n - 1 , a , s , d);
    }
}