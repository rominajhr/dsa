#include<iostream>
using namespace std;

void MaxMin(int [] , int);

int main(){
    int n , a[100];
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the array : ";
    for(int i = 0;i < n;i++)
        cin>>a[i];

    MaxMin(a , n);
}

void MaxMin(int arr[] , int n){
    int maxim = arr[0] , minim = arr[0];
    for(int i = 0;i < n;i+=2){
        if(arr[i] > arr[i + 1]){
            maxim = (arr[i] > maxim)?arr[i]:maxim;
            minim = (arr[i + 1] < minim)?arr[i + 1]:minim;
        }
        else{
            maxim = (arr[i + 1] > maxim)?arr[i + 1]:maxim;
            minim = (arr[i] < minim)?arr[i]:minim;
        }
    }

    if(n % 2){
        if(arr[n - 1] > maxim)
            maxim = arr[n - 1];
        else if(arr[n - 1] < minim)
            minim = arr[n - 1];
    }

    cout<<"Maximum : "<<maxim<<endl;
    cout<<"Minimum : "<<minim<<endl;
}

