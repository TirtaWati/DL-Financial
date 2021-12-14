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

#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "structure.h"
#define BUFFER_SIZE 1000

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
void infouser (void){
	FILE *fu, *fp;
	struct datauser d;
	fu = fopen("info.txt", "r");
	fp = fopen("logrec.txt", "r");
	while(fgets(&d, BUFFER_SIZE, fu)){
		if(strcmp(&usrname, &d.username) == 0){
		    system("clear");
			printf  ("\t\t\t\t\t==========================================\n");
			printf  ("\t\t\t\t\t||\t       ACCOUNT INFO\t\t||\n");
			printf  ("\t\t\t\t\t||--------------------------------------||\n");
			printf  ("\t\t\t\t\t||\tNAMA : %s\t\t\t||\n", &d.nama);
			printf  ("\t\t\t\t\t||\tEMAIL: %s\t\t||\n", &d.email);
			printf  ("\t\t\t\t\t||\tSAKU : %2.f\t\t\t||\n", d.uang);
			printf  ("\t\t\t\t\t==========================================\n");
		}
	}
	fclose(fu);
	fclose(fp);
}

void laporan(){
	
}