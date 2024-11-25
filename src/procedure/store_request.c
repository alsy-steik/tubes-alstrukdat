#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "Queue.h"
#include "ArrayDin.h"
#include "Barang.h"
#include "MesinKata.h"

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
    return (str1[i] == '\0' && str2[i] == '\0');
}
/*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


void StoreRequest(ArrayDin arr, Queue requestQueue){
    printf("Masukkan nama item:\n");

    startKata(NULL);
    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

    if (isEmpty(requestQueue)){
        enqueue(&requestQueue, &currentKata.buffer);
    }

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

    else{
        Queue temp;
        initQueue(&temp);
        char* val;

        int Mark_Antrean = 0, Mark_Supply = 0;
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
        
        /*Mengecek apakah nama tersebut ada pada queue*/

        /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
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
            enqueue(&requestQueue, &currentKata.buffer);
            printf("Barang berhasil ditambahkan di antrean\n");
        }
    }
}
