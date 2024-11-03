#include<iostream>
#include<string>

using namespace std;

#ifndef BIGNUMBER_H
#define BIGNUMBER_H

class BigNumber{
    int size;
    bool sign;
    int digits[500];

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

        friend ostream & operator << (ostream & , const BigNumber &);
};

#endif
