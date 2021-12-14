#ifndef __STRUCT_H__
#define __STRUCT_H__ 

struct datauser{
    char nama[50];
    char email[20];
    char password[20];
    char username[20];
    float uang;
};

struct transaksi
{
    char kategori[100];
    float pengeluaran;
    float pemasukan;
};

struct Laporan
{
    int tanggal, bulan, tahun;
    float pengeluaran;
    float pemasukan;
    float netIncome;
};

#endif