#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include "structure.h"
//Deklarasi fungsi-fungsi yang digunakan pada program catatan keuangan ini:
int pemasukan ();                                    /* Merupakan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori,
                                                        dan inputan pemasukan saldo user. */

int transaksi ();                                    /* Merupakan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori,
                                                        dan inputan transaksi(pengeluaran) user. */
                                                        
void header ();

void daftar();                                       /* Fungsi void daftar() untuk menyimpan perintah-perintah yang dibutuhkan
                                                        untuk registrasi yang akan menyimpan nama, username, serta password yang
                                                        akan digunakan oleh pengguna*/

void masuk();                                        /* Fungsi void masuk() digunakan agar pengguna dapat masuk dengan username serta
                                                        password yang sudah dibuat dan nantinya akan dilanjutkan kedalam fitur program*/
														

void menu_masuk();                                   // Merupakan fungsi yang digunakan untuk menampilkan pilihan menu masuk Login

void email_pw();                                     /* Merupakan fungsi yang digunakan untuk meminta user untuk menginput Email dan Password
                                                        yang di gunakan untuk Masuk ke dalam program */

void record(User u1, char file[]);                  

void error_alert();                                  /* Merupakan fungsi yang digunakan untuk menampilan pemberitahuan ketika user menginputkan
                                                        pilihan yang salah pada setiap switch case. */


#endif
