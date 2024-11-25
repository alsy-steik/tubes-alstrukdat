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

void Work(){
    char InputBuffer[100];

    TampilkanDaftarPekerjaan();
    printf("Masukkan pekerjaan yang dipilih: ");
    startKataMajemuk(InputBuffer);
    salinKataMajemuk();
    
    printf("\n");
    // is_same_string(InputBuffer, "Inator Connoisseur");
    // misal program selesai pake "Selesai"
    while (!is_same_string(currentKata.buffer, "Selesai");){
        if (is_same_string(currentKata.buffer, "Evil Lab Assistant")){
            printf("Anda bekerja sebagai Evil Lab Assistant, Menunggu gaji turun :3...\n");
            Jeda(14);
            printf("Horee gaji sudah turun! 100 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (is_same_string(currentKata.buffer, "OWCA Hiring Manager");){
            printf("Anda bekerja sebagai OWCA Hiring Manager, Menunggu gaji turun :3...\n");
            Jeda(21);
            printf("Horee gaji sudah turun! 4200 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (is_same_string(currentKata.buffer, "Cikapundunginator Caretaker")){
            printf("Anda bekerja sebagai Cikapundunginator Caretaker, Menunggu gaji turun :3...\n");
            Jeda(30);
            printf("Horee gaji sudah turun! 7000 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (is_same_string(currentKata.buffer, "Mewing Specialist")){
            printf("Anda bekerja sebagai Mewing Specialist, Menunggu gaji turun :3...\n");
            Jeda(22);
            printf("Horee gaji sudah turun! 10000 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (is_same_string(currentKata.buffer, "Inator Connoisseur")){
            printf("Anda bekerja sebagai Inator Connoisseur, Menunggu gaji turun :3...\n");
            Jeda(15);
            printf("Horee gaji sudah turun! 997 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else {
            printf("Tolong input sesuai yang ada di daftar, gausah ngadi-ngadi soalnya emang itu doang :(\n");
        }
        TampilkanDaftarPekerjaan();
        printf("Masukkan pekerjaan yang dipilih: ");
        startKataMajemuk(InputBuffer);
        salinKataMajemuk();   
        printf("\n");
    }

    printf("Sampai Jumpa :D\n");

}

// int main(){
//     Work();
//     return 0;
// }
