#include <iostream>
#include "function.hpp"

int main(){
    queue q;
    pointerT Head, HeadN, newT;
    pointerN newN, pDel_N;
    pointerH Top, newH;
    char Key[50];
    int menu,key;
    int no[3] = {1,2,3};

    // Keadaan Awal List
    first_list(Head);
    // Keadaan Awal Queue
    first_queue(q);
    // Keadaan Awal Stack
    first_stack(Top);

    // Input No Teller
    for (int i = 0; i < 3; i++)
    {
        create_teller(newT,no[i]);
        insert_last(Head,newT);
    }

    //traversal_teller(Head);
    
    do
    {
        system("pause");
        system("cls");
        std::cout << "==============================================" <<std::endl;
        std::cout << "  Program Antrian Pelayanan Bank Jago" <<std::endl;
        std::cout << "==============================================\n" <<std::endl;
        std::cout << " 1. Tambah Daftar Antrian Nasabah"<<std::endl;
        std::cout << " 2. Edit Data Antrian Nasabah"<<std::endl;
        std::cout << " 3. Hapus Data Daftar Antrian Nasabah"<<std::endl;
        std::cout << " 4. Tampilkan Data Antrian Teller" << std::endl;
        std::cout << " 5. Panggil Nasabah"<<std::endl;
        std::cout << " 6. Tampilkan data history pelayanan nasabah"<<std::endl;
        std::cout << " 0. Exit"<<std::endl;
        std::cout << "=============================================="<<std::endl;
        std::cout << "Pilih Menu: ";
        std::cin >> menu;

        switch (menu)
        {
        case 1:
            // Memasukkan Nasabah ke Dalam Queue
            system("cls");
            std::cout <<"=============================================="<<std::endl;
            std::cout <<"\t\tMasukkan Data Nasabah"<<std::endl;
            std::cout <<"=============================================="<<std::endl;
            traversal_teller(Head);
            create_nasabah(newN);
            enqueueN(Head,q,key,newN);
            break;
        
        case 2:
            // Mengedit Data Nasabah yang Sudah Ada Dalam Antrian
            pointerN pCari_N, prevCari_N;
            pointerT pCari_T, prevCari_T;
            int status;
            system("cls");
            std::cout <<"=============================================="<<std::endl;
            std::cout <<"\t\tEdit Data Nasabah"<<std::endl;
            std::cout <<"=============================================="<<std::endl;
            updateN(Head,Key,newN);
            break;
        case 3:
            // Menghapus Seluruh Data Nasabah Pada Teller Tertentu
            system("cls");
            std::cout<<"=============================================="<< std::endl;
            std::cout<<"\t\tHapus Data Nasabah" << std::endl;
            std::cout<<"=============================================="<< std::endl;
            traversal_teller(Head);
            denqueueN_search(Head, key, pDel_N,pCari_N, pCari_T);
            break;
        case 4:
            // Melihat Data Antrian Pada Setiap Teller 
            system("cls");
            std::cout<<"=============================================="<<std::endl;
            std::cout<<"       Data Antrian Teller Bank Jago          "<<std::endl;       
            std::cout<<"=============================================="<<std::endl;
            traversal_pelayanan(Head);
            break;
        case 5:
            // Memanggil Nasabah Untuk Mengunjungin Teller yang Dipilih 
            // Serta Memasukkan Nasabah ke Dalam Stack
            system("cls");
            dequeueN(Head,key, pDel_N);
            create_stack(newH,pDel_N);
            isEmpty(Top);
            push(Top, newH);
            break;
        case 6 :
            // Menampilkan History Pelayanan
            system("cls");
            std::cout <<"=============================================="<<std::endl;
            std::cout <<"\t\tHistory Pelayanan"<<std::endl;
            std::cout <<"=============================================="<<std::endl;
            print_history(Top);
            break;
        default:
            break;
        }
    } while (menu != 0); 
    
    return 0;
}