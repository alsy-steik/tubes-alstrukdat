#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../adt/MesinKata/MesinKata.h"


void TebakAngka() {
    int randNum = rand() % 101;
    bool correct = false;
    int chance = 10;

    while(!correct && chance--) {
        printf("Tebak angka: ");
        int guess = getNum();

        if(guess < randNum)
            puts("Tebakanmu lebih kecil!\n");
        else if(guess > randNum)
            puts("Tebakanmu lebih besar!\n");
        
        correct = guess == randNum;
    }

    if(correct) {
        printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke akun anda.", chance * 50);
    } else {
        printf("gagal akskajksjakjskwjskwjksjw");
    }
}

// int main() {

//     TebakAngka();
//     return 0;
// }
