#include "variable.h"
#include "structure.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>

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
    // penggunaan file handling pada program, mendeklarasikan pointer
	FILE *log, *record;
	log = fopen("dataLog.txt", "r");		    	// pointer log digunakan untuk membuka file dataLog.txt dengan mode read 
	record = fopen("logrecord.txt", "r"); 			/* pointer record digunakan untuk membuka file logrecord.txt dengan mode w 
                                		           	   (dimana data yang tersimpan akan terus berganti setiap kali login dilakukan)*/

	//membaca username yang ada di file dataLog.txt dan mencari kesamaan antar username yang ada di logrecord
	while(fgets(&u, BUFFER_SIZE, log)){				// membaca keseluruhan isi dari dataLog.txt
		if(strcmp(username, u.username) == 0){		// membandingkan apakah username logrecord dan username dataLog.txt sama
		    system("clear");
			//jika kondisi terpernuhi maka ditampilkan keseluruhan info user yang ada dan yang sesuai dengan username
			printf  ("\t\t\t\t\t==========================================\n");	
			printf  ("\t\t\t\t\t              ACCOUNT INFO\n");
			printf  ("\t\t\t\t\t------------------------------------------\n");
			printf  ("\t\t\t\t\t\t  NAMA     : %s\n", &u.nama);
			printf  ("\t\t\t\t\t\t  EMAIL    : %s\n", &u.email);
			printf  ("\t\t\t\t\t\t  USERNAME : %s\n", &u.username);
			printf  ("\t\t\t\t\t\t  PASSWORD : %s\n", &u.password);
			printf  ("\t\t\t\t\t\t  SAKU     : %2.f\n", u.saku);
			printf  ("\t\t\t\t\t==========================================\n");
		}
	}
	fclose(log);		/*menutup kedua file dataLog.txt dan logrecord.txt*/
	fclose(record);
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

void laporan (){
	// penggunaan file handling pada program, mendeklarasikan pointer
	FILE *data, *record;
	data = fopen("dataLog.txt", "r");  			// pointer data digunakan untuk membuka file dataLog.txt dengan mode read 
	record = fopen("logrecord.txt", "r"); 		// pointer record digunakan untuk membuka file logrecord.txt dengan mode read

	//membaca username yang ada di file dataLog.txt dan mencari kesamaan antar username yang ada di logrecord
	while(fgets(&u, BUFFER_SIZE, data)){		// membaca keseluruhan isi dari dataLog.txt
		if(strcmp(username, u.username) == 0){	// membandingkan apakah username logrecord dan username dataLog.txt sama
			system("clear");
			//jika kondisi terpernuhi maka ditampilkan keseluruhan transaksi yang ada dan yang sesuai dengan username
			printf  ("\t\t\t\t\t===================================================\n");	
			printf  ("\t\t\t\t\t            LAPORAN TRANSAKSI HARI INI			   \n");
			printf  ("\t\t\t\t\t---------------------------------------------------\n");
			printf  ("\t\t\t\t\t  NAMA : %s\n", &u.nama);
			printf  ("\t\t\t\t\t  SAKU : %2.f\n", u.saku);
			printf  ("\t\t\t\t\t---------------------------------------------------\n");
			printf  ("\t\t\t\t\t\t  PEMASUKAN            : %2.f\n", u.in.pemasukan);
			printf  ("\t\t\t\t\t\t  KATEGORI PEMASUKAN   : %s\n\n", u.in.kategori);
			printf  ("\t\t\t\t\t\t  PENGELUARAN          : %2.f\n", u.out.pengeluaran);
			printf  ("\t\t\t\t\t\t  KATEGORI PENGELUARAN : %s\n", u.out.kategori);
			printf  ("\t\t\t\t\t===================================================\n");
		}
		
	}
	fclose(data);		/*menutup kedua file dataLog.txt dan logrecord.txt*/
	fclose(record);
	home();
}
