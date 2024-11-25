#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../adt/Queue/Queue.h"
#include "../adt/ArrayDin/ArrayDin.h"
#include "../adt/Barang/barang.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/MesinKata/MesinKata.h"

/*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


void StoreRequest(ArrayDin arr, Queue requestQueue){
    printf("Masukkan nama item:\n");

    startKataMajemuk(NULL);
    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
    int Mark_Antrean = 0;
    if (isEmpty(requestQueue)){
        enqueue(&requestQueue, currentKata.buffer);
    }

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
    
    else{
        Queue temp;
        initQueue(&temp);
        char* val;

        
        while (!isEmpty(requestQueue)){
            val = dequeue(&requestQueue);
            enqueue(&temp, val);
        }

        while (!isEmpty(temp)){
            val = dequeue(&temp);
            if (is_same_string(currentKata.buffer, val)){
                Mark_Antrean++;
            }
            enqueue(&requestQueue, val);
        }
    }
        
    /*Mengecek apakah nama tersebut ada pada queue*/

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
    int Mark_Supply = 0;
    int N = getArrayDinLength(arr);

    if (N > 0){
            for (int j = 0; j < N; j++){
                Barang storelist = getArrayDinElmt(arr,j);
                
                if (is_same_string(currentKata.buffer, storelist.name)){
                    Mark_Supply++;
                }
            }
        /*Meskipun hanya memakai item_name, tetap perlu diambil harga_item untuk memisahkannya*/  
    }
    

    /*Mengecek apakah nama tersebut ada pada store*/

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


    if (Mark_Supply != 0){
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    }

    else if (Mark_Antrean != 0){
        printf("Barang dengan nama yang sama sudah ada di antrean!\n");
    }

    else{
        enqueue(&requestQueue, currentKata.buffer);
        printf("Barang berhasil ditambahkan di antrean\n");
    }

    for (int z = 0; z < currentKata.length; z++){
        currentKata.buffer[z] = '\0';
    }
    currentKata.length = 0;

    printf("Masukkan nama item:\n");

    startKataMajemuk(NULL);
}
