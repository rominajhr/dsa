#include<iostream>
using namespace std;

double f(int , int);

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    cout<<"\n"<<f(1 , n)<<endl;

}

double f (int i , int n){
    if(i == n)
        return 1;

    if(i == 1){
        int m = 1;
        for(int i = 2;i <= n;i++){
            m *= i;
        }
        return (1 + (i + 1) * f(i + 1 , n)) / m;
    }

    return 1 + (i + 1) * f(i + 1 , n);
}