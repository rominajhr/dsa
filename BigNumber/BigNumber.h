#include<iostream>
#include<string>

using namespace std;

#ifndef BIGNUMBER_H
#define BIGNUMBER_H

class BigNumber{
    int size;
    bool sign;
    string num;

    public:
        BigNumber();
        BigNumber(string);
        BigNumber(int);

        void shiftR();
        void shiftR(int);
        void shiftL();
        void shiftL(int);

        BigNumber sum(BigNumber);
        BigNumber minus(BigNumber);
        BigNumber multiply(BigNumber);
        BigNumber division(BigNumber);
        BigNumber factorial();
        BigNumber power(int);
        BigNumber karatsuba(BigNumber);

        friend ostream & operator << (ostream & , const BigNumber &);
        friend bool operator <= (const BigNumber & , const BigNumber &);
};

#endif
