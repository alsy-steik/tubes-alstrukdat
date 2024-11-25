void Quit()
{
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    while (true)
    {
        start(NULL);
        adv();

        if (cc == 'Y' || cc == 'y')
        {
            printf("Nama save file: ");
            startKata(NULL);
            while (endKata)
            {
                puts("Please specify filename!");
                printf("Nama save file: ");
                startKata(NULL);
            }

            saveFile(currentKata.buffer);

            cc = 'n';
        }

        else if (cc = 'N' || cc == 'n')
        {
            puts("Kamu keluar dari PURRMART.");
            puts("Dadah ^_^/");
        }
    }
}
