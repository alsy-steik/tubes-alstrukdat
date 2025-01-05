// #include <stdio.h>
// #include "../adt/MesinKata/MesinKata.h"
// #include "../adt/MesinKarakter/MesinKarakter.h"
// #include "../adt/ArrayDin/ArrayDin.h"
// #include "../adt/Barang/barang.h"
// #include "../boolean.h"
// #include "../util/util.h"

// void store_remove(ArrayDin *arr) {
//     printf("Nama barang yang akan dihapus: ");
//     startKataMajemuk(NULL); 

//     int found = -1; // Indeks barang dalam array
//     for (int i = 0; i < getArrayDinLength(*arr); i++) {
//         Barang currentBarang = getArrayDinElmt(*arr, i);
//         if (is_same_string(currentKata.buffer, currentBarang.name)) {
//             found = i;
//             break;
//         }
//     }

//     if (found != -1) {
//         ArrayDinDeleteElem(arr, found);
//         PrintKata(currentKata);
//         printf(" telah berhasil dihapus.\n");
//     } else {
//         printf("Toko tidak menjual ");
//         PrintKata(currentKata);
//         printf(".\n");
//     }
// }

// // Fungsi testing untuk prosedur store_remove
// void test_store_remove() {
//     // Inisialisasi array dinamis
//     ArrayDin barangStore;
//     MakeEmptyArrayDin(&barangStore);
//     Barang barang1 = {"Beras", 10000};
//     Barang barang2 = {"Gula", 15000};
//     Barang barang3 = {"Minyak Goreng", 20000};

//     // Menambahkan barang ke dalam ArrayDin
//     ArrayDinInsertEnd(&barangStore, barang1);
//     ArrayDinInsertEnd(&barangStore, barang2);
//     ArrayDinInsertEnd(&barangStore, barang3);

//     // Menampilkan barang sebelum penghapusan
//     printf("Daftar barang di toko:\n");
//     for (int i = 0; i < getArrayDinLength(barangStore); i++) {
//         Barang currentBarang = getArrayDinElmt(barangStore, i);
//         printf("- %s: Rp%d\n", currentBarang.name, currentBarang.price);
//     }

//     // Simulasi input barang yang akan dihapus
//     printf("\nSimulasi penghapusan barang...\n");
//     store_remove(&barangStore);

//     // Menampilkan barang setelah penghapusan
//     printf("\nDaftar barang setelah penghapusan:\n");
//     for (int i = 0; i < getArrayDinLength(barangStore); i++) {
//         Barang currentBarang = getArrayDinElmt(barangStore, i);
//         printf("- %s: Rp%d\n", currentBarang.name, currentBarang.price);
//     }

// }

// void help() {
//     printf("Welcome to PURRMART:\n");
//     printf("1. START - Membaca file konfigurasi default untuk memulai PURRMART.\n");
//     printf("2. LOAD <filename> - Membaca save file <filename> untuk memulai PURRMART.\n");
//     printf("3. LOGIN - Masuk ke akun di sistem PURRMART.\n");
//     printf("4. LOGOUT - Keluar dari akun yang sedang login.\n");
//     printf("5. REGISTER - Mendaftarkan akun baru ke dalam sistem PURRMART.\n");
//     printf("6. WORK - Melakukan pekerjaan untuk mendapatkan uang.\n");
//     printf("7. WORK CHALLENGE - Bermain challenge untuk mendapatkan uang tambahan.\n");
//     printf("8. STORE LIST - Melihat daftar barang unik yang tersedia di toko.\n");
//     printf("9. STORE REQUEST - Meminta penambahan barang baru ke dalam toko.\n");
//     printf("10. STORE SUPPLY - Menambahkan barang ke toko dari antrian permintaan.\n");
//     printf("11. STORE REMOVE - Menghapus barang yang ada di toko.\n");
//     printf("12. SAVE - Menyimpan data permainan ke file.\n");
//     printf("13. QUIT - Keluar dari PURRMART.\n");
//     printf("14. HELP - Menampilkan daftar command dan deskripsinya.\n");
// }

// int main() {
//     help();
//     printf("=== TESTING store_remove ===\n");
//     test_store_remove();
//     return 0;
// }
