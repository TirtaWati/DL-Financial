#include "variable.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void daftar(){
    // Membuat pointer regis untuk file "dataLog.txt"
    FILE *registrasi;
    // Membuka file "dataLog.txt" dengan mode "w"
    registrasi = fopen(namaFile,"w");
    // Melakukan Pengecekan apakah pointer regis menunjuk kepada file yang dituju ("dataLog.txt")
    if (registrasi == NULL)
    {
        fputs("Tidak terdapat FILE!!", stderr);
        exit(1);
    }

    // Arahan untuk menginput nama dan email baru
    printf("\n\n\t\t\t\t Silahkan registrasi akun anda terlebih dahulu!\n\n");
    getchar();
    printf("\t\t\t\tNama    : ");
    gets(u.nama);
    printf("\t\t\t\tEmail   : ");
    scanf ("%s", u.email);
    printf("\n\t\t\t\t\t Selamat Datang %s!\n", u.nama);
    printf ("\t\t\t\t\tSilahkan input username (max 10)\n");
    printf ("\t\t\t\t\tSilahkan input password (max 8)\n");

    // Arahan untuk menginput username serta password baru
    printf("\n\t\t\t\tUsername : ");
    scanf ("%s", u.username);
    printf("\t\t\t\tPassword : ");
    scanf ("%s", u.password);

    // Menuliskan nama yang diinput oleh pengguna kedalam file "dataLog.txt"
    fwrite(&u,sizeof(u),1,registrasi);
    fclose(registrasi);
    getchar();
    system ("clear");
    // Memanggil fungsi masuk()
    masuk();
}
    
void masuk(){
    char username[10];
    char password[8];

    // Variabel pilihan untuk pilihan user apakah ingin mendaftar atau keluar
    int pilihan;

    // Membuat pointer record untuk menunjuk pada file "dataLog.txt"
    FILE *record;
    // Membuka file dengan mode "r"
    record = fopen (namaFile, "r");
    if (record == NULL){
        fputs ("Tidak terdapat FILE!!\n", stderr);
        daftar();
    }

    // Arahan untuk LOGIN
    printf ("\n\n\t\t\t\t\t=====================\n");
    printf ("\t\t\t\t\t        LOGIN\n");
    printf ("\t\t\t\t\t---------------------\n");
    printf ("\t\t\t\t\t Username: ");
    scanf  ("%s", username);
    printf ("\t\t\t\t\t---------------------\n");
    printf ("\t\t\t\t\t Password: ");
    scanf  ("%s", password);
    printf ("\t\t\t\t\t--------------------\n");
    system ("clear");
    // Membaca file "dataLog.txt"
    while(fread(&u,sizeof(u),1,record)){
        /*  Mengkomparasi username serta password yang diinput pengguna kedalam fungsi
            masuk() dengan username serta password yang sudah terdaftar */
        if(strcmp(username, u.username)==0 && strcmp(password, u.password)==0){
            printf ("\n\n\t\t\t\t\t========================\n");
            printf ("\t\t\t\t\t     Login Berhasil!\n");
            printf ("\t\t\t\t\t========================\n");

        }
        //  Jika akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar atau keluar dari program
        else {
            printf ("\n\n\t\t\t\t\t===============================\n");
            printf ("\t\t\t\t\t      Akun tidak terdaftar!\n");
            printf ("\t\t\t\t\t===============================\n");

            instruksi:
            printf ("\t\t\t\t\tKetik 1 untuk daftar");
            printf ("\n\t\t\t\t\tKetik 2 untuk masuk ulang");
            printf ("\n\t\t\t\t\tKetik 3 untuk EXIT\n");
            printf ("\t\t\t\t\t-------------------------------\n");
            printf ("\t\t\t\t\tKetik Pilihan: ");
            scanf ("%d", &pilihan);
            system ("clear");
            // Jika pengguna mengetik nomor 1 maka akan dialihkan kepada fungsi daftar
            if (pilihan == 1){
                daftar();
            /* Menggunakan fungsi recursive kepada fungsi masuk agar pengguna
               dapat melakukan percobaan masuk kembali jika terjadi kesalahan penulisan */
            } else if (pilihan==2) {
                masuk();
            } else if (pilihan ==3){
                exit(1);
            } else {
                printf ("\n\n\t\t\t\t\t ERROR!!!\n");
                goto instruksi;
            }
        }
    }
    fclose(record);
    return;
}
void menu_masuk(){
    int pilihan;

    // Arahan yang diberikan kepada pengguna
    arahan:
    printf ("\n\n\t\t\t\t\t===============================================\n");
    printf ("\t\t\t\t\t||                 MENU MASUK                ||\n");
    printf ("\t\t\t\t\t||===========================================||\n");
    printf ("\t\t\t\t\t||   No  |    Menu                           ||\n");
    printf ("\t\t\t\t\t||-------|-----------------------------------||\n");
    printf ("\t\t\t\t\t||   1   |    Masuk                          ||\n");
    printf ("\t\t\t\t\t||   2   |    Registrasi                     ||\n");
    printf ("\t\t\t\t\t||   3   |    Exit                           ||\n");
    printf ("\t\t\t\t\t===============================================\n");
    printf ("\t\t\t\t\tInput pilihan Anda = ");
    scanf  ("%d", &pilihan);
    system ("clear");

    switch (pilihan){
    case 1:
        // Jika pengguna menginput angka 1 maka dipanggil fungsi masuk
        masuk();
        break;
    case 2:
        // Jika pengguna menginput angka 2 maka dipanggil fungsi registrasi
        daftar();
        break;
    case 3:
        exit(1);
        break;
    default:
    	error_alert();
        goto arahan;
        break;
    }
}
