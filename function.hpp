#pragma once
#include<iostream>
#include "struct.hpp"


// =========> Keadaan Awal List, Queue, dan Stack <======== // 
void first_list(pointerT &Head){
    Head = nullptr;
}

void first_queue(queue& q){
    q.Head = nullptr; //
    q.Tail = nullptr;
}
 
void first_stack(pointerH &Top){
    Top = nullptr;
}


// ========> Create Teller, Nasabah, dan History <========= 
void create_teller(pointerT &newT, int no){
    newT = new teller;
    newT->no = no;
    newT->next = nullptr;
    newT->antrian = queue {nullptr, nullptr}; //
}

void create_nasabah(pointerN &newN){ 
    std::cout << "----------------------------------------------\n";
    newN = new nasabah;
    std::cout << "Nama Nasabah\t\t: ";
    std::cin >> newN->nama;
    std::cout << "Jenis Kelamin (L/P)\t: ";
    std::cin >> newN->jk;
    newN->next = nullptr;
}

void create_stack(pointerH &newH, pointerN pDel_N, int key){
    newH = new stack;
    newH->nama = (std::string)pDel_N->nama;
    newH->jk = (std::string)pDel_N->jk;
    newH->no = key;
    newH->next = nullptr;

}


// ========> Fungsi Teller (Single Linked List) <========= //
void search_teller(pointerT Head, int key, int &status, pointerT& pCari){
    status = 0;
    pCari = Head;
    while (status == 0 && pCari != nullptr)
    {
        if(pCari->no == key){
            status = 1;
            
        }else{
            pCari = pCari->next;

        }
    }

}

void insert_last(pointerT &Head, pointerT newT){
    pointerT last;
    if(Head == nullptr){
        Head = newT;
    }else{
        last = Head;
        while (last->next)
        {
            last = last->next;
        }
        last->next = newT;
    }
}

void traversal_teller(pointerT Head){
    pointerT pBantu;
    std::string teller[3] = {"Setor Tunai","Pembuatan Rekening","Cetak Buku Tabungan"};
    int i = 0;
    if(Head == nullptr){
        std::cout << "Teller Kosong" << std::endl;
    }else{
        pBantu = Head;
        do
        {
            std::cout << pBantu->no << ". " << teller[i] <<std::endl;
            pBantu = pBantu->next;
            i++;
        } while (pBantu != nullptr);
    }
}


// =========> Fungsi Nasabah (Queue) <========= //
void enqueueN(pointerT Head, queue& q, int key, pointerN newN){
    pointerT pCari;
    pointerN tmp, pBantu;
    int status;

    std::cout << "Pilihan Teller\t\t: ";
    std::cin >> key;
    search_teller(Head, key,status, pCari);
    if(status){
        if(pCari->antrian.Head == nullptr && pCari->antrian.Tail == nullptr){ //
            pCari->antrian.Head = newN; //
            pCari->antrian.Tail = newN; //
        
        }else{
           pCari->antrian.Tail->next = newN;
           pCari->antrian.Tail = newN; 
        }
    
    }else{
        std::cout << "\n----------------------------------------------\n";
        std::cout << "Teller tidak tersedia !\n";
        std::cout << "----------------------------------------------\n";
         
    }
}

bool isEmpty(pointerH Top);
void push(pointerH newH, pointerH &Top);

void dequeueN(pointerT Head, int key, pointerN &pDel_N, pointerT &pCari, pointerH &newH, pointerH &Top){
    pointerN tmp, preclast;
    int status;

    std::cout<<"==============================================" <<std::endl;
    std::cout<<"              Pemanggilan Nasabah             " <<std::endl;       
    std::cout<<"==============================================" <<std::endl;
    traversal_teller(Head);
    std::cout<<"----------------------------------------------" <<std::endl;
    std::cout << "Pilihan Teller\t: ";
    std::cin >> key;
    search_teller(Head, key, status, pCari);

    if(status){
        if(pCari->antrian.Head == nullptr && pCari->antrian.Tail == nullptr){
            std::cout<<"\n----------------------------------------------" <<std::endl;
            std::cout << "Tidak Ada Antrian Nasabah\n";
            std::cout<<"----------------------------------------------" <<std::endl;
        
        }else if (pCari->antrian.Head->next == nullptr){
            pDel_N = pCari->antrian.Head;
            pCari->antrian.Head = nullptr;
            pCari->antrian.Tail = nullptr;
            create_stack(newH,pDel_N, key);
            isEmpty(Top);
            push(newH,Top); 
            std::cout <<"----------------------------------------------" <<std::endl;
            std::cout << "Nasabah " << pDel_N->nama << " silahkan mengunjungi Teller " << key << std::endl;
        }else{
            pDel_N = pCari->antrian.Head; 
            pCari->antrian.Head = pCari->antrian.Head->next;
            pDel_N->next = nullptr;
            std::cout<<"----------------------------------------------" <<std::endl;
            std::cout << "Nasabah " << pDel_N->nama << " silahkan mengunjungi Teller " << key << std::endl;
            create_stack(newH,pDel_N,key);
            isEmpty(Top);
            push(newH,Top); 
        } 
        
    }else{
        std::cout<<"\n----------------------------------------------" <<std::endl; 
        std::cout << "Teller Tidak Tersedia\n";
        std::cout<<"----------------------------------------------"   <<std::endl;
            
    }
    
}

