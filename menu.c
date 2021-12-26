#include "function.h"
#include <stdio.h>
#include <stdlib.h>

//=======================================================================//
//************  Fungsi Untuk Menampilkan Halaman Utama   ****************//
//=======================================================================//
// Tgl  	  : 14-12-2021                                   	         //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022		             //
// Revisi	  : 0					                                     //
// Nama Fungsi: home                                                     //
// Deskripsi  : Meminta user untuk memilih salah satu kategori yang      //
//		        ingin dijalankan sesuai dengan kebutuhan user.           //
//=======================================================================//

/*************************************************************************|
|*************   Fungsi Untuk Menampilkan Halaman Utama   ****************|
|=========================================================================|
|TANGGAL PEMBUATAN : 14 DESEMBER 2021                                     |
|OLEH : DWI TIRTA WATI                                                    |
|DESKRIPSI : REVISI FUNGSI HOME() PADA PROGRAM                            |
|REVISI : 1                                                               |
|DESKRIPSI : Menambahkan pilihan "akun Info" pada halama utama pada       |
|            switch case 5, fungsi home()                                 |
**************************************************************************/

void home(){
    pilih:
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                 HALAMAN UTAMA                  |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Pilihan Menu                        |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Pemasukan                           |\n");
    printf ("\t\t\t\t\t|   2   |    Pengeluaran                         |\n");
    printf ("\t\t\t\t\t|   3   |    Laporan Transaksi                   |\n");
    printf ("\t\t\t\t\t|   4   |    INFO AKUN                           |\n");
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
        // pada case 3, program akan menampilkan menu laporan dari pemasukan serta pengeluaran user
        case 3:
            laporan ();
            break;
        //case 4 masuk ke fungsi infouser()--> file "display.c"
        case 4:
            infouser();
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

//=======================================================================//
//************    Fungsi Untuk Menampilkan Menu Masuk    ****************//
//=======================================================================//
// Tgl  	  : 07-12-2021                                   	         //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022		             //
// Revisi	  : 0					                                     //
// Nama Fungsi: menu_masuk                                               //
// Deskripsi  : Meminta user untuk memilih salah satu kategori menu      //
//		        masuk yang ingin dijalankan sesuai dengan kebutuhan user //
//=======================================================================//
void menu_masuk(){
    int pilihanmasuk;

    // Arahan yang diberikan kepada pengguna
    arahan:
    printf ("\n\n\t\t\t\t\t===============================================\n");
    printf ("\t\t\t\t\t||                 MENU MASUK                ||\n");
    printf ("\t\t\t\t\t||===========================================||\n");
    printf ("\t\t\t\t\t||   No  |    Menu                           ||\n");
    printf ("\t\t\t\t\t||-------|-----------------------------------||\n");
    printf ("\t\t\t\t\t||   1   |    Masuk                          ||\n");
    printf ("\t\t\t\t\t||   2   |    Registrasi                     ||\n");
    printf ("\t\t\t\t\t||   3   |    Exit                           ||\n");
    printf ("\t\t\t\t\t===============================================\n");
    printf ("\t\t\t\t\tInput pilihan Anda = ");
    scanf  ("%d", &pilihanmasuk);
    system ("clear");

    switch (pilihanmasuk){
    case 1:
        // Jika pengguna menginput angka 1 maka dipanggil fungsi masuk
        masuk();
        break;
    case 2:
        // Jika pengguna menginput angka 2 maka dipanggil fungsi registrasi
        daftar();
        break;
    case 3:
        exit(1);
        break;
    default:
    	error_alert();
        goto arahan;
        break;
    }
}

