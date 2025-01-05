#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// #include <string.h>

int IndeksUser;
ArrayStat user;

int main() {

    int pos = 0;
    puts("============SELAMAT DATANG DI PURRMART!============");
    puts("Anda dapat memulai dengan memasukan command-command berikut : ");
    puts("1. START : membaca file konfigurasi default.");
    puts("2. LOAD <filename> : membaca <filename> yang merupakan file save.");
    puts("3. HELP : menampilkan daftar command yang mungkin untuk dieksekusi dengan deskripsinya.");

    boolean valid = false;

    createEmpty(&user);

    ArrayDin barang;
    MakeEmptyArrayDin(&barang);

    Queue request;
    initQueue(&request);

    while (!valid)
    {
        printf(">> ");
        startKata(NULL);
        if(is_same_string(currentKata.buffer, "START")) {
            valid = START(&user, &barang);
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

            valid = Load(currentKata.buffer, &user, &barang);
            if(!valid) {
                printf("File '%s' not found.\n", currentKata.buffer);
            }
        } else if(is_same_string(currentKata.buffer, "HELP")) {
            help(1);
        } else {
            printf("%s : command not found\n");
        }
    }

    // DEBUG
    // for(int i = 0; i < user.len; ++i) {
    //     printf("%s %s %d\n", user.arr[i].name, user.arr[i].password, user.arr[i].money);
    // }

    // StackNode* bjir = user.arr[0].riwayat_pembelian.top;
    // printf("%d\n", user.arr[0].riwayat_pembelian.len);
    // while(bjir != NULL) {
    //     printf("%s %d\n", bjir->data.nama_barang, bjir->data.harga_total);
    //     bjir = bjir->link;
    // }

notLoggedIn:
    IndeksUser = -1;
    valid = false;
    while(!valid) {
        printf(">> ");
        startKata(NULL);

        if(is_same_string(currentKata.buffer, "LOGIN")) {
            valid = Login();
        } else if(is_same_string(currentKata.buffer, "REGISTER")) {
            Register();
        } else if (is_same_string(currentKata.buffer, "HELP")) {
            help(2);
        } else {
            printf("%s : command not found\n", currentKata.buffer);
        }
    }

    pos = 3;
    valid = false;

    while(!valid) {
        printf(">> ");
        startKata(NULL);

        if(is_same_string(currentKata.buffer, "LOGOUT")) {
            Logout();
            goto notLoggedIn;
        }

        else if(is_same_string(currentKata.buffer, "WORK")) {
            advKata();
            if(!endKata) {
                if(is_same_string(currentKata.buffer, "CHALLENGE")) {
                    WorkChallenge();
                } else {
                    printf("???: NOT FOUND");
                }
            } else {
                Work();
            }
        }

        else if(is_same_string(currentKata.buffer, "STORE")) {
            advKata();
            if(!endKata) {
                if(is_same_string(currentKata.buffer, "LIST")) {
                    store_list(barang);
                }
                else if(is_same_string(currentKata.buffer, "REQUEST")) {
                    StoreRequest(barang, &request);
                }
                else if(is_same_string(currentKata.buffer, "SUPPLY")) {
                    StoreSupply(&barang, &request);
                }
                else if(is_same_string(currentKata.buffer, "REMOVE")) {
                    store_remove(&barang);
                } else {
                    printf("STORE %s : command not found\n", currentKata.buffer);
                }
            } else {
                printf("%s : command not found\n", currentKata.buffer);
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
            Quit(&user, &barang);
            return 0;
        } else if(is_same_string(currentKata.buffer, "HELP")){
            help(3);
        } else if(is_same_string(currentKata.buffer, "WISHLIST")){
            advKata();
            if(!endKata) {
                if(is_same_string(currentKata.buffer, "ADD")) {
                    WishlistAdd(&(user.arr[IndeksUser].wishlist), barang);
                } else if(is_same_string(currentKata.buffer, "SWAP")) {
                    
                    advKata();
                    int num1;
                    if(endKata) {
                        puts("Missing arguments.");
                    } else {
                        num1 = atoi(currentKata.buffer);
                    }

                    advKata();
                    int num2;
                    if(endKata) {
                        puts("Missing an argument.");
                    } else {
                        num2 = atoi(currentKata.buffer);
                    }

                    Wishlist_swap(&(user.arr[IndeksUser].wishlist), num1, num2);
                } else if(is_same_string(currentKata.buffer, "REMOVE")) {
                    advKata();
                    if(endKata) {
                        Wishlist_remove(&(user.arr[IndeksUser].wishlist));
                    } else {
                        Wishlist_remove_i(&(user.arr[IndeksUser].wishlist), atoi(currentKata.buffer));
                    }
                } else if(is_same_string(currentKata.buffer, "CLEAR")) {
                    Wishlist_clear(&(user.arr[IndeksUser].wishlist));
                } else if(is_same_string(currentKata.buffer, "SHOW")) {
                    Wishlist_show(user.arr[IndeksUser].wishlist);
                }
            } else {
                puts("WISHLIST : command not found");
            }
        } else if(is_same_string(currentKata.buffer, "PROFILE")) {
            showProfile();
        } else if(is_same_string(currentKata.buffer, "CART")) {
            advKata();
            if(!endKata) {
                if (is_same_string(currentKata.buffer, "ADD")) {
                    advKataMajemuk();
                    int i = 0;
                    int last_space = -1;
                    puts(currentKata.buffer);
                    while(currentKata.buffer[i] != 0) {
                        if(currentKata.buffer[i] == ' ') last_space = i;
                        ++i;
                    }
                    
                    if(last_space == -1) {
                        puts("Missing Arguments");
                    } else {
                        int quantity = atoi(currentKata.buffer + last_space + 1);
                        if(quantity == 0) {
                            puts("Invalid quantity");
                        } else {
                            currentKata.buffer[last_space] ='\0';
                            cartAdd(
                                &(user.arr[IndeksUser].keranjang),
                                &(barang),
                                currentKata.buffer,
                                quantity
                            );
                        }
                    }


                }
                else if (is_same_string(currentKata.buffer, "SHOW"))
                {
                    cartShow(&(user.arr[IndeksUser].keranjang), &barang);
                } else if(is_same_string(currentKata.buffer, "PAY")) {
                    showCart(barang);
                } else if(is_same_string(currentKata.buffer, "REMOVE")) {
                    advKataMajemuk();
                    int i = 0;
                    int last_space = -1;
                    puts(currentKata.buffer);
                    while (currentKata.buffer[i] != 0)
                    {
                        if (currentKata.buffer[i] == ' ')
                            last_space = i;
                        ++i;
                    }

                    if (last_space == -1)
                    {
                        puts("Missing Arguments");
                    }
                    else
                    {
                        int quantity = atoi(currentKata.buffer + last_space + 1);
                        if (quantity == 0)
                        {
                            puts("Invalid quantity");
                        }
                        else
                        {
                            currentKata.buffer[last_space] = '\0';
                            cartRemove(
                                &(user.arr[IndeksUser].keranjang),
                                currentKata.buffer,
                                quantity
                            );
                        }
                    }
                }
            }
        } else if(is_same_string(currentKata.buffer, "HISTORY")) {
            advKata();
            if(endKata) {
                puts("Missing an argument. Try again.");
            } else {
                showHistory(user.arr[IndeksUser].riwayat_pembelian, atoi(currentKata.buffer));
            }
        }
        else {
            printf("%s : command not found\n", currentKata.buffer);
        }
    }
}
