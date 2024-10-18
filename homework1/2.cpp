#include<iostream>
using namespace std;

double aver(int [] , int , int);

int main(){
    int a[100] , n;
    cout<<"Enter size of thr array : ";
    cin>>n;
    cout<<"Enter the array : ";
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    
    cout<<"\naverage : "<<aver(a , n , n)<<endl;
}

double aver(int arr[] , int n , int i){
    if(i == 1)
        return arr[0];

    if(i == n)
        return (arr[i - 1] + aver(arr , n , i - 1)) / n;

    return arr[i - 1] + aver(arr , n , i - 1);
    
}