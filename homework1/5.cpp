#include<iostream>
using namespace std;

int maxi(int [] , int);

int main(){
    int a[100] , n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i];

    cout<<"Maximum : "<<maxi(a , n)<<endl;
}

int maxi(int arr[] , int n){
    if(n == 1)
        return arr[0];

    int arrayMux = maxi(arr , n - 1);
    if(arrayMux < arr[n - 1])
        return arr[n - 1];

    return arrayMux;
}