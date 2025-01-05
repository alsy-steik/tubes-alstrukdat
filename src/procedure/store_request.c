#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../adt/Queue/Queue.h"
#include "../adt/ArrayDin/ArrayDin.h"
#include "../adt/Barang/barang.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../util/util.h"

/*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


void StoreRequest(ArrayDin arr, Queue* requestQueue){

    // for(int i = 0; i < requestQueue->arr.len; ++i) {
    //     printf("%d. %s\n", i + 1, requestQueue->arr.arr[i].name);
    // }
    printf("Masukkan nama item:\n");
    
    startKataMajemuk(NULL);
    /*Menerima input user terkait nama barang mau dimasukan*/
    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
    // if (isEmpty(*requestQueue)){
    //     enqueue(requestQueue, currentKata.buffer);
    // }
    /*Bila antrean kosong akan langsung dimasukan*/

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
    
    // else{
    // Mark_Antrean = contains(*requestQueue, currentKata.buffer);
    // }

    boolean Mark_Antrean = contains(*requestQueue, currentKata.buffer);
    if(Mark_Antrean) {
        printf("Barang dengan nama yang sama sudah ada di antrean!\n");
        return;
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
    }
    /*Mengecek apakah nama tersebut ada pada store*/

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


    if (Mark_Supply != 0){
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    }

    else{
        enqueue(requestQueue, currentKata.buffer);
        printf("Barang berhasil ditambahkan di antrean\n");
    }
}
