//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdlib.h>
#include "login.c"
#include "menu.c"
#include "display.c"
#include "transaksi.c"

// fungsi main () adalah kepala dari program ini, dimana program akan di eksekusi oleh fungsi main ini.
int main (){
    header();
    system ("clear");
    menu_masuk();
}
