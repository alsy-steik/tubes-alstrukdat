#include <stdio.h>
#include "../adt/MesinKata/MesinKata.h"

void W0RDL3();
void TebakAngka();

void WorkChallenge()
{
    puts("Daftar challenge yang tersedia:");
    puts("1. Tebak angka (biaya main = 200)");
    puts("2. WORDL399 (biaya main = 500)");
        putchar('\n');
    printf("Masukkan challenge yang hendak dimainkan: ");

    int num = getNum();

    if (num == 1)
    {
        TebakAngka();
    }
    else if (num == 2)
    {
        W0RDL3();
    }else{
        
    }
}
