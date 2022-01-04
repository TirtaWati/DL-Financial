#include "variable.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//=======================================================================//
//***********************      REGISTRASI     ***************************//
//=======================================================================//
// Tgl  	  : 07-12-2021                                   	 //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022               //
// Revisi	  : 0		                                         //
// Nama Fungsi    : daftar                                               //
// Deskripsi      : Membuat Fungsi untuk melakukan registrasi yang akan  //
//		    akan dimasukkan oleh user.	       			 //
//=======================================================================//

/*************************************************************************|
|**************************     REGISTRASI    ****************************|
|=========================================================================|
|TANGGAL PEMBUATAN : 7 DESEMBER 2021                                      |
|OLEH : DWI TIRTA WATI                                                    |
|DESKRIPSI : REVISI FUNGSI UNTUK MELAKUKAN REGISTRASI PENGGUNA            |
|REVISI : 1                                                               |
|DESKRIPSI : Membuat dataLog.txt menyimpan tiap data pada 1 line, dan     |
|            menambahkan difine untuk membaca seluruh data di dataLog.txt |
**************************************************************************/

void daftar(){
    // Membuat pointer regis untuk file "dataLog.txt"
    FILE *registrasi;
    // Membuka file "dataLog.txt" dengan mode append
    registrasi = fopen(namaFile,"a");
    // Melakukan Pengecekan apakah pointer regis menunjuk kepada file yang dituju ("dataLog.txt")
    if (registrasi == NULL)
    {
        fputs("Tidak terdapat FILE!!", stderr);
        exit(1);
    }

    // Arahan untuk menginput nama dan email baru
    printf  ("\t\t\t\t\t================================================\n");
    printf  ("\t\t\t\t\t Silahkan registrasi akun anda terlebih dahulu! \n");
    printf  ("\t\t\t\t\t------------------------------------------------\n");
    getchar();
    printf  ("\t\t\t\t\tNama    : ");
    gets    (u.nama);
    printf  ("\t\t\t\t\tEmail   : ");
    scanf   ("%s", u.email);

    system("clear");
    printf  ("\n\t\t\t\t\t==========================================\n");
    printf  ("\t\t\t\t\tSelamat Datang %s!\n", u.nama);
    printf  ("\t\t\t\t\t------------------------------------------  \n");
    printf  ("\t\t\t\t\t    Silahkan input username (max 10)        \n");
    printf  ("\t\t\t\t\t    Silahkan input password (max 8)         \n");
    printf  ("\t\t\t\t\t==========================================  \n");
    // Arahan untuk menginput username serta password baru
    printf  ("\t\t\t\t\tUsername : ");
    scanf   ("%s", u.username);
    printf  ("\t\t\t\t\tPassword : ");
    scanf   ("%s", u.password);

    // Menuliskan data yang diinput oleh pengguna kedalam file "dataLog.txt"
    fwrite(&u,sizeof(u),1,registrasi);
    //print new line agar data lain tidak berada di satu baris yang sama
    fprintf(registrasi, "\n");               
    fclose(registrasi);
    getchar();
    system ("clear");
    // Memanggil fungsi masuk()
    masuk();
}

//=======================================================================//
//*************************       LOGIN     *****************************//
//=======================================================================//
// Tgl  	  : 07-12-2021                                   	 //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022               //
// Revisi	  : 0			                                 //
// Nama Fungsi    : masuk                                                //
// Deskripsi      : Membuat Fungsi untuk melakukan Log In yang akan      //
//		    akan dimasukkan oleh user.				 //
//=======================================================================//

/*************************************************************************|
|***************************    LOGIN     ********************************|
|=========================================================================|
|TANGGAL PEMBUATAN : 7 DESEMBER 2021                                      |
|OLEH : DWI TIRTA WATI                                                    |
|DESKRIPSI : REVISI FUNGSI UNTUK MELAKUKAN  lOGIN PENGGUNA                |
|REVISI : 1                                                               |
|DESKRIPSI : menambahkan file logrecord untuk menyimpan value username    |
|            yang ada di login agar dapat melakukan strcmp di fungsi lain |
**************************************************************************/
void masuk(){
    waktu();
    // Membuat pointer log untuk menunjuk pada file "dataLog.txt"
    FILE *log, *record;
    // Membuka file dengan mode "r"
    log = fopen (namaFile, "r");
    if (log == NULL){
        fputs ("Tidak terdapat FILE!!\n", stderr);
        daftar();
    }
    record = fopen("logrecord.txt", "w");           /* pointer record digunakan untuk membuka file logrecord.txt dengan mode w 
                                                     (dimana data yang tersimpan akan terus berganti setiap kali login dilakukan)*/

    // Arahan untuk LOGIN
    printf ("\n\t\t\t\t\t\t\t=====================\n");
    printf ("\t\t\t\t\t\t\t        LOGIN\n");
    printf ("\t\t\t\t\t\t\t---------------------\n");
    printf ("\t\t\t\t\t\t\t Username: ");
    scanf  ("%s", &username);
    printf ("\t\t\t\t\t\t\t---------------------\n");
    printf ("\t\t\t\t\t\t\t Password: ");
    scanf  ("%s", &password);
    printf ("\t\t\t\t\t\t\t--------------------\n");
    system ("clear");
    
    //value username ditulis dan disimpan pada file logrecord
    fwrite(&username, sizeof(username), 1, record);       

    //pengecekan username yang dimasukan apakah valid dengan dataLog.txt atau tidak
    while(fgets(&u, BUFFER_SIZE, log)){              // loop while, semua yang data dalam dataLog.txt dibaca 

        /*  Mengkomparasi username serta password yang diinput pengguna kedalam fungsi
            masuk() dengan username serta password yang sudah terdaftar */
        if(strcmp(&username, &u.username) == 0 && strcmp(&password, &u.password) == 0){      // membandingkan apakah username dan password valid
            system("clear");
            printf  ("\t\t\t\t\t Selamat Datang %s!!\n", &u.nama);
            home();
        }
        else if(strcmp(&username, &u.username)== 0 && strcmp(&password, &u.password) != 0 ){ // membandingkan apakah pass yang diinputkan salah
            system("clear");
			printf ("\n\n\t\t\t\t\t===============================\n");                      // kondisi kedua maka login gagal (karena pass salah)
			printf ("\t\t\t\t\tPassword yang Anda Masukan Salah!\n");
			printf ("\t\t\t\t\t===============================\n");
            //instruksi apakah user ingin melakukan login ulang
			printf ("Ingin Login Ulang? (Y|N): ");                
			scanf  ("%s", &yn);                                      
			if(strcmp(&yn, "y") == 0 || strcmp(&yn, "Y") == 0){   
				masuk();
			}else {
				exit(0);
			}
        }
        /* selain dua kondisi diatas maka sistem mengeluarkan printf dibawah dan keluar dari program
        akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar atau keluar dari program*/
        else {           
            system("clear");
            printf ("\n\n\t\t\t\t\t=============================================\n");
            printf("\t\t\t\t\t\tUsername tidak terdaftar!\n");
            printf("\t\t\t\t\tSilahkan melakukan registrasi terlebih dahulu");
            printf ("\n\t\t\t\t\t=============================================\n");
        }
    }
    /*menutup kedua file dataLog.txt dan logrecord.txt*/
    fclose(log);            
    fclose(record);
    return;
}
