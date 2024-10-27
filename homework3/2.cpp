#include<iostream>
using namespace std;

double c(int , int);

int main(){
    int n , r;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter r : ";
    cin>>r;

    cout<<"c("<<n<<","<<r<<") = "<<c(n , r)<<endl;
}

double c(int n , int r){
    if(n < r)
        return 0;

    int* a = new int[n - r + 1];
    a[0] = 1;
    for(int i = 1;i < n - r + 1;i++)
        a[i] = a[i - 1] * (r + i) / i;

    return a[n - r];
}