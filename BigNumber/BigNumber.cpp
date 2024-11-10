#include<iostream>
#include<string>
#include"BigNumber.h"

using namespace std;

BigNumber :: BigNumber (){
    size = 0;
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

    //asigning the sign of the result number
    if(*this <= r)
        result.sign = !sign;
    else
        result.sign = sign;

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

    if(!result.size){
        result.num = "\0";
        result.sign = false;
    }

    return result;
    
}

BigNumber BigNumber :: multiply (BigNumber r){
    BigNumber result , temp;

    string s , c;
    int number , k , carry;
    for(int i = size - 1;i >= 0;i--){
        number = num[i] - '0';
        s = "\0";
        carry = 0;

        //put zeros
        for(int k = 0;k < size - i - 1;k++)
            s += '0';

        for(int j = r.size - 1;j >= 0;j--){
            k = number * (r.num[j] - '0') + carry;
            c = (k % 10) + '0';
            c += s;
            s = c;
            carry = k / 10;
        }
        if(carry){
            c = carry + '0';
            c += s;
            s = c;
        }

        result = result.sum(s);

    }

    if(r.sign == sign)
        result.sign = false;
    else
        result.sign = true;

    return result;

}

BigNumber BigNumber :: division (BigNumber r){
    if(size < r.size || (size == r.size && num[0] < r.num[0]))
        return 0;

    string s;
    BigNumber temp(*this) , result;
    while(temp.size - r.size > 1){
        int n = temp.size - r.size - 1;
        s = "1";
        while(n--)
            s +='0';

        temp = temp.minus(r.multiply(s));
        result = result.sum(s);

    }

    for(int i = 0;i < 100;i++){
        temp = temp.minus(r);
        if(!temp.sign)
            result = result.sum(1);
        else
            break;
    }

    if(r.sign == sign)
        result.sign = false;
    else
        result.sign = true;

    return result;
}

BigNumber BigNumber :: factorial(){
    BigNumber temp(1) , result(1);
    while(temp <= *this){
        result = result.multiply(temp);
        temp = temp.sum(1);
    }

    return result;
}

BigNumber BigNumber :: power(int n){
    BigNumber result(1);
    for(int i = 2;i <= n/2;i++){
        if(n % i == 0){
            result = this->power(i);
            return result.power(n / i);
        }

    }

    while(n--)
        result = result.multiply(*this);

    return result;
}

BigNumber BigNumber :: karatsuba(BigNumber r){
    BigNumber result , tempb1_1 , tempb1_2 , tempb2_1 , tempb2_2 , k1 , k2 , k3;
    int n = max(size , r.size);
    if(n <= 1){
        int number = (num[0] - '0') * (r.num[0] - '0');
        return number;
    }

    for(int i = 1;i <= n/2;i++){
        if(i < size){
            tempb1_1.num += num[size - i];
            tempb1_1.size++;
        }
        if(i < r.size){
            tempb2_1.num += r.num[r.size - i];
            tempb2_1.size++;
        }
    }

    for(int i = n / 2 + 1;i <= n;i++){
        if(i < size){
            tempb1_2.num += num[size - i];
            tempb1_2.size++;
        }
        if(i < r.size){
            tempb2_2.num += r.num[r.size - i];
            tempb2_2.size++;
        }
    }

    cout<<tempb1_1<<" "<<tempb1_2<<" "<<tempb2_1<<" "<<tempb2_2<<endl;
    
    k1 = tempb1_1.karatsuba(tempb2_1);
    k2 = tempb1_2.karatsuba(tempb2_2);
    k3 = tempb2_2.sum(tempb1_2).karatsuba(tempb1_1.sum(tempb2_1));

    string s = "1";
    for(int i = 1;i <= n/2;i++)
        s += '0';
    
    result = result.sum(k1);
    result = result.sum(k3.multiply(s));

    for(int i = n/2 + 1;i <= n;i++)
        s += '0';

    result = result.sum(k2.multiply(s));

    return result;

}



bool operator <= (const BigNumber & b1 , const BigNumber & b2){
    if(b1.size > b2.size)
        return false;

    if(b1.size == b2.size){
        for(int i = 0;i < b1.size;i++){
            if(b1.num[i] > b2.num[i])
                return false;
        }
    }

    return true;
}

ostream & operator << (ostream & strm, const BigNumber &b){
    if(b.sign)
        cout<<'-';

    strm<<b.num;

    return strm;
}

