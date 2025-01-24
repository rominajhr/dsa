#include<iostream>
#include"heap.h"
using namespace std;

void Heap :: buildMaxHeap(int d){
    data[length] = d;
    this->isMaxHeap(length);
    length++;
}

void Heap :: isMaxHeap(int i){
    
    while(i > 0 && data[i] > data[(i - 1) / 2]){
        int temp = data[i];
        data[i] = data[(i - 1) / 2];
        data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }

}

void Heap :: buildMinHeap(){
    int i = length - 1;
    while(i > 0){
        int temp = data[i];
        data[i] = data[0];

        int j = 0;
        while(true){
            int pre = j;

            int left = j * 2 + 1;
            int right = j * 2 + 2;

            if(left < i){
                if(right < i && data[right] > data[left])
                    j = right;   
                else
                    j = left;
            }
            else if(right < i)
                j = right;
            else
                break;

            data[pre] = data[j];
        }

        data[j] = temp;

        this->isMaxHeap(j);
        i--;
    }
}

void Heap :: printTree(){
    for(int i = 0;i < length;i++)
        cout<<data[i]<<" ";
    
    cout<<endl;
}