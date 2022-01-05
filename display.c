#include "variable.h"
#include "structure.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//=======================================================================//
//************  Fungsi Untuk Menampilkan Tampilan Awal   ****************//
//=======================================================================//
// Tgl  	  : 07-12-2021                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	      	 //
// Revisi	  : 0		  					 //
// Nama Fungsi    : header                                               //
// Deskripsi      : Menampilkan sebuah tampilan awal saat program        //
//		   		 	dijalankan                       //
//=======================================================================//
void header (void){
    system ("clear");
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

//=======================================================================//
//***********************      ERROR ALERT     **************************//
//=======================================================================//
// Tgl  	  : 07-12-2021                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	         //
// Revisi	  : 0		      					 //
// Nama Fungsi    : error_alert                                          //
// Deskripsi      : Menampilkan pemberitahuan ketika user menginputkan   //
//		    		pilihan yang salah                       //
//=======================================================================//
void error_alert(){
    printf   ("\n\n\t\t\t\t\t||            Pilihan Tidak Ada!!!           || \n");
    printf   ("\t\t\t\t\t||       Silahkan Pilih Pilihan yang Ada     || \n");
	getchar();
	getchar();
	system("clear");
}

//=======================================================================//
//***********************      WAKTU SERVER    **************************//
//=======================================================================//
// Tgl  	  : 02-01-2022                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	         //
// Revisi	  : 0		      					 //
// Nama Fungsi    : waktu                                                //
// Deskripsi      : Fungsi waktu() ini digunakan untuk mengambil dan     //
//                  menampilkan waktu sistem saat user mengakses program.//
//=======================================================================//
void waktusrvr(){
    time( &waktuserver);
    struct tm * waktu = localtime( & waktuserver);
    printf("\n\t\t||=============================Tanggal: %i/%i/%i================================||\n\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900);
}


/*************************************************************************|
|*********************      DISPLAY INFO AKUN      ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 13 DESEMBER 2021                       		  |
|OLEH : DWI TIRTA WATI                                      		  |
|DESKRIPSI : Membuat fungsi infouser() untuk menampilkan data-data user   |
|REVISI : 0                                                 		  |
|*************************************************************************/

/*************************************************************************|
|*********************      DISPLAY INFO AKUN      ***********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 14 DESEMBER 2021                       		  |
|OLEH : DWI TIRTA WATI                                      		  |
|DESKRIPSI : Membuat fungsi infouser untuk menampilkan data-data user     |
|            setelah menu home pilihan 5				  |
|REVISI : 1                                                 		  |
|DESKRIPSI : membuat file logrecord yang ada pada logngsi login termuat di|
|            fungsi ini agar dapat memanggil data user pada dataLog.txt   | 
|*************************************************************************/

//=======================================================================//
//********************      DISPLAY INFO AKUN      **********************//
//=======================================================================//
// Tgl  	  : 21-12-2021                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	      	 //
// Revisi	  : 2		  					 //
// Nama Fungsi    : infouser                                             //
// Deskripsi      : Menambahkan info user yaitu username dan password    //
//		    sesuai dengan account yang sedang dijalankan.        //
//=======================================================================//

void infouser (void){
// penggunaan file handling pada program, mendeklarasikan pointer
	FILE *log, *record;
	log = fopen("dataLog.txt", "r");		    	// pointer log digunakan untuk membuka file dataLog.txt dengan mode read 
	record = fopen("logrecord.txt", "r"); 			/* pointer record digunakan untuk membuka file logrecord.txt dengan mode w 
                                		           	   (dimana data yang tersimpan akan terus berganti setiap kali login dilakukan)*/
	while(fgets(&u, BUFFER_SIZE, log)){																					// membaca keseluruhan isi dari dataLog.txt
		if(strcmp(username, u.username) == 0){																					// membandingkan apakah username logrecord dan username dataLog.txt sama
		    system("clear");
			//jika kondisi terpernuhi maka ditampilkan keseluruhan info user yang ada dan yang sesuai dengan username
			printf  ("\t\t\t\t\t    ==========================================\n");	
			printf  ("\t\t\t\t\t                  ACCOUNT INFO\n");
			printf  ("\t\t\t\t\t    ------------------------------------------\n");
			printf  ("\t\t\t\t\t\t      NAMA     : %s\n", &u.nama);
			printf  ("\t\t\t\t\t\t      EMAIL    : %s\n", &u.email);
			printf  ("\t\t\t\t\t\t      USERNAME : %s\n", &u.username);
			printf  ("\t\t\t\t\t\t      PASSWORD : %s\n", &u.password);
			printf  ("\t\t\t\t\t\t      SAKU     : Rp%2.f\n", u.saku);
			printf  ("\t\t\t\t\t    ==========================================\n");
			printf  ("\t\t\t\t\t     Tekan ENTER untuk kembali Halaman Utama \n");
			printf  ("\t\t\t\t\t    ==========================================\n");
			getchar();
			getchar();
		}
	}
	fclose(log);		/*menutup kedua file dataLog.txt dan leogrecord.txt*/
	fclose(record);
	system("clear");
	home();
}

/*************************************************************************|
|******************      DISPLAY LAPORAN TRANSAKSI    ********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 20 DESEMBER 2021                       		  |
|OLEH : DWI TIRTA WATI                                      		  |
|DESKRIPSI : Membuat fungsi laporan() untuk menampilkan transaksi yang    |
|			 dilakukan oleh user				  |
|REVISI : 0                                                 		  |
|*************************************************************************/

//=======================================================================//
//******************     DISPLAY LAPORAN TRANSAKI    ********************//
//=======================================================================//
// Tgl  	  : 02-01-2022                                           //
// Oleh		  : Leony Mona Putri Sihaloho - 2105551022     	         //
// Revisi	  : 1		      					 //
// Nama Fungsi    : laporan                                              //
// Deskripsi      : Menambahkan fungsi waktu() untuk memanggil waktu     //
//                  sistem dan mengubah struktur tampilan data dari      //
//                  pemasukan dan pengeluaran sebelumnya.                //
//=======================================================================//

/*************************************************************************|
|******************      DISPLAY LAPORAN TRANSAKSI   *********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 2 JANUARI 2022                                       |
|OLEH : DWI TIRTA WATI                                                    |
|DESKRIPSI : REVISI FUNGSI LAPORAN() UNTUK TAMPILAN LAPORAN TRANSAKSI     |
|REVISI : 2                                                               |
|DESKRIPSI : Menambahkan file memory baru "transaksi.txt" untuk menyimpan |
|            hasil laporan transaksi agar dapat digunakan pada fungsi     |
|            lap_bulan()						  |						  |
**************************************************************************/

void laporan (){
	time_t t;

    time(&t);
    struct tm*n  = localtime(&t);
        waktu.bulan = n ->tm_mon + 1;
        waktu.tgl = n ->tm_mday;
        waktu.tahun = n ->tm_year + 1900;

	// penggunaan file handling pada program, mendeklarasikan pointer
	FILE *data, *record, *trans;
	data = fopen("dataLog.txt", "r");  																			// pointer data digunakan untuk membuka file dataLog.txt dengan mode read 
	record = fopen("logrecord.txt", "r"); 																		// pointer record digunakan untuk membuka file logrecord.txt dengan mode read
	trans = fopen("transaski.txt", "a");

	//membaca username yang ada di file dataLog.txt dan mencari kesamaan antar username yang ada di logrecord
	while(fgets(&u, BUFFER_SIZE, data)){																	// membaca keseluruhan isi dari dataLog.txt
		if(strcmp(username, u.username) == 0){																		// membandingkan apakah username logrecord dan username dataLog.txt sama
			system("clear");
			printf ("\t\t========================================================================================\n");
			printf ("\t\t                                        PEMASUKAN                                       \n");
			printf ("\t\t========================================================================================\n");
			printf ("\t\t|     Nama     		|     Pemasukan     |        Kategori  		|	Jumlah Saku	   	 \n");
			printf ("\t\t|%s             		Rp%2.f             %s                 	  Rp%2.f			 \n", &u.nama, u.pemasukan, u.kategori_in, u.saku);
			printf ("\t\t========================================================================================\n");
			printf ("\t\t\n                                     PENGELUARAN                                      \n");
			printf ("\t\t========================================================================================\n");
			printf ("\t\t|     Nama     		|     Pengeluaran   |        Kategori  		|	Jumlah Saku	 \n");
			printf ("\t\t|%s          			Rp%2.f             %s               	  Rp%2.f				 \n", &u.nama, u.pengeluaran, u.kategori_out, u.saku);
			printf ("\t\t|=======================================================================================|\n");
			//jika kondisi terpernuhi maka ditampilkan keseluruhan transaksi yang ada dan yang sesuai dengan username
			
			printf  ("\t\t=======================================================================================\n");
			printf  ("\t\t\t\t\t\t     Tekan ENTER untuk kembali ke Menu Laporan	   \n");
			printf  ("\t\t=======================================================================================\n");
			getchar();
			getchar();

			// menyimpan di file transaksi.txt
			fprintf (trans, "\n\t\tFOR USERNAME: %s																 		 \n", &u.username);
			fprintf (trans, "\t\t========================================================================================\n");
			fprintf (trans, "\t\t                                        PEMASUKAN                                       \n");
			fprintf (trans, "\t\t========================================================================================\n");
			fprintf (trans, "\t\t|     Tanggal     |     Nama     |     Pemasukan     |     Kategori     |Jumlah Saku	 \n");
			fprintf (trans, "\t\t|%02i/%02i/%i          %s          Rp%2.f           %s               Rp%2.f			 \n", waktu.bulan, waktu.tgl, waktu.tahun, &u.nama, u.pemasukan, u.kategori_in, u.saku);
			fprintf (trans, "\t\t========================================================================================\n");
			fprintf (trans, "\t\t\n                                     PENGELUARAN                                      \n");
			fprintf (trans, "\t\t========================================================================================\n");
			fprintf (trans, "\t\t|     Tanggal     |     Nama     |     Pengeluaran   |     Kategori     |Jumlah Saku	 \n");
			fprintf (trans, "\t\t|%02i/%02i/%i          %s          Rp%2.f          %s               Rp%2.f				 \n", waktu.bulan, waktu.tgl, waktu.tahun, &u.nama, u.pengeluaran, u.kategori_out, u.saku);
			fprintf (trans, "\t\t|=======================================================================================|\n\n");
		}
		
	}
	fclose(data);		/*menutup file dataLog.txt dan logrecord.txt*/
	fclose(record);
	fclose(trans);
	system("clear");
	menu_laporan();
}

/*************************************************************************|
|******************      DISPLAY LAPORAN BULANAN     *********************|
|=========================================================================|
|TANGGAL PEMBUATAN : 3 Januari 2022                                       |
|OLEH : DWI TIRTA WATI                                                    |
|DESKRIPSI : Membuat fungsi lap_bulan() untuk menampilkan laporan sesuai   |
|			 dengan inputan bulan dari user								  |
|REVISI : 0                                                               |
**************************************************************************/

void lap_bulan(){
	int bulan;
	FILE *trans, *record;
	char buff[BUFFER_SIZE];
	trans = fopen("transaski.txt", "r");
	record = fopen("logrecord.txt", "r");
	
	printf ("========================================================================================\n");
	printf ("               ----   Masukan Nomor Bulan Yang Ingin Ditampilkan   ---                  \n");
	printf (" Keterangan:\n");
	printf (" JANUARI   --> 1	FEBRUARI --> 2		MARET    --> 3		APRIL    --> 4\n");
	printf (" MEI       --> 5	JUNI	 --> 6		JULI     --> 7		AGUSTUS  --> 8\n");
	printf (" SEPTEMBER --> 9	OKTOBER  --> 10		NOVEMBER --> 11		DESEMBER --> 12\n");
	printf ("========================================================================================\n");
	printf("\n\nMasukan nomor bulan: ");
	scanf("%i", &bulan);

	while(fgets(&buff, BUFFER_SIZE, trans)){
		if(strcmp(&u.username, &username)== 0 && waktu.bulan == bulan){
			system("clear");

			printf ("\t\t========================================================================================\n");
			printf ("\t\t                                        PEMASUKAN                                       \n");
			printf ("\t\t========================================================================================\n");
			printf ("\t\t|     Tanggal     |     Nama     |     Pemasukan     |     Kategori     |Jumlah Saku	 \n");
			printf ("\t\t|%02i/%02i/%i          %s          Rp%2.f           %s               Rp%2.f			 \n", waktu.bulan, waktu.tgl, waktu.tahun, &u.nama, u.pemasukan, u.kategori_in, u.saku);
			printf ("\t\t========================================================================================\n");
			printf ("\t\t\n                                     PENGELUARAN                                      \n");
			printf ("\t\t========================================================================================\n");
			printf ("\t\t|     Tanggal     |     Nama     |     Pengeluaran   |     Kategori     |Jumlah Saku	 \n");
			printf ("\t\t|%02i/%02i/%i          %s          Rp%2.f          %s               Rp%2.f				 \n", waktu.bulan, waktu.tgl, waktu.tahun, &u.nama, u.pengeluaran, u.kategori_out, u.saku);
			printf ("\t\t|=======================================================================================|\n");
			//jika kondisi terpernuhi maka ditampilkan keseluruhan transaksi yang ada dan yang sesuai dengan username
			
			printf  ("\t\t\t\t\t===================================================\n");
			printf  ("\t\t\t\t\t     Tekan ENTER untuk kembali ke Menu Laporan	   \n");
			printf  ("\t\t\t\t\t===================================================\n");
			getchar();
			getchar();
			menu_laporan();
			
		}
		else{
			printf  ("\t\t\t\t\t===================================================\n");
			printf  ("\t\t\t\t\t             Riwayat Tidak Ditemukan!			   \n");
			printf  ("\t\t\t\t\t===================================================\n");
			getchar();
			getchar();
			system("clear");
			menu_laporan();
		}
	}
	fclose(trans);
	fclose(record);
	


}




