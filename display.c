/**************************************************************************************************|
|                    DISPLAY INFO AKUN                      									   |
|TANGGAL PEMBUATAN : 14 DESEMBER 2021                       									   |
|OLEH : DWI TIRTA WATI                                      									   |
|DESKRIPSI : Membuat fungsi infouser untuk menampilkan data-data user setelah menu home pilihan 4  |
|REVISI : 0                                                 									   |
|***************************************************************************************************/

/*********************************************************************************************************************************|
|                    DISPLAY INFO AKUN                      																	  |
|TANGGAL PEMBUATAN : 14 DESEMBER 2021                       																	  |
|OLEH : DWI TIRTA WATI                                                        													  |
|DESKRIPSI : Membuat fungsi infouser untuk menampilkan      																	  |
|			data-data user setelah menu home pilihan 4																			  |
|REVISI : 1                                                 																	  |
|DESKRIPSI : membuat file logrecord yang ada pada fungsi login termuat di fungsi ini agar dapat memanggil data user pada info.txt |
|*********************************************************************************************************************************/


//header untuk menampung libraries yang ada baik yang global mapun local
#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "structure.h"
//define buffer_size ini untuk mendeklarasikan banyak/jumlah buffer max pada file
#define BUFFER_SIZE 1000

//fungsi untuk menampilkan header sistem
void header (void){
	system  ("clear");
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

//fungsi untuk menampilkan info data user 
void infouser (void){
	FILE *fu, *fp;						// penggunaan file handling pada program, mendeklarasikan pointer
	struct datauser d;					//pointer fu digunakan untuk membuka file info.txt dengan mode read
	fu = fopen("info.txt", "r");		//pointer fu digunakan untuk membuka file info.txt dengan mode read	
	fp = fopen("logrecord.txt", "r"); 		/* pointer fp digunakan untuk membuka file logrecord.txt dengan mode w 
                                		(dimana data yang tersimpan akan terus berganti setiap kali login dilakukan)*/

	//membaca username yang ada di file info.txt dan mencari kesamaan antar username yang ada di logrecord
	while(fgets(&d, BUFFER_SIZE, fu)){				//membaca keseluruhan isi dari info.txt
		if(strcmp(&usrname, &d.username) == 0){		//membandingkan apakah username logrecord dan username info.txt sama
		    system("clear");
			//jika kondisi terpernuhi maka ditampilkan keseluruhan info user yang ada dan yang sesuai dengan username
			printf  ("\t\t\t\t\t==========================================\n");	
			printf  ("\t\t\t\t\t              ACCOUNT INFO\n");
			printf  ("\t\t\t\t\t------------------------------------------\n");
			printf  ("\t\t\t\t\t\t  NAMA : %s\n", &d.nama);
			printf  ("\t\t\t\t\t\t  EMAIL: %s\n", &d.email);
			printf  ("\t\t\t\t\t\t  SAKU : %2.f\n", d.uang);
			printf  ("\t\t\t\t\t==========================================\n");
		}
	}
	fclose(fu);		/*menutup kedua file info.txt dan logrecord.txt*/
	fclose(fp);
}

void laporan(){
	
}