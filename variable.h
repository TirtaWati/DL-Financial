//Header untuk menyimpan variable-variable yang digunakan pada program ini
#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include <time.h>


// Dekalarasi variable global yang di gunakan pada program catatan keuangan ini:
int ktgripemasukan;                   //variable ktgripemasukan    => berfungsi untuk menyimpan yang dimasukkan oleh user pada pemilihan kategori pemasukan 
int ktgripengeluaran;                 //variable ktgripengeluaran  => berfungsi untuk menyimpan yang dimasukkan oleh user pada pemilihan kategori pengeluaran
time_t waktuserver;                   //variavel waktuserver       => berfungsi untuk mengambil waktu dari sistem.            
int mtdmsk;                           //variabel mtdmsk            => untuk memilih akun mana yang ingin dicatat pemasukannya
char namaFile[] = "dataLog.txt";    // assign namaFile (nF) agar menyimpan string "logRecord.txt"


#endif
