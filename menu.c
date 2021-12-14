#include <stdio.h>
#include <stdlib.h>
#include "fungsi.h"
#include "struct.h"
#include "variable.h"

/***********************************************************|
|                     MENU PADA PROGRAM                     |
|TANGGAL PEMBUATAN : 13 DESEMBER 2021                       |
|OLEH : DWI TIRTA WATI                                      |
|DESKRIPSI : MENAMBAHKAN MENU HOME PADA PROGRAM             |
|REVISI : 1                                                 |
|DESKRIPSI : Membuat fungsi menudua untuk menampung tampilan|
|           dan swict case menu                             |
************************************************************/

void menuawal (void){
    system("clear");
    printf  ("\n\n\t\t\t\t\t=============================================\n");
	printf  ("\t\t\t\t\t||              DL'FINANCIAL               ||\n");
	printf  ("\t\t\t\t\t============================================\n");
	printf  ("\t\t\t\t\t||            SIGN IN / SIGN UP            ||\n");
	printf  ("\t\t\t\t\t||     --------------------------------    ||\n");
	printf  ("\t\t\t\t\t||             1. LOGIN                    ||\n");
	printf  ("\t\t\t\t\t||             2. REGISTRASI               ||\n");
	printf  ("\t\t\t\t\t||             3. EXIT                     ||\n");
	printf  ("\t\t\t\t\t=============================================\n");
	printf  ("\n\t\t\t\t\t             PILIHAN: ");
    scanf("%c", &menu1);

    switch (menu1){
        case '1':
            login();
            break;
        case '2':
            registrasi();
            break;
        case '3':
            exit(0);     
    }
}

void menudua (void){
    int menu2;
	printf  ("\t\t\t\t\t=============================================\n");
	printf  ("\t\t\t\t\t||                  HOME                   ||\n");
	printf  ("\t\t\t\t\t||     --------------------------------    ||\n");
	printf  ("\t\t\t\t\t||             1. PEMASUKAN                ||\n");
	printf  ("\t\t\t\t\t||             2. PENGELUARAN              ||\n");
	printf  ("\t\t\t\t\t||             3. LAPORAN                  ||\n");
    printf  ("\t\t\t\t\t||             4. EXIT                     ||\n");
	printf  ("\t\t\t\t\t=============================================\n");
	printf  ("\n\t\t\t\t\t             PILIHAN: ");
    scanf("%d", &menu2);

    switch (menu2){
        case 1:
            pemasukan();
            break;
        case 2:
            pengeluaran();
            break;
        case 3:
            exit(0);     
    }
}
