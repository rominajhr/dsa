#include<iostream>
#include<string>
#include"BigNumber.h"

using namespace std;

BigNumber :: BigNumber (){
    size = 1;
    digits[499] = 0;
}

BigNumber :: BigNumber(string str){
    size = str.length();
    for(int i = size;i > 0;i--)
        digits[500 - i] = str[i];
}

BigNumber :: BigNumber(int num){
    int i = 1;
    while(num){
        size++;
        digits[500 - i] = num % 10;
        num /= 10;
        i++;
    }
}


void BigNumber :: shiftR(){
    size--;
    for(int i = 1 ; i <= size ;i++)
        digits[500 - i] = digits[500 - i - 1];

}

void BigNumber :: shiftR(int n){
    size -= n;
    for(int i = 1;i <= size;i++)
        digits[500 - i] = digits[500 - i - n];

}

void BigNumber :: shiftL(){
    for(int i = size;i > 0;i--)
        digits[500 - i - 1] = digits[500 - i];

    digits[499] = 0;
    size++;
}

void BigNumber :: shiftL(int n){
    for(int i = size;i > 0 ;i--)
        digits[500 - i - n] = digits[500 - i];

    for(int i = 1;i <= n;i++)
        digits[500 - i] = 0;
    size += n;
}


BigNumber BigNumber :: sum(BigNumber r){
    BigNumber result;
    int carry = 0 , n = max(size , r.size) , k;
    for(int i = 1;i <= n;i++){
        if(n > size)
            k = r.digits[500 - i] + carry;
        else if(n > r.size)
            k = digits[500 - i] + carry;
        else
            k = digits[500 - i] + r.digits[500 - i] + carry;
        
        result.digits[500 - i] = k % 10;
        carry = k / 10;
    }
    result.size = n;

    if(carry){
        result.digits[500 - n - 1] = carry;
        result.size++;
    }
}
