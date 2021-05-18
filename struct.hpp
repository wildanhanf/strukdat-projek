#pragma once
#include <iostream>

// Struct Nasabah
struct nasabah
{
    char nama[50];
    char jk[1];
    nasabah* next;
};

// Struck Queue
struct queue 
{
    nasabah* Head; 
    nasabah* Tail;
};

// Struck Stack
struct stack
{
    std::string nama;
    std::string jk;
    int no;
    stack* next;
};

// Struck Teller
struct teller
{
    int no;
    teller* next;
    queue antrian;
};

typedef nasabah* pointerN;
typedef teller* pointerT;
typedef stack* pointerH;