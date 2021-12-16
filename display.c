#include "variable.h"
#include "structure.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>

//define buffer_size ini untuk mendeklarasikan banyak/jumlah buffer max pada file
#define BUFFER_SIZE 1000

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

void error_alert(){
    printf   ("\n\n\t\t\t\t\t||            Pilihan Tidak Ada!!!           || \n");
    printf   ("\t\t\t\t\t||       Silahkan Pilih Pilihan yang Ada     || \n");
}


/*************************************************************************|
|*********************      DISPLAY INFO AKUN      ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 13 DESEMBER 2021                       			  |
|OLEH : DWI TIRTA WATI                                      			  |
|DESKRIPSI : Membuat fungsi infouser() untuk menampilkan data-data user   |
|REVISI : 0                                                 			  |
|*************************************************************************/

/*************************************************************************|
|*********************      DISPLAY INFO AKUN      ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 14 DESEMBER 2021                       			  |
|OLEH : DWI TIRTA WATI                                      			  |
|DESKRIPSI : Membuat fungsi infouser untuk menampilkan data-data user     |
|            setelah menu home pilihan 5								  |
|REVISI : 1                                                 			  |
|DESKRIPSI : membuat file logrecord yang ada pada logngsi login termuat di|
|            fungsi ini agar dapat memanggil data user pada dataLog.txt   | 
|*************************************************************************/

void infouser (void){
    // penggunaan file handling pada program, mendeklarasikan pointer
	FILE *log, *record;
	log = fopen("dataLog.txt", "r");		    // pointer log digunakan untuk membuka file dataLog.txt dengan mode read 
	record = fopen("logrecord.txt", "r"); 		/* pointer record digunakan untuk membuka file logrecord.txt dengan mode w 
                                		           (dimana data yang tersimpan akan terus berganti setiap kali login dilakukan)*/

	//membaca username yang ada di file dataLog.txt dan mencari kesamaan antar username yang ada di logrecord
	while(fgets(&u, BUFFER_SIZE, log)){				//membaca keseluruhan isi dari dataLog.txt
		if(strcmp(username, u.username) == 0){		//membandingkan apakah username logrecord dan username dataLog.txt sama
		    system("clear");
			//jika kondisi terpernuhi maka ditampilkan keseluruhan info user yang ada dan yang sesuai dengan username
			printf  ("\t\t\t\t\t==========================================\n");	
			printf  ("\t\t\t\t\t              ACCOUNT INFO\n");
			printf  ("\t\t\t\t\t------------------------------------------\n");
			printf  ("\t\t\t\t\t\t  NAMA : %s\n", &u.nama);
			printf  ("\t\t\t\t\t\t  EMAIL: %s\n", &u.email);
			printf  ("\t\t\t\t\t\t  SAKU : %2.f\n", u.uang);
			printf  ("\t\t\t\t\t==========================================\n");
		}
	}
	fclose(log);		/*menutup kedua file dataLog.txt dan logrecord.txt*/
	fclose(record);
}