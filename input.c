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


//header untuk menampung libraries yang ada baik yang global mapun local
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "variable.h"
#include "function.h"
//define buffer_size ini untuk mendeklarasikan banyak/jumlah buffer max pada file
#define BUFFER_SIZE 1000

//fungsi login dimana user akan melakukan login akun
void login (void){
    struct datauser d;  // deklarasi untuk strurt datauser akan dipanggil dengan menggunakan "d"
    FILE *fu, *fp;      // penggunaan file handling pada program, mendeklarasikan pointer
    fu = fopen("info.txt", "r"); //pointer fu digunakan untuk membuka file info.txt dengan mode read
    fp = fopen("logrecord.txt", "w"); /* pointer fp digunakan untuk membuka file logrecord.txt dengan mode w 
                                        (dimana data yang tersimpan akan terus berganti setiap kali login dilakukan)*/
    
    if(fu == NULL){                        //mengecek apakah file info.txt terdapat nilai
        printf("ERROR IN OPENING FILE");   //jika tidak maka program akan melakukan prinrf dan keluar
		exit(0);
    }
    //tampilan login
    system ("clear");
    printf ("\n\n\t\t\t\t\t=====================\n");
    printf ("\t\t\t\t\t        LOGIN\n");
    printf ("\t\t\t\t\t---------------------\n");
    printf ("\t\t\t\t\t Username: ");               //user memasukan username
    scanf  ("%s", &usrname);                        //memasukan value ke dalam usrname
    printf ("\t\t\t\t\t---------------------\n");
    printf ("\t\t\t\t\t Password: ");               //user memasukan password
    scanf  ("%s", &pass);                           //memasukan value ke dalam pass
    printf ("\t\t\t\t\t--------------------\n");

    fwrite(&usrname, sizeof(usrname), 1, fp);       //value usrname ditulis dan disimpan pada file logrecord

    //pengecekan username yang dimasukan apakah valid dengan info.txt atau tidak
    while(fgets(&d, BUFFER_SIZE, fu)){              //loop while, semua yang data dalam info.txt dibaca 
        if(strcmp(&usrname, &d.username) == 0 && strcmp(&pass, &d.password) == 0){      //membandingkan apakah username dan password valid
            system("clear");
            printf  ("\n\n\t\t\t\t\t=============================================\n");  //kondisi pertama maka login berhasil
            printf  ("\t\t\t\t\t||\t    Selamat Datang %s\t   ||\n", &d.nama);
            home();
        }
        else if(strcmp(&usrname, &d.username)== 0 && strcmp(&pass, &d.password) != 0 ){ //membandingkan apakah pass yang diinputkan salah
            system("clear");
			printf ("\n\n\t\t\t\t\t===============================\n");                 //kondisi kedua maka login gagal (karena pass salah)
			printf ("\t\t\t\t\tPassword yang Anda Masukan Salah!\n");
			printf ("\t\t\t\t\t===============================\n");
            //instruksi apakah user ingin melakukan login ulang
			printf ("Ingin Input Ulang? (Y|N): ");                
			scanf  ("%s", &yn);                                      
			if(strcmp(&yn, "y") == 0 || strcmp(&yn, "Y") == 0){   
				login();
			}else {
				exit(0);
			}
        }
        else{           //selain dua kondisi diatas maka sistem mengeluarkan printf dibawah dan keluar dari program
            system("clear");
            printf ("\n\n\t\t\t\t\t=============================================\n");
            printf("\t\t\t\t\t\tUsername tidak terdaftar!\n");
            printf("\t\t\t\t\tSilahkan melakukan registrasi terlebih dahulu");
            printf ("\n\t\t\t\t\t=============================================\n");
        }
    }
    fclose(fu);     /*menutup kedua file info.txt dan logrecord.txt*/
    fclose(fp);
}

//fungsi registrasi dimana user akan melakukan register akun baru
void registrasi (void){
    struct datauser d;      // deklarasi untuk strurt datauser akan dipanggil dengan menggunakan "d"
    FILE *fu;               // penggunaan file handling pada program, mendeklarasikan pointer

    fu = fopen("info.txt", "a+");  //pointer fu digunakan untuk membuka file info.txt dengan mode apend dan baca
    
    //mengecek apakah file info.txt ada
    if (fu == NULL) {               
        printf("ERROR IN OPENING FILE");
    }

    system("clear");                    
    printf("\t\t\t\tNama    : ");           //user memasukan nama
    scanf ("%s", d.nama);                   //value dimasukan ke sturct datauser variable nama
    printf("\t\t\t\tEmail   : ");           //user memasukan email
    scanf ("%s", d.email);                  //value dimasukan ke sturct datauser variable email
    printf("\n\t\t\t\t\t Selamat Datang %s!\n", d.nama);   //valuae dari d.nama dipanggil
    printf("\t\t\t\t\tSilahkan input username (max 10)\n");
    printf("\t\t\t\t\tSilahkan input password (max 8)\n");

    //input username dan password user untuk login
    printf("\n\t\t\t\tUsername : ");
    scanf ("%s", d.username);
    printf("\t\t\t\tPassword : ");
    scanf ("%s", d.password);

    //input nominal uang saku pertama
    printf("\t\t\t\tMasukan total uang saku Anda: ");
    scanf ("%f",&d.uang);

    //semua data yang sudah diinputkan ditulis ke dalam info.txt
    fwrite(&d, sizeof(d), 1, fu);
	fprintf(fu,"\n");           //print new line agar data lain tidak berada di satu baris yang sama
    fclose(fu);             //menutup info.txt

    //masuk ke fungsi login
	login();
}

void pemasukan (void){
    
}
void pengeluaran (void){

}