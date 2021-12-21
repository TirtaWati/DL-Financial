#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "variable.h"
#include "function.h"

/*************************************************************************|
|*********************       FUNGSI PEMASUKAN      ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 17 DESEMBER 2021                       			  |
|OLEH : DWI TIRTA WATI                                      			  |
|DESKRIPSI : Membuat fungsi pemasukan(), untuk menginput pemasukan dan    |
|            Kategori pemasukan user.                                     |
|REVISI : 0                                                 			  |
|*************************************************************************/

/*************************************************************************|
|*********************       FUNGSI PEMASUKAN      ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 18 DESEMBER 2021                       			  |
|OLEH : DWI TIRTA WATI                                      			  |
|DESKRIPSI : Revisi fungsi pemasukan(), untuk menginput pemasukan dan     |
|            Kategori pemasukan user.                                     |
|REVISI : 1                                                 			  |
|DESKRIPSI : membuat file temp.txt, digunakan untuk menyimpan data update |
|            (yang berupa inputan user) sementara untuk disimpan pada file|
|            dataLog.txt nantinya                                         |
|*************************************************************************/

/*************************************************************************|
|*********************       FUNGSI PEMASUKAN      ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 19 DESEMBER 2021                       			  |
|OLEH : DWI TIRTA WATI                                      			  |
|DESKRIPSI : Revisi fungsi pemasukan(), untuk menginput pemasukan dan     |
|            Kategori pemasukan user.                                     |
|REVISI : 2                                                 			  |
|DESKRIPSI : menambahkan struct transaksi di dalam struct user, tampilan  |
|            setelah data berhasil diinputkan dan masuk ke menu home      |
|*************************************************************************/
void pemasukan (){
    int found = 0;                                      //variable found untuk menunjukan sistem bahwa data akan dimasukan sesuai dengan baris dari username yang dituju
    
    // penggunaan file handling pada program, mendeklarasikan pointer
    FILE *data, *record, *temp; 

    data = fopen("dataLog.txt", "r");                   // pointer data digunakan untuk membuka file dataLog.txt dengan mode read 
    record = fopen("logrecord.txt", "r");               // pointer record digunakan untuk membuka file logrecord.txt dengan mode read
    temp = fopen("temp.txt", "w");                      // pointer temp digunakan untuk membuka file temp.txt dengan mode write

    while (fgets(&u, BUFFER_SIZE, data))                // membaca keseluruhan isi dari dataLog.txt
    {
          if(strcmp(username, u.username) == 0){        // membandingkan apakah username logrecord dan username dataLog.txt sama
            found = 1;                                  // memberi nilai pada varible found untuk menyatakan bahwa baris data yang dituju ada 
            // tampilan penginputan pemasukan dan ketegori pemasukan
            printf ("\n\n\t\t\t\t\t================================\n");
            printf ("\t\t\t\t\t    Pemasukan Anda Hari ini\n");
            printf ("\t\t\t\t\t--------------------------------\n");
            printf ("\t\t\t\t\t Pemasukan : ");
            scanf  ("%f", &u.in.pemasukan);
            printf ("\t\t\t\t\t--------------------------------\n");
            printf ("\t\t\t\t\t Kategori  : ");
            scanf  ("%s", &u.in.kategori);
            u.saku += u.in.pemasukan;           //menjumlahkan pemasukan ke jumlah dari u.saku
          }
          fwrite(&u, sizeof(u), 1, temp);       //memasukan data ke file temp.txt (data sementara)
    }
    fclose(data);                               //menutup file dataLog.txt, logrecord.txt, dan temp.txt
    fclose(record);
    fclose(temp);

    if(found){                                  // ketika found = 1 maka program dibawahnya dijalankan
        data = fopen("dataLog.txt", "w");       // pointer data digunakan untuk membuka file dataLog.txt dengan mode write 
        temp = fopen("temp.txt", "r");          // pointer record digunakan untuk membuka file temp.txt dengan mode read
        
        while(fread(&u, sizeof(u), 1, temp)){   // membaca data yang ada pada file temp.txt
            fwrite(&u, sizeof(u), 1, data);     // memasukan data yang ada di temp.txt ke dalam dataLog.txt
            fprintf(data, "\n");
        }

        fclose(data);                           // menutup file dataLog.txt, logrecord.txt, dan temp.txt
        fclose(temp);

        // tampilan ketika data berhasil diinputkan dan kembali ke menu home
        system("clear");
        printf  ("\t\t\t\t\t=============================================\n");
        printf  ("\t\t\t\t\t          Data Berhasil diinputkan!!         \n");
        printf  ("\t\t\t\t\t---------------------------------------------\n");
        printf  ("\t\t\t\t\t       Tekan ENTER  untuk melanjutkan....    \n");
        printf  ("\t\t\t\t\t=============================================\n");
        getchar();
    }
    system("clear");
    home();                                     // memanggil fungsi home()
}

