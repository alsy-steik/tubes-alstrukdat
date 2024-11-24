#include "MesinKata.h"


bool endKata;
Kata currentKata;

void ignoreBlank() {
    while(cc == BLANK) {
        // puts("a");
        adv();
    }
        // puts("n");
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

void startKataMajemuk(const char* path) {
    start(path);
    ignoreBlank();
    if(cc == MARK) {
        endKata = true;
    } else {
        endKata = false;
        salinKataMajemuk();
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

void salinKataMajemuk() {
    int i = 0;
    while((cc != MARK)) {
        currentKata.buffer[i] = cc;
        adv();
        ++i;
    }
    currentKata.length = i;
}

boolean BandingString(Kata kata, char *s){
    boolean found = true;
    int i = 0;
    while (i<kata.length && found){
        if (kata.buffer[i]!=s[i]){
            found = false;
        }
        else {
            i++;
        }
    } return found;
}

boolean BandingKata(Kata input1, Kata input2){
    if (input1.length != input2.length){
        return false;
    } else {
        boolean found = true;
        int i = 0;
        while (i<input1.length && found){
            if (input1.buffer[i]!=input2.buffer[i]){
                found = false;
            }
            else {
                i++;
            }
        } return found;
    }
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

void PrintKata(Kata kata){
    for (int i = 0; i<kata.length; i++){
        printf("%c", kata.buffer[i]);
    }
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
