#include<iostream>
#include<stack>
#include"huffman.h"
using namespace std;

void huffman(string & str){

    bool isHufCode = false;
    if(str[0] >= '0' && str[0] <= '9')
        isHufCode = true;
    
    int rep[54] = {0};
    frequency(rep , str);
    Node * treeRoot = buildTree(rep);
    if(isHufCode)
        deCode(str , treeRoot);
    else
        enCode(str , treeRoot , rep);
}

void frequency(int rep [] , string & str){
    int len = str.length();
    if(str[0] >= '0' && str[0] <= '9'){
        int k = 0 , temp = 0;                                   //writing number of any letter
        while(str[k] != '\n'){
            if(str[k] >= 'a' && str[k] <= 'z'){
                rep[str[k] - 'a'] = temp;
                temp = 0;
            }
            else if(str[k] >= 'A' && str[k] <= 'Z' ){
                rep[str[k] - 'A' + 26] = temp;
                temp = 0;
            }
            else if(str[k] == '/'){
                rep[52] = temp;
                temp = 0;
            }
            else if(str[k] == '\\'){
                rep[53] = temp;
                temp = 0;
            }
            else{
                temp *= 10;
                temp += str[k] - '0';
            }

            k++;
            
        }

        str = str.substr(k + 1 , len);
        
    }
    else{    
        for(int i = 0;i < len;i++){                                 //finding number of repeates
            if(str[i] == ' ')
                rep[52]++;
            else if(str[i] == '\n')
                rep[53]++;
            else if(str[i] >= 'a' && str[i] <= 'z')
                rep[str[i] - 'a']++;
            else
                rep[str[i] - 'A' + 26]++;
            
        }
    }
}

Node * buildTree(int rep[]){
    Queue q;
    char alphab;
    for(int i = 0;i < 54;i++){                                  //making nodes
        if(rep[i] > 0){
            if(i == 52)
                alphab = ' ';
            else if(i == 53)
                alphab = '\n';
            else if(i < 26)
                alphab = 'a' + i;
            else
                alphab = 'A' + (i - 26);


            Node *temp = new Node(rep[i] ,alphab);
            q.enQueue(temp);
        }
    }

    while(true){                                                //making tree
        Node * temp1 , * temp2;
        if(!q.isEmpty())
            temp1 = q.deQueue();
        if(!q.isEmpty())
            temp2 = q.deQueue();
        else{
            q.enQueue(temp1);
            break;
        }

        Node * root = new Node(temp1 , temp2);
        q.enQueue(root);
    }

    return q.deQueue();

}

void hufCode(Node * node, string code[] , string str){
    if(!node->left && !node->right){
        if(node->ch == ' ')
            code[52] = str;
        else if(node->ch == '\n')
            code[53] = str;
        else if(node->ch >= 'a' && node->ch <= 'z')
            code[node->ch - 'a'] = str;
        else
            code[node->ch - 'A' + 26] = str;
    }
    else{
        hufCode(node->left , code ,str + "0");
        hufCode(node->right , code , str + "1");
    }
}

void enCode(string & str , Node * root , int rep[]){                        
    string code[54];
    hufCode(root , code , "");                                  //find each letter code    

    string temp;
    int len = str.length();
    for(int i = 0;i < len;i++){                                 //replace any letter with code
        if(str[i] == ' ')
            temp += code[52];
        else if(str[i] == '\n')
            temp += code[53];
        else if(str[i] >= 'a' && str[i] <= 'z')
            temp += code[str[i] - 'a'];
        else
            temp += code[str[i] - 'A' + 26];
    }


    str = "";
    for(int i = 0;i < 54;i++){                                  //add each letter code to the file
        if(rep[i] == 0)
            continue;
            
        string x;
        int digits = 0;
        while(rep[i]){
            x += (rep[i] % 10) + '0';
            rep[i] /= 10;
            digits++;
        }

        for(int j = 0;j < digits;j++)
            str += x[digits - 1 - j];

        if(i == 52)
            str += '/';
        else if(i == 53)
            str += '\\';
        else if(i < 26)
            str += 'a' + i;
        else
            str += 'A' + (i - 26);

    }

    str += '\n';


    int bin = 0;
    len = temp.length();
    for(int i = 0;i <len;i++){
        bin <<= 1;
        bin += temp[i] - '0';
        if(i % 8 == 7){
           str += bin;
           bin = 0; 
        }
    }

    len = 8 - (len % 8);
    for(int i = 0;i < len;i++){
        bin <<= 1;
        if(i == 0)
            bin += 1;
    }
    str += bin; 

}


void deCode(string & str , Node * root){

    int len = str.length() , bin;
    string temp;
    for(int i = 0;i < len;i++){                                 //changr string to binary
        bin = str[i];
        for(int j = 0;j < 8;j++ , bin <<= 1)
            temp += ((bin & 128) >> 7) + '0';
    }


    Node * head = root;
    int end = temp.length();
    str = "";
    while(temp[end - 1] != '1')                                  //find end of real binary code
        end--;


    for(int i = 0;i < end - 1;i++){
        if(temp[i] == '0'){
            head = head->left;
        }
        else{
            head = head->right;
        }

        if(!head->left && !head->right){
            str += head->ch;
            head = root;
        }
    }


}
