#include<iostream>
using namespace std;

bool isTranspose(int [][50] , int [][50] , int n);

int main(){
    int n , a[50][50] , b[50][50];
    cout<<"Enter the number of rows and columns : ";
    cin>>n;
    cout<<"Enter the first matrix : "<<endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            cin>>a[i][j];
    }

    cout<<"Enter the second matrix : "<<endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            cin>>b[i][j];
    }

    if(isTranspose(a , b , n))
        cout<<"Yes it is transpose"<<endl;
    else
        cout<<"No it is not transpose"<<endl;
}

bool isTranspose(int a[][50] , int b[][50] , int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(a[i][j] != b[j][i])
                return false;
        }
    }

    return true;
}