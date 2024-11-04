#include<iostream>
using namespace std;

void khayamPascal(int);

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    khayamPascal(n);
}

void khayamPascal(int n){
    int* digits = new int[n]();
    int oldDig , newDig;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < n - i;j++)
            cout<<" ";
        for(int j = 0;j < i;j++){
            newDig = digits[j];
            if(j == 0 || j == i - 1)
                digits[j] = 1;
            else
                digits[j] += oldDig;

            oldDig = newDig;
            cout<<digits[j]<<" ";
        }
        cout<<endl;
    }
}