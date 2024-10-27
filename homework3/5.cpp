#include<iostream>
using namespace std;

void changeValue(int [][20] , int);

int main(){
    int n , a[20][20];
    cout<<"Enter the number of the array : ";
    cin>>n;
    cout<<"Enter the elements of the array : ";
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            cin>>a[i][j];
    }

    changeValue(a , n);

    cout<<"The new array : "<<endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void changeValue(int a[][20] , int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j)
                a[i][j]++;
            else if(i + j == n - 1)
                a[i][j]--;
            else if(j - i >= 1 && i + j < n - 1)
                a[i][j] += 2;
            else if(i - j >= 1 && i + j >= n)
                a[i][j] -= 2;
            else if(i - j >= 1 && i + j < n - 1)
                a[i][j] += 3;
            else
                a[i][j] -= 3;
        }
    }

    a[n / 2][n / 2]--;
}