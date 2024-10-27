#include<iostream>
using namespace std;

int fib(int);

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    cout<<"a["<<n<<"] = "<<fib(n);
}

int fib(int n){
    if(n == 0 || n == 1)
        return 1;

    int* a = new int[n];
    a[0] = a[1] = 1;

    for(int i = 2;i < n;i++)
        a[i] = a[i - 1] + a[i - 2];

    return a[n - 1];
}
