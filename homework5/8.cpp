#include<iostream>
#include<stack>
using namespace std;

struct position
{
    int x;
    int y;
};


int main(){
    int n;
    cout<<"Enter the number of rows : ";
    cin>>n;
    int **a = new int*[n];
    for(int i = 0;i < n;i++)
        a[i] = new int [n];
    cout<<"\nEnter elements : "<<endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            cin>>a[i][j];
    }


    position p;
    stack<position> moves;
    int i = 0 , j = 0;
    while(i != n - 1 || j != n - 1){

        cout<<i<<" "<<j<<" "<<endl;
        p.x = i;
        p.y = j;
        a[i][j] = 1;
        moves.push(p);
    
        if(i + 1 < n && j + 1 < n && a[i + 1][j + 1] == 0){
            i++;
            j++;
        }
        else if(i + 1 < n && a[i + 1][j] == 0)
            i++;
        else if(j + 1 < n && a[i][j + 1] == 0)
            j++;
        else if(i + 1 < n && 0 <= j - 1 && a[i + 1][j - 1] == 0){
            i++;
            j--;
        }
        else if(0 <= i - 1 && j + 1 < n && a[i - 1][j + 1] == 0){
            i--;
            j++;
        }
        else if(0 <= j - 1 && a[i][j - 1] == 0)
            j--;
        else if(0 <= i - 1 && a[i - 1][j] == 0)
            i--;
        else if(0 <= i - 1 && 0 <= j - 1 && a[i - 1][j - 1] == 0){
            i--;
            j--;
        }
        else{
            moves.pop();
            i = moves.top().x;
            j = moves.top().y;
            moves.pop();
        }
    }

    while(!moves.empty()){
        cout<<moves.top().x + 1<<" , "<<moves.top().y + 1<<endl;
        moves.pop();
    }
}