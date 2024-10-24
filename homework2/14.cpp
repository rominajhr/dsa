#include<iostream>
using namespace std;

int mainNum(int [] , int );

int main(){
    int n , a[100];
    cout<<"Enter size of the array : ";
    cin>>n;
    cout<<"Enter the array : ";
    for(int i = 0;i < n;i++)
        cin>>a[i];

    cout<<"\nThe main number of the array is : "<<mainNum(a , n)<<endl;

}

int mainNum(int arr[] , int n){
    int mainnum = arr[0] , counter = 1;
    for(int i = 1;i < n;i++){
        if(arr[i] == mainnum || counter == 0){
            counter++;

            if(counter == 1)
                mainnum = arr[i];
        }
        else{
            if(counter > 0)
                counter--;
        }
        
        cout<<counter<<" "<<mainnum<<endl;

    }

    if(counter <= 0)
        return -1;

    return mainnum;
}