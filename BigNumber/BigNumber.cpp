#include<iostream>
#include<string>
#include"BigNumber.h"

using namespace std;

BigNumber :: BigNumber (){
    size = 1;
    sign = false;
    num = '\0';
}

BigNumber :: BigNumber(string str){
    size = str.length();
    
    if(str[0] == '-'){
        num = str[1];
        sign = true;
        for(int i = 2;i < size;i++)
            num += str[i];
        size--;
    }
    else{
        sign = false;
        num = str;
    }
}

BigNumber :: BigNumber(int number){
    int i = 1;
    size = 0;
    string s;
    num = '\0';
    if(number > 0)
        sign = false;
    else{
        sign = true;
        number *= -1;
    }
    while(number){
        size++;
        s = number % 10 + '0';
        s += num;
        num = s;
        number /= 10;
        i++;
    }
}


void BigNumber :: shiftR(){
    num[size - 1] = '\0';
    size--;
}

void BigNumber :: shiftR(int n){
    for(int i = 1;i <= n;i++)
        num[size - i] = '\0';

    size -= n;
}

void BigNumber :: shiftL(){
    size++;
    num += '0';
}

void BigNumber :: shiftL(int n){
    size += n;
    for(int i = 0;i < n;i++)
        num += '0';
}


BigNumber BigNumber :: sum(BigNumber r){
    if(r.sign != sign){
        r.sign = sign;
        return this->minus(r);
    }

    BigNumber result;
    result.sign = sign;
    int carry = 0 , n = max(size , r.size) , k;
    string s;

    for(int i = 1;i <= n;i++){
            k = carry;
            if(size - i >= 0)
                k += num[size - i] - '0';
            if(r.size - i >= 0)
                k += r.num[r.size - i] - '0';

            s = k % 10 + '0';
            s += result.num;
            result.num = s;
            carry = k / 10;
     
    }

    result.size = n;
    if(carry){
        s = carry + '0';
        s += result.num;
        result.num = s;
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
    else if(r.size > size)
        result.sign = !sign;
    else{
        if(num[0] > r.num[0])
            result.sign = sign;
        else
            result.sign = !sign;
    }

    bool endOfNum = false;
    int k;
    string s;
    if(result.sign == sign){
        for(int i = 1;i <= size;i++){
            if(r.size - i < 0)
                k = num[size - i] - '0';
            else{
                if((num[size - i] - '0') >= (r.num[r.size - i] - '0'))
                    k = (num[size - i] - '0') - (r.num[r.size - i] - '0');
                else{
                    for(int j = i + 1;j <= size;j++){
                        if(num[size - j] - '0'){
                            num[size - j]--;
                            break;
                        }

                        num[size - j] = 9 + '0';
                    }
                    k = 10 + (num[size - i] - '0') - (r.num[r.size - i] - '0');
                }
            }

            if(k)
                endOfNum = true;
            else
                endOfNum = false;

            if(endOfNum)
                result.size = i;

            
            s = k + '0'; 
            s += result.num;
            result.num = s;
        }
    }
    else{
        for(int i = 1;i <= r.size;i++){

            if(size - i < 0)
                k = r.num[r.size - i] - '0';
            else{
                if((r.num[r.size - i] - '0') >= (num[size - i] - '0'))
                    k = (r.num[r.size - i] - '0') - (num[size - i] - '0');
                else{
                    for(int j = i + 1;j <= r.size;j++){
                        if(r.num[r.size - j] - '0'){
                            r.num[r.size - j]--;
                            break;
                        }

                        r.num[r.size - j] = 9 + '0';
                    }

                    k = (10 + r.num[r.size - i] - '0') - (num[size - i] - '0');
                }
            }

            if(k)
                endOfNum = true;
            else
                endOfNum = false;

            if(endOfNum)
                result.size = i;

            
            s = k + '0'; 
            s += result.num;
            result.num = s;
        }
    }


    int zeros = 0;
    for(int i = 0;result.num[i] == '0' && i <= result.size;i++)
        zeros++;

    for(int i = 0;i < result.size - zeros + 1;i++)
        result.num[i] = result.num[i + zeros];

    for(int i = 0;i < zeros;i++)
        result.num[result.size - i] = '\0';

    result.size -= zeros;


    return result;
    
}

ostream & operator << (ostream & strm, const BigNumber &b){
    if(b.sign)
        cout<<'-';

    strm<<b.num;

    return strm;
}
