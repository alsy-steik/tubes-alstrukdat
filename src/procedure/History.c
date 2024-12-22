#include <stdio.h>
#include "../adt/Stack/stack.h"
#include "../adt/MesinKata/MesinKata.h"

Stack history;

void showHistory(){
    int banyak;
    int Counter = 0;
    Stack temporary;
    StackInitEmpty(&temporary);

    printf("Berapa Transaksi yang Ingin Ditampilkan?\n");
    startKata(NULL);
    banyak = getNum();

    printf("========== RIWAYAT TRANSAKSI ANDA ==========\n");
     if (isEmpty(history)) {
        printf("Anda belum beli apapun -w-\n");
        return;
    }

    while (!isEmpty(history) && Counter < banyak){
        StackElement sekarang = top(history);
        printf("%d. %s %d\n", Counter + 1, sekarang.nama_barang, sekarang.harga_total);

        push(&temporary, sekarang);
        pop(&history);
        Counter++;
    }
    printf("========== RIWAYAT TRANSAKSI ANDA ==========\n");

    while (!isEmpty(temporary)){
        push(&history, top(temporary));
        pop(&temporary);
    }
    return;
}


// DEBUG AAKJSHKAD
// int main(){
//     StackInitEmpty(&history);

//     pushNT(&history, "Buku", 123);
//     pushNT(&history, "Albarda", 456);
//     pushNT(&history, "Dorito", 789);
//     pushNT(&history, "Pensil", 111);

//     printf("Mulai/Selesai\n");
//     startKata(NULL);
//     while (!is_same_string(currentKata.buffer, "Selesai")){
//         if (is_same_string(currentKata.buffer, "Mulai")){
//             showHistory();
//         }
//         else {
//             printf("yang bener\n");
//         }
//         printf("Mulai/Selesai\n");
//         startKata(NULL);
//     }
//     printf("Done\n");
// }