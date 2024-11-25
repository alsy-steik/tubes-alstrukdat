#include <stdio.h>

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
}
