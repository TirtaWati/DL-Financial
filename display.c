#include "variable.h"
#include "structure.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//=======================================================================//
//************  Fungsi Untuk Menampilkan Tampilan Awal   ****************//
//=======================================================================//
// Tgl  	  : 07-12-2021                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	      	 //
// Revisi	  : 0		  					 //
// Nama Fungsi    : header                                               //
// Deskripsi      : Menampilkan sebuah tampilan awal saat program        //
//		   		 	dijalankan                       //
//=======================================================================//
void header (void){
    system ("clear");
	printf  ("\n\n\t\t\t\t\t=============================================\n");
	printf  ("\t\t\t\t\t||         Program Catatan Keuangan        ||\n");
	printf  ("\t\t\t\t\t============================================\n");
	printf  ("\t\t\t\t\t||     Program dibuat dan disusun oleh:    ||\n");
	printf  ("\t\t\t\t\t||     --------------------------------    ||\n");
	printf  ("\t\t\t\t\t||              Dwi Tirta Wati             ||\n");
	printf  ("\t\t\t\t\t||                    &                    ||\n");
	printf  ("\t\t\t\t\t||         Leony Mona Putri Sihaloho       ||\n");
	printf  ("\t\t\t\t\t=============================================\n");
	printf  ("\t\t\t\t\t       Tekan ENTER  untuk melanjutkan....    \n");
    printf  ("\t\t\t\t\t=============================================\n");
    getchar();
}

//=======================================================================//
//***********************      ERROR ALERT     **************************//
//=======================================================================//
// Tgl  	  : 07-12-2021                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	         //
// Revisi	  : 0		      					 //
// Nama Fungsi    : error_alert                                          //
// Deskripsi      : Menampilkan pemberitahuan ketika user menginputkan   //
//		    		pilihan yang salah                       //
//=======================================================================//
void error_alert(){
    printf   ("\n\n\t\t\t\t\t||            Pilihan Tidak Ada!!!           || \n");
    printf   ("\t\t\t\t\t||       Silahkan Pilih Pilihan yang Ada     || \n");
}

