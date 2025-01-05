#include "../boolean.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/MesinKata/MesinKata.h"

void Quit(ArrayStat* user, ArrayDin* barang)
{
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    while (true)
    {
        start(NULL);
        adv();

        if (cc == 'Y' || cc == 'y')
        {
            printf("Nama save file: ");
            adv();
            startKata(NULL);
            // printf("%s|", currentKata.buffer);
            while (endKata)
            {
                puts("Please specify filename!");
                printf("Nama save file: ");
                startKata(NULL);
            }

            saveFile(currentKata.buffer, user, barang);

            puts("Kamu keluar dari PURRMART.");
            puts("Dadah ^_^/");
            return;
        }

        else if (cc = 'N' || cc == 'n')
        {
            puts("Kamu keluar dari PURRMART.");
            puts("Dadah ^_^/");
            return;
        }
    }
}
