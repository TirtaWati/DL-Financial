
/***********************************************************|
|                     MENU PADA PROGRAM                     |
|TANGGAL PEMBUATAN : 13 DESEMBER 2021                       |
|OLEH : DWI TIRTA WATI                                      |
|DESKRIPSI : MENAMBAHKAN MENU HOME PADA PROGRAM             |
|REVISI : 1                                                 |
|DESKRIPSI : Membuat fungsi menudua untuk menampung tampilan|
|           dan swict case menu                             |
************************************************************/



//header untuk menampung libraries yang ada baik yang global mapun local
#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "variable.h"

//fungsi untuk menampilkan dan menjalankan menu awal pada program
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
	printf  ("\n\t\t\t\t\t             PILIHAN: ");                         //user memasukan pilihan
    scanf("%c", &menu1);                                                    //inputan dimasukan ke variable menu1

    //penggunaan switch case untuk setiap menu yang ada
    switch (menu1){
        case '1':       //case 1 untuk masuk ke fungsi login()-->file "input.c"
            login();
            break;
        case '2':       //case 2 untuk masuk ke fungsi registrasi() -->file "input.c"
            registrasi();       
            break;
        case '3':       //case 3 keluar dari program
            exit(0);     
    }
}

//fungsi untuk menampilkan dan menjalankan menu home pada program
void home (void){
	printf  ("\t\t\t\t\t=============================================\n");
	printf  ("\t\t\t\t\t||                  HOME                   ||\n");
	printf  ("\t\t\t\t\t||     --------------------------------    ||\n");
	printf  ("\t\t\t\t\t||             1. PEMASUKAN                ||\n");
	printf  ("\t\t\t\t\t||             2. PENGELUARAN              ||\n");
	printf  ("\t\t\t\t\t||             3. LAPORAN                  ||\n");
    printf  ("\t\t\t\t\t||             4. ACCOUNT INFO             ||\n");
    printf  ("\t\t\t\t\t||             5. EXIT                     ||\n");
	printf  ("\t\t\t\t\t=============================================\n");
	printf  ("\n\t\t\t\t\t             PILIHAN: ");                     //user memasukan pilihan 
    scanf("%d", &menu2);                                                //inputan dimasukan ke variable menu2

    //penggunaan switch case untuk setiap menu yang ada
    switch (menu2){
        case 1:
            pemasukan();        //case 1 masuk ke fungsi pemasukan()--> file "input.c"
            break;
        case 2:
            pengeluaran();      //case 2 masuk ke fungsi pengeluaran()--> file "input.c"
            break;
        case 3:
            laporan();          //case 3 masuk ke fungsi laporan()--> file "display.c"
            break;
        case 4:
            infouser();         //case 4 masuk ke fungsi infouser()--> file "display.c"
            break;
        case 5:                 //case 5 keluar dari program
            exit(0);
                 
    }
}
