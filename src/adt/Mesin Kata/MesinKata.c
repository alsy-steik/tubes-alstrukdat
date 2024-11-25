#include "MesinKata.h"
#include "MesinKarakter.h"
#include "ArrayDin.h"
#include "ArrayStat.h"
#include "Barang.h"
#include "User.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool endKata;
Kata currentKata;

void ignoreBlank() {
    while(cc == BLANK) {
        adv();
    }
}

void startKata(const char* path) {
    start(path);
    ignoreBlank();
    if(cc == MARK) {
        endKata = true;
    } else {
        endKata = false;
        salinKata();
    }
}

void advKata() {
    ignoreBlank();
    if(cc == MARK) {
        endKata = true;
    } else {
        endKata = false;
        salinKata();
    }
}

void salinKata() {
    int i = 0;
    while((cc != MARK) && (cc != BLANK)) {
        currentKata.buffer[i] = cc;
        adv();
        ++i;
    }

    currentKata.length = i;
}

int getNum() {
    startKata(NULL);
    return atoi(currentKata.buffer);
}

void saveFile(const char *filename, ArrayStat *user, ArrayDin *barang)
{
    FILE *fptr = fopen(filename, "w");

    fprintf(fptr, "%d\n", barang->len);
    for (int i = 0; i < barang->len; ++i)
    {
        Barang bjir = (barang->arr)[i];
        fprintf(fptr, "%d %s\n", bjir.price, bjir.name);
    }

    fprintf(fptr, "%d\n", user->len);
    for (int i = 0; i < user->len; ++i)
    {
        User bjir = (user->arr)[i];
        fprintf(fptr, "%d %s %s\n", bjir.money, bjir.name, bjir.password);
    }

    fclose(fptr);
}

// int main() {
//     startKata(NULL);
//     while(!endKata) {
//         for (int i = 0; i < currentKata.length; i++)
//         {
//             // puts("a");
//             printf("%c", currentKata.buffer[i]);
//             // puts("a");
//         }
//         printf("\n");
//         advKata();
//     }
// }
