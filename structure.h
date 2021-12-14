//library local untuk menampung struktur yang digunakan dalam program
#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__ 

//struct untuk menampung data user yang telah melakukan registrasi
struct datauser{        
    char nama[50];
    char email[20];
    char password[20];
    char username[20];
    float uang;
};

//struct untuk menampung transaksi user yang digunakan pada fungsi pengeluaran() dan pemasukan()
struct transaksi
{
    char kategori[100];
    float pengeluaran;
    float pemasukan;
};

//struct untuk menampung laporan user yang akan ditampilkan pada fungsi laporan()
struct Laporan
{
    int tanggal, bulan, tahun;
    float pengeluaran;
    float pemasukan;
    float netIncome;
};

#endif