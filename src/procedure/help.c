#include <stdio.h>

<<<<<<< HEAD
void help() {
    printf("Welcome to PURRMART:\n");
    printf("1. START - Membaca file konfigurasi default untuk memulai PURRMART.\n");
    printf("2. LOAD <filename> - Membaca save file <filename> untuk memulai PURRMART.\n");
    printf("3. LOGIN - Masuk ke akun di sistem PURRMART.\n");
    printf("4. LOGOUT - Keluar dari akun yang sedang login.\n");
    printf("5. REGISTER - Mendaftarkan akun baru ke dalam sistem PURRMART.\n");
    printf("6. WORK - Melakukan pekerjaan untuk mendapatkan uang.\n");
    printf("7. WORK CHALLENGE - Bermain challenge untuk mendapatkan uang tambahan.\n");
    printf("8. STORE LIST - Melihat daftar barang unik yang tersedia di toko.\n");
    printf("9. STORE REQUEST - Meminta penambahan barang baru ke dalam toko.\n");
    printf("10. STORE SUPPLY - Menambahkan barang ke toko dari antrian permintaan.\n");
    printf("11. STORE REMOVE - Menghapus barang yang ada di toko.\n");
    printf("12. SAVE - Menyimpan data permainan ke file.\n");
    printf("13. QUIT - Keluar dari PURRMART.\n");
    printf("14. HELP - Menampilkan daftar command dan deskripsinya.\n");
=======
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
        printf("LOGOUT -> Untuk keluar dari sesi\n");
        printf("SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("QUIT -> Untuk keluar dari program\n");
    } 
>>>>>>> afd1d1549a8e56ba31b2aad0c03a71eeb1b0d667
}
