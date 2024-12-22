#include <stdio.h>

void help(int menu) {
    if (menu == 1) { // Welcome Menu
        printf("=====[ Welcome Menu Help PURRMART]=====\n");
        printf("START -> Untuk masuk sesi baru\n");
        printf("LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("QUIT -> Untuk keluar dari program\n");
    } 
    else if (menu == 2) { // Login Menu
        printf("=====[ Login Menu Help PURRMART]=====\n");
        printf("REGISTER -> Untuk melakukan pendaftaran akun baru\n");
        printf("LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("QUIT -> Untuk keluar dari program\n");
    } 
    else if (menu == 3) { // Main Menu
        printf("=====[ Menu Help PURRMART]=====\n");
        printf("WORK -> Untuk bekerja\n");
        printf("WORK CHALLENGE -> Untuk mengerjakan challenge\n");
        printf("STORE LIST -> Untuk melihat barang-barang di toko\n");
        printf("STORE REQUEST -> Untuk meminta penambahan barang\n");
        printf("STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
        printf("STORE REMOVE -> Untuk menghapus barang\n");
        printf("PROFILE -> Untuk melihat data diri pengguna (hanya saat login)\n");
        printf("CART ADD <nama> <n> -> Untuk menambahkan barang ke keranjang belanja\n");
        printf("CART REMOVE <nama> <n> -> Untuk mengurangi barang dari keranjang belanja\n");
        printf("CART SHOW -> Untuk melihat isi keranjang belanja\n");
        printf("CART PAY -> Untuk melakukan pembayaran keranjang belanja\n");
        printf("HISTORY <n> -> Untuk melihat riwayat pembelian\n");
        printf("WISHLIST ADD -> Untuk menambahkan barang ke wishlist\n");
        printf("WISHLIST SWAP <i> <j> -> Untuk menukar posisi barang di wishlist\n");
        printf("WISHLIST REMOVE <i> -> Untuk menghapus barang dari wishlist berdasarkan posisi\n");
        printf("WISHLIST REMOVE -> Untuk menghapus barang dari wishlist berdasarkan nama\n");
        printf("WISHLIST CLEAR -> Untuk mengosongkan seluruh isi wishlist\n");
        printf("WISHLIST SHOW -> Untuk melihat barang-barang di wishlist\n");
        printf("LOGOUT -> Untuk keluar dari sesi\n");
        printf("SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("QUIT -> Untuk keluar dari program\n");
    } 
}
