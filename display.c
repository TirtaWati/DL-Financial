#include <stdio.h>
#include <stdlib.h>
#include "fungsi.h"
#include "struct.h"

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
	FILE *fin;
	struct datauser d;
	fin = fopen("info.txt", "r");
	system("clear");
			printf  ("\t\t\t\t\t==========================================\n");
			printf  ("\t\t\t\t\t||\t       ACCOUNT INFO\t\t||\n");
			printf  ("\t\t\t\t\t||--------------------------------------||\n");
			printf  ("\t\t\t\t\t||\tNAMA : %s\t\t\t||\n", &d.nama);
			printf  ("\t\t\t\t\t||\tEMAIL: %s\t\t\t||\n", &d.email);
			printf  ("\t\t\t\t\t||\tSAKU : %2.f\t\t\t||\n", d.uang);
			printf  ("\t\t\t\t\t==========================================\n");
			printf  ("\t\t\t\t\t||     Tekan ENTER  untuk melanjutkan   ||    \n");
			printf  ("\t\t\t\t\t==========================================\n");
    		getchar();
	fclose(fin);
}
