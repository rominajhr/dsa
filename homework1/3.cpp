#include<iostream>
using namespace std;

void rev(int [] , int , int);

int main(){
    int arr[100] , n;
    cout<<"Enter size of thr array : ";
    cin>>n;
    cout<<"Enter the array : ";
    for(int i = 0;i < n;i++)
        cin>>arr[i];

    rev(arr , 0 , n - 1);
    cout<<"New array : \n";

    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void rev(int arr[] , int i , int j){
    if(j - i > 1)
        rev(arr , i + 1 , j - 1); 

    int temp;    
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;


}   