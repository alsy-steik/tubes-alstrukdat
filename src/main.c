#include "adt/MesinKata/MesinKata.h"
#include "boolean.h"
#include "adt/Queue/Queue.h"
#include "adt/ArrayDin/ArrayDin.h"
#include "adt/ArrayStat/ArrayStat.h"

boolean START(ArrayStat* pengguna, ArrayDin* barang);
void help(int menu);
boolean Login();
boolean Register();
void Logout();
void Work();
void TebakAngka();
void W0RDL3();
void WorkChallenge();
void store_list(ArrayDin arr);
void store_remove(ArrayDin *arr);
void StoreRequest(ArrayDin arr, Queue requestQueue);
void StoreSupply(ArrayDin arr, Queue requestQueue);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

    int main() {

    int pos = 0;
    puts("============SELAMAT DATANG DI PURRMART!============");
    puts("Anda dapat memulai dengan memasukan command-command berikut : ");
    puts("1. START : membaca file konfigurasi default.");
    puts("2. LOAD <filename> : membaca <filename> yang merupakan file save.");
    puts("3. HELP : menampilkan daftar command yang mungkin untuk dieksekusi dengan deskripsinya.");

    boolean valid = false;

    ArrayStat user;
    ArrayDin barang;

    User session = NULL;

    while (!valid)
    {
        printf(">> ");
        startKata(NULL);
        if(is_same_string(currentKata.buffer, "START")) {
            valid = START(user, barang);
            if(valid) {
                puts("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.");
            } else
                puts("Terjadi kesalahan. Coba lagi!");
        } else if(is_same_string(currentKata.buffer, "LOAD")) {
            advKata();
            if(endKata) {
                puts("Invalid usage : Argumen <filename> tidak ditemukan.");
                continue;
            }

            char path[100] = "save/";
            strcat(path, currentKata.buffer);   

            valid = Load(path, &user, &barang);
            if(!valid) {
                printf("File '%s' not found.\n", currentKata.buffer);
            }
        } else if(is_same_string(currentKata.buffer, "HELP")) {
            help(1);
        } else {
            printf("%s : command not found");
        }
    }

    valid = false;
    while(!valid) {
        printf(">> ");
        startKata(NULL);

        if(is_same_string(currentKata.buffer, "LOGIN")) {
            valid = Login();
        } else if(is_same_string(currentKata.buffer, "REGISTER")) {
            valid = Register();
        } else if{
            help(pos);
        } else {
            printf("%s : command not found");
        }
    }

    pos = 2;
    valid = false;

    while(!valid) {
        printf(">> ");
        startKata(NULL);

        if(is_same_string(currentKata.buffer, "LOGOUT")) {
            Logout();
        }

        else if(is_same_string(currentKata.buffer, "WORK")) {
            advKata();
            if(!endKata) {
                if(is_same_string(currentKata.buffer, "CHALLENGE")) {
                    WorkChallenge();
                } else {
                    printf("???: NOT FOUND");
                }
            }
            Work();
        }

        else if(is_same_string(currentKata.buffer, "STORE")) {
            advKata();
            if(!endKata) {
                if(is_same_string(currentKata.buffer, "LIST")) {
                    store_list(barang);
                }
                if(is_same_string(currentKata.buffer, "REQUEST")) {
                    StoreRequest(barang, )
                }
                if(is_same_string(currentKata.buffer, "SUPPLY")) {

                }
                if(is_same_string(currentKata.buffer, "REMOVE")) {

                }
            }
        }
    }

}

void WorkChallenge() {
    puts("Daftar challenge yang tersedia:");
    puts("1. Tebak angka (biaya main = 200)");
    puts("2. WORDL399 (biaya main = 500)")
    putchar('\n');
    printf("Masukkan challenge yang hendak dimainkan: ");

    int num = getNum();
    
    if(num == 1) { 
        TebakAngka();
    } else if(num == 2) {
        W0RDL3();
    }
}
