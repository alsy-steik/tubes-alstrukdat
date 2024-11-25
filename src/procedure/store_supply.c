#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../adt/Queue/Queue.h"
#include "../adt/ArrayDin/ArrayDin.h"
#include "../adt/Barang/barang.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/MesinKata/MesinKata.h"

/*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

void StoreSupply(ArrayDin arr, Queue* requestQueue){
    
    if (!isEmpty(*requestQueue)){
        char* queue_front = front(*requestQueue);
        
        printf("Apakah kamu ingin menambahkan barang %s: ", queue_front);
        
        startKata(NULL);

        /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

        if (is_same_string(currentKata.buffer, "Terima")){
            dequeue(requestQueue);
            int inputHarga = 0;

            while (inputHarga <= 0){
                printf("Harga barang:");
                inputHarga = getNum();

                if (inputHarga <= 0){
                    printf("Harga barang tidak valid, silahkan mengulang kembali!\n");
                }
            }      

            /*------------------------------------------------------DIVIDER--------------------------------------------------------*/

            Barang BarangBaru = createBarang(queue_front, inputHarga);
            ArrayDinInsertEnd(&arr, BarangBaru); 
        }

            /*------------------------------------------------------DIVIDER--------------------------------------------------------*/

        else if (is_same_string(currentKata.buffer, "Tunda")){
            enqueue(requestQueue, queue_front);
            printf("%s dikembalikan ke antrean", queue_front);
            dequeue(requestQueue);
        }

        else if (is_same_string(currentKata.buffer, "Tolak")){
            dequeue(requestQueue);
        }
    }
}
