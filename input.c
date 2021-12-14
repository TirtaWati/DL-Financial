/***********************************************************|
|                    LOGIN & REGISTRASI                     |
|TANGGAL PEMBUATAN : 6 DESEMBER 2021                        |
|OLEH : DWI TIRTA WATI                                      |
|DESKRIPSI : MEMBUAT FUNGSI UNTUK MELAKUKAN REGISTRASI DAN  |
|           lOGIN PENGGUNA                                  |
|REVISI : 0                                                 |
************************************************************/

/***********************************************************|
|                    LOGIN & REGISTRASI                     |
|TANGGAL PEMBUATAN : 7 DESEMBER 2021                        |
|OLEH : DWI TIRTA WATI                                      |
|DESKRIPSI : REVISI FUNGSI UNTUK MELAKUKAN REGISTRASI DAN   |
|           lOGIN PENGGUNA                                  |
|REVISI : 1                                                 |
|DESKRIPSI : Membuat info.txt menyimpan tipa data pada 1    |
|line, dan menambahkan difine untuk membaca seluruh data di |
|info.txt                                                   |
************************************************************/

/***********************************************************|
|                    LOGIN & REGISTRASI                     |
|TANGGAL PEMBUATAN : 13 DESEMBER 2021                       |
|OLEH : DWI TIRTA WATI                                      |
|DESKRIPSI : REVISI FUNGSI UNTUK MELAKUKAN REGISTRASI DAN   |
|           lOGIN PENGGUNA                                  |
|REVISI : 2                                                 |
|DESKRIPSI : menambahkan tampilan setelah berhasil login    |
|            menampilkan nama dari user kemudian menu home  |
************************************************************/

/***********************************************************|
|                    LOGIN & REGISTRASI                     |
|TANGGAL PEMBUATAN : 14 DESEMBER 2021                       |
|OLEH : DWI TIRTA WATI                                      |
|DESKRIPSI : REVISI FUNGSI UNTUK MELAKUKAN REGISTRASI DAN   |
|           lOGIN PENGGUNA                                  |
|REVISI : 3                                                 |
|DESKRIPSI : menambahkan file logrecord untuk menyimpan     |
|            value usrname yang ada di login agar dapat     |
|            melakukan strcmp di fungsi lain (infouser())   |
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "variable.h"
#include "function.h"
#define BUFFER_SIZE 1000

void login (void){
    struct datauser d;
    FILE *fu, *fp;
    fu = fopen("info.txt", "r");
    fp = fopen("logrecord.txt", "w");
    if(fu == NULL){
        printf("ERROR IN OPENING FILE");
		exit(0);
    }
    system ("clear");
    printf ("\n\n\t\t\t\t\t=====================\n");
    printf ("\t\t\t\t\t        LOGIN\n");
    printf ("\t\t\t\t\t---------------------\n");
    printf ("\t\t\t\t\t Username: ");
    scanf  ("%s", &usrname);
    printf ("\t\t\t\t\t---------------------\n");
    printf ("\t\t\t\t\t Password: ");
    scanf  ("%s", &pass);
    printf ("\t\t\t\t\t--------------------\n");

    fwrite(&usrname, sizeof(usrname), 1, fp);

    while(fgets(&d, BUFFER_SIZE, fu)){
        if(strcmp(&usrname, &d.username) == 0 && strcmp(&pass, &d.password) == 0){
            system("clear");
            printf  ("\n\n\t\t\t\t\t=============================================\n");
            printf  ("\t\t\t\t\t||\t    Selamat Datang %s\t   ||\n", &d.nama);
            home();
        }
        else if(strcmp(&usrname, &d.username)== 0 && strcmp(&pass, &d.password) != 0 ){
            system("clear");
			printf ("\n\n\t\t\t\t\t===============================\n");
			printf ("\t\t\t\t\tPassword yang Anda Masukan Salah!\n");
			printf ("\t\t\t\t\t===============================\n");
			printf ("Ingin Input Ulang? (Y|N): ");
			scanf  ("%s", &yn);
			if(strcmp(&yn, "y") == 0 || strcmp(&yn, "Y") == 0){
				login();
			}else {
				exit(0);
			}
        }
        else{
            system("clear");
            printf ("\n\n\t\t\t\t\t==========================================\n");
            printf("\t\t\t\tUsername tidak terdaftar!\n");
            printf("\t\tSilahkan melakukan registrasi terlebih dahulu");
            printf ("\n\n\t\t\t\t\t==========================================\n");
        }
    }
    fclose(fu);
    fclose(fp);
}

void registrasi (void){
    struct datauser d;
    FILE *fu;
    fu = fopen("info.txt", "a+");
    if (fu == NULL) {
        printf("ERROR IN OPENING FILE");
    }

    system("clear");
    printf("\t\t\t\tNama    : ");
    scanf ("%s", d.nama);
    printf("\t\t\t\tEmail   : ");
    scanf ("%s", d.email);
    printf("\n\t\t\t\t\t Selamat Datang %s!\n", d.nama);
    printf("\t\t\t\t\tSilahkan input username (max 10)\n");
    printf("\t\t\t\t\tSilahkan input password (max 8)\n");

    printf("\n\t\t\t\tUsername : ");
    scanf ("%s", d.username);
    printf("\t\t\t\tPassword : ");
    scanf ("%s", d.password);

    printf("\t\t\t\tMasukan total uang saku Anda: ");
    scanf ("%f",&d.uang);

    fwrite(&d, sizeof(d), 1, fu);
	fprintf(fu,"\n");
    fclose(fu);

	login();
}

void pemasukan (void){
    
}
void pengeluaran (void){

}