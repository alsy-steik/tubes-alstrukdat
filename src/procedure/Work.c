#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MesinKata.h"
#include "MesinKarakter.h"
#include "boolean.h"

// https://www.tutorialspoint.com/c_standard_library/time_h.htm
// MAKRO time.h
// NULL - Indef

// Function Buat Waktu Tunggu
void Jeda(int Detik){
    time_t Waktu;
    Waktu = time(NULL);
    
    while (time(NULL) - Waktu < Detik){
        // Loop sampe detik yang diinput
    }
}

// Function buat ngebanding string
boolean BandingString(const char *String1, const char *String2) {
    int Indeks = 0;
    if (String1 == NULL || String2 == NULL) {
        return false;
    }
    while (String1[Indeks] != '\0' && String2[Indeks] != '\0') {
        if (String1[Indeks] != String2[Indeks]) {
            return false;
        }
        Indeks++;
    }
    return (String1[Indeks] == '\0' && String2[Indeks] == '\0');
}

// Function buat nampilin daftar work
void DaftarWork(){
    printf("Daftar Pekerjaan:\n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("\n");
}

// Function buat ngebaca string per karakter
// ga pake Word karena harus baca spasinya juga
void BacaStringPerKarakter(char *String, int Panjang){
    int Indeks = 0;

    start();
    while (cc == BLANK || cc == NEW_LINE){
        adv();
    }
    while (cc != BLANK && cc != NEW_LINE && Indeks < Panjang - 1){
        String[Indeks] = cc;
        Indeks++;
        adv();
    }
    String[Indeks] = '\0';
    
}

void Work(){
    char InputBuffer[100];

    TampilkanDaftarPekerjaan();
    printf("Masukkan pekerjaan yang dipilih: ");
    BacaStringPerKarakter(InputBuffer, sizeof(InputBuffer));    
    printf("\n");

    // misal program selesai pake "Selesai"
    while (!BandingHuruf(InputBuffer, "Selesai")){
        if (BandingHuruf(InputBuffer, "Evil Lab Assistant")){
            printf("Anda bekerja sebagai Evil Lab Assistant, Menunggu gaji turun :3...\n");
            Jeda(14);
            printf("Horee gaji sudah turun! 100 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (BandingHuruf(InputBuffer, "OWCA Hiring Manager")){
            printf("Anda bekerja sebagai OWCA Hiring Manager, Menunggu gaji turun :3...\n");
            Jeda(21);
            printf("Horee gaji sudah turun! 4200 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (BandingHuruf(InputBuffer, "Cikapundunginator Caretaker")){
            printf("Anda bekerja sebagai Cikapundunginator Caretaker, Menunggu gaji turun :3...\n");
            Jeda(30);
            printf("Horee gaji sudah turun! 7000 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (BandingHuruf(InputBuffer, "Mewing Specialist")){
            printf("Anda bekerja sebagai Mewing Specialist, Menunggu gaji turun :3...\n");
            Jeda(22);
            printf("Horee gaji sudah turun! 10000 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (BandingHuruf(InputBuffer, "Inator Connoisseur")){
            printf("Anda bekerja sebagai Inator Connoisseur, Menunggu gaji turun :3...\n");
            Jeda(15);
            printf("Horee gaji sudah turun! 997 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else {
            printf("Tolong input sesuai yang ada di daftar, gausah ngadi-ngadi soalnya emang itu doang :(\n");
        }
        TampilkanDaftarPekerjaan();
        printf("Masukkan pekerjaan yang dipilih: ");
        BacaStringPerKarakter(InputBuffer, sizeof(InputBuffer));    
        printf("\n");
    }

    printf("Sampai Jumpa :D\n");

}

// int main(){
//     Work();
//     return 0;
// }