//=======================================================================//
//***********************      WAKTU SERVER    **************************//
//=======================================================================//
// Tgl  	  : 02-01-2022                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	         //
// Revisi	  : 0		      					 //
// Nama Fungsi    : waktu                                                //
// Deskripsi      : Fungsi waktu() ini digunakan untuk mengambil dan     //
//                  menampilkan waktu sistem saat user mengakses program.//
//=======================================================================//
void waktu(){
    time( &waktuserver);
    struct tm * waktu = localtime( & waktuserver);
    printf("\n\t\t\t\t\t||================Tanggal: %i/%i/%i==============||\n\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900);
}


/*************************************************************************|
|*********************      DISPLAY INFO AKUN      ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 13 DESEMBER 2021                       		  |
|OLEH : DWI TIRTA WATI                                      		  |
|DESKRIPSI : Membuat fungsi infouser() untuk menampilkan data-data user   |
|REVISI : 0                                                 		  |
|*************************************************************************/

/*************************************************************************|
|*********************      DISPLAY INFO AKUN      ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 14 DESEMBER 2021                       		  |
|OLEH : DWI TIRTA WATI                                      		  |
|DESKRIPSI : Membuat fungsi infouser untuk menampilkan data-data user     |
|            setelah menu home pilihan 5				  |
|REVISI : 1                                                 		  |
|DESKRIPSI : membuat file logrecord yang ada pada logngsi login termuat di|
|            fungsi ini agar dapat memanggil data user pada dataLog.txt   | 
|*************************************************************************/

//=======================================================================//
//********************      DISPLAY INFO AKUN      **********************//
//=======================================================================//
// Tgl  	  : 21-12-2021                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	      	 //
// Revisi	  : 2		  					 //
// Nama Fungsi    : infouser                                             //
// Deskripsi      : Menambahkan info user yaitu username dan password    //
//		    sesuai dengan account yang sedang dijalankan.        //
//=======================================================================//

void infouser (void){
	FILE *log, *record;
	log = fopen("dataLog.txt", "r");		    						// pointer log digunakan untuk membuka file dataLog.txt dengan mode read 
	//membaca username yang ada di file dataLog.txt dan mencari kesamaan antar username
	while(fgets(&u, BUFFER_SIZE, log)){																					// membaca keseluruhan isi dari dataLog.txt
		if(strcmp(username, u.username) == 0){																					// membandingkan apakah username logrecord dan username dataLog.txt sama
		    system("clear");
			//jika kondisi terpernuhi maka ditampilkan keseluruhan info user yang ada dan yang sesuai dengan username
			printf  ("\t\t\t\t\t    ==========================================\n");	
			printf  ("\t\t\t\t\t                  ACCOUNT INFO\n");
			printf  ("\t\t\t\t\t    ------------------------------------------\n");
			printf  ("\t\t\t\t\t\t      NAMA     : %s\n", &u.nama);
			printf  ("\t\t\t\t\t\t      EMAIL    : %s\n", &u.email);
			printf  ("\t\t\t\t\t\t      USERNAME : %s\n", &u.username);
			printf  ("\t\t\t\t\t\t      PASSWORD : %s\n", &u.password);
			printf  ("\t\t\t\t\t\t      SAKU     : Rp%2.f\n", u.saku);
			printf  ("\t\t\t\t\t    ==========================================\n");
			printf  ("\t\t\t\t\t     Tekan ENTER untuk kembali Halaman Utama \n");
			printf  ("\t\t\t\t\t    ==========================================\n");
			getchar();
			getchar();
		}
	}
	fclose(log);		/*menutup kedua file dataLog.txt*/
	system("clear");
	home();
}

/*************************************************************************|
|******************      DISPLAY LAPORAN TRANSAKSI    ********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 20 DESEMBER 2021                       		  |
|OLEH : DWI TIRTA WATI                                      		  |
|DESKRIPSI : Membuat fungsi laporan() untuk menampilkan transaksi yang    |
|			 dilakukan oleh user				  |
|REVISI : 0                                                 		  |
|*************************************************************************/

//=======================================================================//
//******************     DISPLAY LAPORAN TRANSAKI    ********************//
//=======================================================================//
// Tgl  	  : 02-01-2022                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	         //
// Revisi	  : 1		      					 //
// Nama Fungsi    : laporan                                              //
// Deskripsi      : Menambahkan fungsi waktu() untuk memanggil waktu     //
//                  sistem dan mengubah struktur tampilan data dari      //
//                  pemasukan dan pengeluaran sebelumnya.                //
//=======================================================================//

void laporan (){
	time( & waktuserver);
    struct tm * waktu = localtime( & waktuserver);																											// penggunaan file handling pada program, mendeklarasikan pointer
	FILE *data;
	data = fopen("dataLog.txt", "r");  																			// pointer data digunakan untuk membuka file dataLog.txt dengan mode read 
	
	//membaca username yang ada di file dataLog.txt dan mencari kesamaan antar username
	while(fgets(&u, BUFFER_SIZE, data)){																	// membaca keseluruhan isi dari dataLog.txt
		if(strcmp(username, u.username) == 0){																		// membandingkan apakah username logrecord dan username dataLog.txt sama
			system("clear");
			printf ("\t\t========================================================================================\n");
			printf ("\t\t                                        PEMASUKAN                                       \n");
			printf ("\t\t========================================================================================\n");
			printf ("\t\t|     Tanggal     |     Nama     |     Pemasukan     |     Kategori     |Jumlah Saku\n");
			printf ("\t\t|%i-%i-%i          %s          Rp%2.f           %s               Rp%2.f\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900, &u.nama, u.pemasukan, u.kategori_in, u.saku);
			printf ("\t\t========================================================================================\n");
			printf ("\t\t\n                                     PENGELUARAN                                      \n");
			printf ("\t\t========================================================================================\n");
			printf ("\t\t|     Tanggal     |     Nama     |     Pengeluaran   |     Kategori     |Jumlah Saku\n");
			printf ("\t\t|%i-%i-%i          %s          Rp%2.f          %s               Rp%2.f\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900, &u.nama, u.pengeluaran, u.kategori_out, u.saku);
			printf ("\t\t|=======================================================================================|\n");
			//jika kondisi terpernuhi maka ditampilkan keseluruhan transaksi yang ada dan yang sesuai dengan username
			
			printf  ("\t\t\t\t\t===================================================\n");
			printf  ("\t\t\t\t\t     Tekan ENTER untuk kembali Halaman Utama	   \n");
			printf  ("\t\t\t\t\t===================================================\n");
			getchar();
			getchar();
		}
		
	}
	fclose(data);		/*menutup kedua file dataLog.txt*/
	system("clear");
	home();
}

