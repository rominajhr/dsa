#include<iostream>
using namespace std;

int findSecondMax(int [] , int , int , int);

int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter elements : ";
    int * a = new int[n];
    for(int i = 0;i < n;i++)
        cin>>a[i];

    cout<<"Second max : "<<findSecondMax(a , 0 , n - 1 , 0)<<endl;    
}

int findSecondMax(int a[] , int s , int e , int call){
    if(s < e){
        int mid = (s + e) / 2;
        int max1 = findSecondMax(a , s , mid , call + 1);
        int max2 = findSecondMax(a , mid + 1 , e , call + 1);
        if(call){
            if(max1 > max2)
                return max1;
            else
                return max2;
        }
        else{
            if(max1 > max2)
                return max2;
            else
                return max1;
        }
    }
    return a[s];

}
