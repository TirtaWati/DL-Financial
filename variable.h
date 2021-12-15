//Header untuk menyimpan variable-variable yang digunakan pada program ini
#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include <time.h>


// Dekalarasi variable global yang di gunakan pada program catatan keuangan ini:
int ktgripemasukan;                   //variable ktgripemasukan    => berfungsi untuk menyimpan yang dimasukkan oleh user pada pemilihan kategori pemasukan 
int ktgripengeluaran;                 //variable ktgripengeluaran  => berfungsi untuk menyimpan yang dimasukkan oleh user pada pemilihan kategori pengeluaran
time_t waktuserver;                   //variavel waktuserver       => berfungsi untuk mengambil waktu dari sistem.            
char namaFile[] = "dataLog.txt";      //assign namaFile (nF) agar menyimpan string "dataLog.txt"
int pilihanmasuk;					  //variabel pilihanmasuk      => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan menu login
int menuhome;						  //variabel pilihanmenu       => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada Halaman Utama atau Home
char yn;                              //untuk menampung karakter input pada pilihan (Y|N) --> file "input.c (login())"
char username[10], password[8];       //untuk menampung array of string username dan password pada login --> file "input.c" fungsi masuk()

#endif
