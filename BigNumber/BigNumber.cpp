#include<iostream>
#include<string>
#include"BigNumber.h"

using namespace std;

BigNumber :: BigNumber (){
    size = 1;
    sign = false;
    digits[499] = 0;
}

BigNumber :: BigNumber(string str){
    size = str.length();
    
    if(str[0] == '-'){
        sign = true;
        size--;
        for(int i = size;i > 0;i--)
            digits[500 - i] = str[size - i + 1] - '0';
    }
    else{
        sign = false;
        for(int i = size;i > 0;i--)
            digits[500 - i] = str[size - i] - '0';
    }
}

BigNumber :: BigNumber(int num){
    int i = 1;
    size = 0;
    if(num > 0)
        sign = false;
    else{
        sign = true;
        num *= -1;
    }
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
    if(r.sign != sign){
        r.sign = sign;
        return this->minus(r);
    }

    BigNumber result;
    result.sign = sign;
    int carry = 0 , n = max(size , r.size) , k;
    for(int i = 1;i <= n;i++){
        if(i > size)
            k = r.digits[500 - i] + carry;
        else if(i > r.size)
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

    return result;
}

BigNumber BigNumber :: minus(BigNumber r){
    if(r.sign != sign){
        r.sign = sign;
        return this->sum(r);
    }
    
    BigNumber result;

    //asigning the sign of the rsult number
    if(size > r.size)
        result.sign = sign;
    else if(r.sign > sign)
        result.sign = !sign;
    else{
        if(digits[500 - size] > r.digits[500 - size])
            result.sign = sign;
        else
            result.sign = !sign;
    }

    bool endOfNum = false;
    if(result.sign == sign){
        for(int i = 1;i <= size;i++){
            if(i > r.size)
                r.digits[500 - i] = 0;
            if(digits[500 - i] >= r.digits[500 - i])
                result.digits[500 - i] = digits[500 - i] - r.digits[500 - i];
            else{
                for(int j = i + 1;j <= size;j++){
                    if(digits[500 - j]){
                        digits[500 - j]--;
                        break;
                    }
                    digits[500 - j] = 9;
                }

                digits[500 - i] += 10;
                result.digits[500 - i] = digits[500 - i] - r.digits[500 - i];
            }

            if(result.digits[500 - i])
                endOfNum = true;
            else
                endOfNum = false;
            
            if(endOfNum)
                result.size = i;
        }
    }
    else{
        for(int i = 1;i <= r.size;i++){
            if(i > size)
                digits[500 - i] = 0;
            if(digits[500 - i] <= r.digits[500 - i])
                result.digits[500 - i] = r.digits[500 - i] - digits[500 - i];
            else{
                for(int j = i + 1;j <= r.size;j++){
                    if(r.digits[500 - j]){
                        r.digits[500 - j]--;
                        break;
                    }
                    r.digits[500 - j] = 9;
                }

                r.digits[500 - i] += 10;
                result.digits[500 - i] = r.digits[500 - i] - digits[500 - i];
            }

            if(result.digits[500 - i])
                endOfNum = true;
            else
                endOfNum = false;
            
            if(endOfNum)
                result.size = i;
        }
    }



    return result;
    
}

ostream & operator << (ostream & strm, const BigNumber &b){
    if(b.sign)
        cout<<'-';
    
    for(int i = b.size;i > 0;i--)
        strm<<b.digits[500 - i];

    return strm;
}
