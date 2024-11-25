#include "adt/MesinKata/MesinKata.h"
#include "boolean.h"
#include "adt/Queue/Queue.h"
#include "adt/ArrayDin/ArrayDin.h"
#include "adt/ArrayStat/ArrayStat.h"

void help(int menu);

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

    while (!valid)
    {
        printf(">> ");
        startKata(NULL);
        if(is_same_string(currentKata.buffer, "START")) {
            valid = true;
            Load("default.txt", &user, &barang);
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

}
