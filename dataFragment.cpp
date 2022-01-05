/************************************************************
 ------------------------------------------------------------
Sarah Bass
Data Fragmentation
CS 41 Data Structures

-------------------------------------------------------------
In class demo of memory usage
-------------------------------------------------------------
************************************************************/

#include <stdio.h>      
#include <stdlib.h>     
#include <iostream>
#include <string>

using namespace std;

struct Fragmentation {
    int x;
    double y;
    bool z;
    short t;
    char a;
    long b;
    string stringname;
};

struct Empty{

};

struct Boolstruct{
    bool sizetest;
};

struct intstruct{
    int sizetester;
};

class Classsize{
int variable;
};

class ClassEmpty{

};




int main (void)
{
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of short : " << sizeof(short) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of long : " << sizeof(long) << endl;
    cout << "Size of bool : " << sizeof(bool) << endl;
    cout << "Size of string : " << sizeof(string) << endl;
    cout << "Size of Empty struct : " << sizeof(Empty) << endl;
    cout << "Size of full struct : " << sizeof(Fragmentation) << endl;
    cout << "Size of bool struct : " << sizeof(Boolstruct) << endl;
    cout << "Size of int struct : " << sizeof(intstruct) << endl;
    cout << "Size of empty class : " << sizeof(ClassEmpty) << endl;
    cout << "Size of int class : " << sizeof(Classsize) << endl;
    
    return 0;
}

