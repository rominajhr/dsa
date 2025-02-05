#include<iostream>
#include<fstream>
#include<string.h>
#include"huffman.h"
using namespace std;

int main(){

    cout<<"\nEnter the name of the file you want to open : ";
    char nameOfFile[50];
    cin.getline(nameOfFile , 50);
    strcat(nameOfFile , ".txt");
    FILE *pf = fopen(nameOfFile , "r");
    if(!pf){
        cout<<"\nThere is no such file!\n";
    }

    char line[100];
    string str;
    while(fgets(line , 100 , pf)){
        str += line;
    }

    fclose(pf);

    huffman(str);

    ofstream fw(nameOfFile);
    fw << str;
    fw.close();

}
