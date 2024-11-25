#include "function.h"

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
    createEmpty(&user);

    ArrayDin barang;
    MakeEmptyArrayDin(&barang);

    Queue request;
    initQueue(&request);

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
                    StoreRequest(barang, &request);
                }
                if(is_same_string(currentKata.buffer, "SUPPLY")) {
                    StoreSupply(barang, request);
                }
                if(is_same_string(currentKata.buffer, "REMOVE")) {
                    store_remove(&barang);
                } else {
                    printf("STORE %s : command not found", currentKata.buffer);
                }
            } else {
                printf("%s : command not found", currentKata.buffer);
            }
        }

        else if(is_same_string(currentKata.buffer, "LOGOUT")) {
            Logout();
        } else if(is_same_string(currentKata.buffer, "SAVE")) {
            advKata();
            if(!endKata) {
                saveFile(currentKata.buffer, &user, &barang);
            } else {
                puts("Please specify filename.");
            }
        } else if(is_same_string(currentKata.buffer, "QUIT")) {
            Quit();
        } else if(is_same_string(currentKata.buffer, "HELP")){
            help(3);
        } else {
            printf("%s : command not found", currentKata.buffer);
        }
    }
}
