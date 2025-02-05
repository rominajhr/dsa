#ifndef HUFFMAN_H
#define HUFFMAN_H
#include<iostream>
#include"queue.h"
using namespace std;

void huffman(string &);
void frequency(int [] , string &);
Node * buildTree(int []);
void enCode(string & , Node * , int []);
void hufCode(Node * , string []);
void deCode(string & , Node *);


#endif