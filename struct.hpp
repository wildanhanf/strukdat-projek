#pragma once
#include <iostream>

const int maxNasabah = 10;

struct nasabah
{
    char nama[50];
    nasabah* next;
};

struct queue 
{
    nasabah* Head; // 
    nasabah* Tail;
};

struct stack
{
    std::string nama;
    stack* next;
};

struct teller
{
    int no;
    teller* next;
    //nasabah* first_nasabah;
    queue antrian; // 
    stack history;
};


stack Top;
typedef nasabah* pointerN;
typedef teller* pointerT;
typedef stack* pointerH;