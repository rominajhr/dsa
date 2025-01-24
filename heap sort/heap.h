#ifndef HEAP_H
#define HEAP_H

class Heap{

    int data[500];
    int length;
    public:
        Heap(){length = 0;}
        void buildMaxHeap(int);
        void isMaxHeap(int);
        void buildMinHeap();
        void printTree();
};

#endif
