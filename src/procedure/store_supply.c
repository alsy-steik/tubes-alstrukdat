#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void StoreSupply(ArrayDin arr, Queue requestQueue){
    
    if (!isEmpty(requestQueue)){
        char* queue_front = front(requestQueue);
        
        printf("Apakah kamu ingin menambahkan barang %s: ", queue_front);
        
        startKata(NULL);

        /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

        if (is_same_string(currentKata.buffer, "Terima")){
            char* val = dequeue(&requestQueue);
            int inputHarga = 0;

            while (inputHarga <= 0){
                printf("Harga barang:");
                inputHarga = getNum();

                if (inputHarga <= 0){
                    printf("Harga barang tidak valid, silahkan mengulang kembali!\n");
                }
            }      

            /*------------------------------------------------------DIVIDER--------------------------------------------------------*/

            Barang BarangBaru = createBarang(val, inputHarga);
            ArrayDinInsertEnd(&arr, BarangBaru); 
        }

            /*------------------------------------------------------DIVIDER--------------------------------------------------------*/

        else if (is_same_string(currentKata.buffer, "Tunda")){
            char* val = dequeue(&requestQueue);
            enqueue(&requestQueue, val);
            printf("%s dikembalikan ke antrean", val);
        }

        else if (is_same_string(currentKata.buffer, "Tolak")){
            char* val = dequeue(&requestQueue);
        }
    }
}
