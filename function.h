#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include "structure.h"
//Deklarasi fungsi-fungsi yang digunakan pada program catatan keuangan ini:
void pemasukan ();                                   /* Merupakan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori,
                                                        dan inputan pemasukan saldo user. */

int pengeluaran ();                                  /* fungsi untuk melakukan penginputan data pengeluaran dari user yang akan menyimpan 
                                                        jumlah pengeluaran dan kategori sehingga mempengaruhi jumlah dari saku user -->"transaksi.c"*/

                                                        
void header ();					                     /* Merupakan fungsi yang digunakan untuk menampilkan Header progam */

void daftar();                                       /* Fungsi void daftar() untuk menyimpan perintah-perintah yang dibutuhkan
                                                        untuk registrasi yang akan menyimpan nama, username, serta password yang
                                                        akan digunakan oleh pengguna */

void masuk();                                        /* Fungsi void masuk() digunakan agar pengguna dapat masuk dengan username serta
                                                        password yang sudah dibuat dan nantinya akan dilanjutkan kedalam fitur home*/
														

void menu_masuk();                                   /* Merupakan fungsi yang digunakan untuk menampilkan pilihan menu masuk Login */

void home();					                     /* Merupakan fungsi yang digunakan untuk menampilkan halaman utama atau home */

void record(User u1, char file[]);                  

void error_alert();                                  /* Merupakan fungsi yang digunakan untuk menampilan pemberitahuan ketika user menginputkan
                                                        pilihan yang salah pada setiap switch case. */

void infouser (void);                                // fungsi untuk menampilkan info akun, berada di file "display.c"

void laporan ();                                     // fungsi untuk menampilkan laporan transaksi user, berada di file "display.c"

#endif
