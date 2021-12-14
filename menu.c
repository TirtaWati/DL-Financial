#include "function.h"
#include <stdio.h>
#include <stdlib.h>

void header (){
    system ("cls");
	printf  ("\n\n\t\t\t\t\t=============================================\n");
	printf  ("\t\t\t\t\t||         Program Catatan Keuangan        ||\n");
	printf  ("\t\t\t\t\t============================================\n");
	printf  ("\t\t\t\t\t||     Program dibuat dan disusun oleh:    ||\n");
	printf  ("\t\t\t\t\t||     --------------------------------    ||\n");
	printf  ("\t\t\t\t\t||              Dwi Tirta Wati             ||\n");
	printf  ("\t\t\t\t\t||                    &                    ||\n");
	printf  ("\t\t\t\t\t||         Leony Mona Putri Sihaloho       ||\n");
	printf  ("\t\t\t\t\t=============================================\n");
	printf  ("\t\t\t\t\t        Klik ENTER untuk melanjutkan....    \n");
    printf  ("\t\t\t\t\t=============================================\n");
	getchar ();
    system ("cls");

}

//=======================================================================//
//************  Fungsi Untuk Menampilkan Halaman Utama   ****************//
//=======================================================================//
// Tgl  		  : 14-12-2021                                   //
// Oleh			  : Leony Mona Putri Sihaloho - 2105551022	 //
// Revisi		  : 0				                 //
// Nama Fungsi    : home                                                 //
// Deskripsi      : Meminta user untuk memilih salah satu kategori yang  //
//		    ingin dijalankan sesuai dengan kebutuhan user.       //
//=======================================================================//
void home(){
    pilih:
    printf ("\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                   HALAMAN UTAMA                |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Pilihan Menu                        |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Pemasukan                           |\n");
    printf ("\t\t\t\t\t|   2   |    Pengeluaran                         |\n");
    printf ("\t\t\t\t\t|   3   |    Transaksi                           |\n");
    printf ("\t\t\t\t\t|   4   |    Target                              |\n");
    printf ("\t\t\t\t\t|   5   |    EXIT                                |\n");
    printf ("\t\t\t\t\t|================================================|\n"); 
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\n\t\t\t\t\t Input Pilihan Anda = ");
    scanf  ("%d",&menuhome);
    printf ("\t\t\t\t\t|================================================|\n");
    system ("clear");

    switch (menuhome)
    {
        //pada case 1, program akan menampilkan menu pemasukan dan user akan diminta untuk memilih kategori untuk pemasukan yang di lakukan oleh user.
        case 1:
            pemasukan ();
            break;
        //pada case 2, program akan menampilkan menu pengeluaran dan user akan diminta untuk memilih kategori untuk pengeluaran yang di lakukan oleh user.
        case 2:
            pengeluaran ();
            break;
        //pada case 3, program akan menampilkan menu transaksi dan user akan diminta untuk memilih untuk transaksi yang di lakukan oleh user.
        case 3:
            transaksi ();
            break;
        //pada case 4, program akan menampilkan menu target yang di lakukan oleh user.
        case 4:
            target ();
            break;
        case 5:
            exit (0);
            break;
        default:
            error_alert();
            //goto pilih; dimana syntax ini akan membawa user kembali ke menu pemilihan program untuk menginputkan pilihan yang benar, ini akan terus berulang hingga user menginputkan pilihan yang benar sesuai apa yang sudah ditampilkan pada menu pilihan.
            goto pilih;
            break;
    }
}
