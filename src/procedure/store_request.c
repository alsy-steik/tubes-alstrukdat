#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../adt/Queue/Queue.h"
#include "../adt/ArrayDin/ArrayDin.h"
#include "../adt/Barang/barang.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/MesinKata/MesinKata.h"

/*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


void StoreRequest(ArrayDin arr, Queue* requestQueue){
    printf("Masukkan nama item:\n");
    
    startKataMajemuk(NULL);
    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
    while (!is_same_string(currentKata.buffer, "Selesai")){
        boolean Mark_Antrean;
        printf("%d", isEmpty(*requestQueue));
        if (isEmpty(*requestQueue)){
            enqueue(requestQueue, currentKata.buffer);
        }

        /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
        
        else{
            Mark_Antrean = contains(*requestQueue, currentKata.buffer);
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

        else if (Mark_Antrean == true){
                printf("Barang dengan nama yang sama sudah ada di antrean!\n");
        }  

        else{
            enqueue(requestQueue, currentKata.buffer);
            printf("Barang berhasil ditambahkan di antrean\n");
        }

        for (int z = 0; z < currentKata.length; z++){
            currentKata.buffer[z] = '\0';
        }
        currentKata.length = 0;

        printf("Masukkan nama item:\n");

        startKataMajemuk(NULL);
    }
}