/*************************************************************************|
|*********************       FUNGSI PENGELUARAN    ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 17 DESEMBER 2021                       			  |
|OLEH : DWI TIRTA WATI                                      			  |
|DESKRIPSI : Membuat fungsi pengeluaran(), untuk menginput pengeluaran dan|
|            Kategori pengeluaran user.                                   |
|REVISI : 0                                                 			  |
|*************************************************************************/

/*************************************************************************|
|*********************       FUNGSI PENGELUARAN    ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 18 DESEMBER 2021                       			  |
|OLEH : DWI TIRTA WATI                                      			  |
|DESKRIPSI : Membuat fungsi pengeluaran(), untuk menginput pengeluaran dan|
|            Kategori pengeluaran user.                                   |
|REVISI : 1                                                 			  |
|DESKRIPSI : membuat file temp.txt, digunakan untuk menyimpan data update |
|            (yang berupa inputan user) sementara untuk disimpan pada file|
|            dataLog.txt nantinya                                         |
|*************************************************************************/

/*************************************************************************|
|*********************       FUNGSI PENGELUARAN    ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 19 DESEMBER 2021                       			  |
|OLEH : DWI TIRTA WATI                                      			  |
|DESKRIPSI : Membuat fungsi pengeluaran(), untuk menginput pengeluaran dan|
|            Kategori pengeluaran user.                                   |
|REVISI : 2                                                 			  |
|DESKRIPSI : menambahkan struct transaksi di dalam struct user, tampilan  |
|            setelah data berhasil diinputkan dan masuk ke menu home      |
|*************************************************************************/
int pengeluaran (){
    int found = 0; //variable found untuk menunjukan sistem bahwa data akan dimasukan sesuai dengan baris dari username yang dituju
    
    // penggunaan file handling pada program, mendeklarasikan pointer
    FILE *data, *record, *temp;

    data = fopen("dataLog.txt", "r");       // pointer data digunakan untuk membuka file dataLog.txt dengan mode read 
    record = fopen("logrecord.txt", "r");   // pointer record digunakan untuk membuka file logrecord.txt dengan mode read
    temp = fopen("temp.txt", "w");          // pointer temp digunakan untuk membuka file temp.txt dengan mode write

    while (fgets(&u, BUFFER_SIZE, data))    //membaca keseluruhan isi dari dataLog.txt
    {
          if(strcmp(username, u.username) == 0){
            found = 1;
            printf ("\n\n\t\t\t\t\t================================\n");
            printf ("\t\t\t\t\t    Pengeluaran Anda Hari ini\n");
            printf ("\t\t\t\t\t--------------------------------\n");
            printf ("\t\t\t\t\t Pengeluaran : ");
            scanf  ("%f", &u.out.pengeluaran);
            printf ("\t\t\t\t\t--------------------------------\n");
            printf ("\t\t\t\t\t Kategori    : ");
            scanf  ("%s", &u.out.kategori);
            u.saku -= u.out.pengeluaran;        // mengurangi jumlah dari u.saku dengan total pengeluaran
          }
          fwrite(&u, sizeof(u), 1, temp);       // memasukan data ke file temp.txt (data sementara)
          
    }
    fclose(data);                               // menutup file dataLog.txt, logrecord.txt, dan temp.txt
    fclose(record);
    fclose(temp);

    if(found){                                  // ketika found = 1 maka program dibawahnya dijalankan
        data = fopen("dataLog.txt", "w");       // pointer data digunakan untuk membuka file dataLog.txt dengan mode write 
        temp = fopen("temp.txt", "r");          // pointer record digunakan untuk membuka file temp.txt dengan mode read
        
        while(fread(&u, sizeof(u), 1, temp)){   // membaca data yang ada pada file temp.txt
            fwrite(&u, sizeof(u), 1, data);     // memasukan data yang ada di temp.txt ke dalam dataLog.txt
            fprintf(data, "\n");
        }

        fclose(data);                           // menutup file dataLog.txt, logrecord.txt, dan temp.txt
        fclose(temp);
        
        // tampilan ketika data berhasil diinputkan dan kembali ke menu home
        system("clear");
        printf  ("\t\t\t\t\t=============================================\n");
        printf  ("\t\t\t\t\t          Data Berhasil diinputkan!!         \n");
        printf  ("\t\t\t\t\t---------------------------------------------\n");
        printf  ("\t\t\t\t\t       Tekan ENTER  untuk melanjutkan....    \n");
        printf  ("\t\t\t\t\t=============================================\n");
        getchar();
    }
    system("clear");
    home();                                     // memanggil fungsi home()
}
