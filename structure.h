#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__
#include "variable.h"

typedef struct {
    char nama[30];
    char username[10];
    char password[8];
    char email[30];
	float saku;
    struct transaksi
    {
        float pemasukan;
        float pengeluaran;
        char kategori[100];
    }in, out;
    
}User;

//Mendeklarasikan variabel u pada struct User
User u;

#endif 