void search_nasabah(pointerT Head, int &status, pointerT &pCari_T, pointerT &prev_T_cari, pointerN &pCari_N, pointerN &prev_N_cari, char key[]){    
    status = 0;
    pCari_T = Head;
    prev_T_cari = nullptr;

    while (status  == 0 && pCari_T != nullptr)
    {
        //pCari_N = pCari_T->first_nasabah;
        pCari_N = pCari_T->antrian.Head;
        prev_N_cari = nullptr;

        while (status == 0 && pCari_N != nullptr)
        {
            if (pCari_N->nama == (std::string)key)
            {
                status = 1;
            
            }else{
                prev_N_cari = pCari_N;
                pCari_N = pCari_N->next;

            }
            
        }
        prev_T_cari = pCari_T;
        pCari_T = pCari_T->next;
        
    }
    
}

void denqueueN_search(pointerT Head, int key, pointerN &pDel_N, pointerN &pBantu,pointerT &pCari){
    int status;
    int i = 0;

    std::cout << "----------------------------------------------\n";
    std::cout << "Pilihan Teller yang diinginkan\t: ";
    std::cin >> key;
    search_teller(Head, key, status, pCari);
    
    if(status){
        pBantu = pCari->antrian.Head;
        while (pBantu != nullptr)
        {
            i++;
            pBantu = pBantu->next;
        }
        
        for (int j = 0; j < i; j++)
        {
            if(pCari->antrian.Head == nullptr && pCari->antrian.Tail == nullptr){
                std::cout << "Tidak Ada Antrian Nasabah\n";
            
            }else if(pCari->antrian.Head->next == nullptr){
                pBantu = pCari->antrian.Head;
                pCari->antrian.Head = nullptr;
                pCari->antrian.Tail = nullptr;

            }
            else{
                pBantu = pCari->antrian.Head;
                pCari->antrian.Head = pBantu->next;
                pBantu->next = nullptr;

            }
        }
    
    }else{
        std::cout << "\n----------------------------------------------\n";
        std::cout << "Teller tidak tersedia !\n";
        std::cout <<"----------------------------------------------" <<std::endl; 
    }    
}

void updateN(pointerT Head, char key[], pointerN newN){
    int status;
    pointerN pCari_N, prevCari_N;
    pointerT pCari_T, prevCari_T;

    std::cout << "Nama Nasabah\t: ";
    std::cin  >> key;
    search_nasabah(Head,status, pCari_T, prevCari_T, pCari_N, prevCari_N, key);
    if (status)
    {
        std::cout << "----------------------------------------------\n";
        std::cout << "\tMasukkan Data Baru Nasabah\n";
        create_nasabah(newN);
        pCari_T = prevCari_T;

        if (pCari_N == pCari_T->antrian.Head)
        {
            if (pCari_N->next == nullptr)
            {
                pCari_N = nullptr;
                pCari_T->antrian.Head = newN;
                newN->next = nullptr;

            }else{
                newN->next = pCari_N->next;
                pCari_N->next = nullptr;
                pCari_T->antrian.Head = newN;
            }
            
        }else{
            if(pCari_N->next == nullptr){
                prevCari_N->next = newN;
                newN->next = nullptr;
                pCari_N = nullptr;

            }else{
                newN->next = pCari_N->next;
                prevCari_N->next = newN;
            }
        }
        
    }else{
        std::cout <<"\n----------------------------------------------" <<std::endl;
        std::cout << "Nasabah tidak ditemukan!\n";
        std::cout <<"----------------------------------------------" <<std::endl;
    }
    
}

void traversal_pelayanan(pointerT Head){
    pointerT T;
    pointerN Tmp;
    int status;

    T = Head;
    while (T != nullptr)
    {
        std::cout<<"\n----------------------------------------------"<< std::endl;
        std::cout<<"            Data Antrian Teller "<< T->no    << std::endl;       
        std::cout<<"----------------------------------------------"<< std::endl;

        if (T->antrian.Head == nullptr)
        {
            std::cout << "Belum Ada Nasabah\n";
            std::cout<<"----------------------------------------------\n";
        
        }else{
            int i = 1;
            Tmp = T->antrian.Head;
            std::cout << "No\tNama\t\tJenis Kelamin\n";
            std::cout<<"----------------------------------------------\n";
    
            while (Tmp != nullptr)
            {
                std::cout << i << '\t' << Tmp->nama << "\t\t" << Tmp->jk << '\n';
                Tmp = Tmp->next;
                i++;
            }
            std::cout<<"----------------------------------------------\n";

        }
        T = T->next;   
    }
    
}

// =========> Fungsi History (Stack) <========= //
bool isEmpty(pointerH Top){
    if (Top == nullptr){
        return true;

    }else{
        return false;
    }
    
}

void push(pointerH newH, pointerH &Top){
        
    if(isEmpty(Top)){
        Top = newH;

    }else{
        newH->next = Top;
        Top = newH;
    }

}
 
void print_history(pointerH Top){
    pointerH pBantu = Top;
    
    if(isEmpty(Top)){
        std::cout << "Belum ada Nasabah yang Dilayani\n";
        std::cout <<"==============================================" <<std::endl;

    }else{
        int i = 1;
        std::cout << "No\tNama\t\tJenis Kelamin\tTeller\n";
        std::cout<<"==============================================" <<std::endl;
        do
        {
            std::cout << i << '\t' <<  pBantu->nama << "\t\t" << pBantu->jk << "\t\t" << pBantu->no <<'\n';
            pBantu = pBantu->next;
            i++;
        } while (pBantu != nullptr);
        std::cout<<"==============================================" <<std::endl;    
    }
}
