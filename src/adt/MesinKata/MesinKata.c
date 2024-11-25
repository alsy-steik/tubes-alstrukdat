#include "MesinKata.h"


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

    currentKata.buffer[i] = '\0';
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

int Uppercased_Char(int num){
    if (num >= 'a' && num <= 'z'){
        return (num - 32);
    }

    return num;
}

boolean is_same_string(const char str1[], const char str2[]){
    int i = 0;
        
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (Uppercased_Char(str1[i]) != Uppercased_Char(str2[i])){
            return false;
        }
        i++;
    }
    // return (str1[i] == '\0' && str2[i] == '\0');
    return (true);
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

boolean Load(const char *filename, ArrayStat *user, ArrayDin *barang)
{
    FILE *file;
    

    file = fopen(filename, "r");
    if (file)
    {
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.");

        /**
         * TODO: Load data into `user` and `barang`
         */
        fclose(file);
        return true;
    }
    
    return false;
}

void PrintKata(Kata kata){
    for (int i = 0; i<kata.length; i++){
        printf("%c", kata.buffer[i]);
    }
}

// int main() {
//     startKata(NULL);
    // while(!endKata) {
    //     for (int i = 0; i < currentKata.length; i++)
    //     {
    //         // puts("a");
    //         printf("%c", currentKata.buffer[i]);
    //         // puts("a");
    //     }
    //     printf("\n");
    //     advKata();
    // }
// }
