#include "MesinKata.h"


boolean endKata;
Kata currentKata;

void ignoreBlank() {
    while(cc == BLANK) {
        // puts("bjirnigga");
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
    if(cc == EOF) {
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
    while((cc != EOL) && (cc != BLANK)) {
        currentKata.buffer[i] = cc;
        adv();
        ++i;
    }

    // reset the current character, so we could read from the next line
    if(cc == EOL) cc = BLANK;

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

boolean saveFile(const char *filename, ArrayStat *user, ArrayDin *barang)
{
    int i = 0;
    while(filename[i] != '\0') {
        if (filename[i] == '\\' || filename[i] == '/') return false;
        ++i;
    }

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
    return true;
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
        printf("%s\n", kata.buffer[i]);
    }
}

int main() {

    ArrayDin barang;
    MakeEmptyArrayDin(&barang);

    startKata("sample.txt");
    int n = atoi(currentKata.buffer);

    printf("%d\n", n);
    while(n--) {
        advKata();
        int quantity = atoi(currentKata.buffer);
        advKata();
        printf("%d %s\n", quantity, currentKata.buffer);
    }

    advKata();
    atoi(currentKata)
    // startKata(NULL);
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
}
