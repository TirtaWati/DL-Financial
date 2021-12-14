#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "variable.h"
#include "fungsi.h"
#define BUFFER_SIZE 1000

void login (void){
    struct datauser d;
    FILE *fu;
    fu = fopen("info.txt", "r");
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

    while(fgets(&d, BUFFER_SIZE, fu)){
        if(strcmp(&usrname, &d.username) == 0 && strcmp(&pass, &d.password) == 0){
            system("clear");
            printf  ("\n\n\t\t\t\t\t=============================================\n");
            printf  ("\t\t\t\t\t||\t    Selamat Datang %s\t   ||\n", &d.nama);
            menudua();
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
    }
    fclose(fu);
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