#include <stdio.h>
#include <stdlib.h>
#include "fungsi.h"
#include "variable.h"

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
            return(0);
            break;
        case '2':
            registrasi();
            return(0);
            break;
        case '3':
            exit(0);     
    }
}

