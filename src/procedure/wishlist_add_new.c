#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "doublyLinkedList.h"
#include "MesinKarakter.h"
#include "MesinKata.h"
#include "Barang.h"
#include "ArrayDin.h"

boolean LinkedListSearch(DoublyLinkedListNode* head, const char* string){
    while (head != NULL){
        if (is_same_string(head->data, string)){
            return true;
        }
        head = head->next;
    }
    return false;
}

boolean LinkedListEnd_ISS(DoublyLinkedListNode* head, const char* string){
    while (head->next != NULL){
        head = head->next;
    }
    return (is_same_string(head->data, string));
}


void WishlistAdd(DoublyLinkedListNode** head, ArrayDin arr){
    printf("Masukkan nama barang: ");
    startKataMajemuk(NULL); 
    /*Meminta input user*/

    boolean P = LinkedListSearch(*head, currentKata.buffer);
    if (P == true){
        printf("%s sudah ada di wishlist!\n");
    }
    /*Validasi apakah barang sudah ada pada wishlist*/


    else{
        int MARK_Store = 0;
        int N = getArrayDinLength(arr);
        for (int i = 0; i < N; i++){
            Barang store = getArrayDinElmt(arr, i);

            if (is_same_string(currentKata.buffer, store.name)){
                MARK_Store++;
            }
        }
        /*Validasi apakah ada barang tersebut di toko*/
        

        if (MARK_Store == 0){
            printf("Tidak ada barang dengan nama %s\n", currentKata.buffer);
        }
        else{
            LinkedListInsertEnd(head, currentKata.buffer);
            if (LinkedListEnd_ISS(*head, currentKata.buffer)){
                printf("Berhasil menambahkan %s ke wishlist!\n", currentKata.buffer);
            }
            /*Konfirmasi dengan cara mengecek akhirannya*/
            else{
                printf("Gagal menambahkan %s ke wishlist!\n", currentKata.buffer);
            }
        }
    }
}

// void store_list(ArrayDin arr)
// {
//     int N = getArrayDinLength(arr);
//     printf("head barang yang ada di toko:\n");
//     if (N > 0)
//     {
//         for (int i = 0; i < N; i++)
//         {
//             Barang storelist = getArrayDinElmt(arr, i);
//             printf("- %s - Harga: %d\n", storelist.name, storelist.price);
//         }
//     }

//     else
//     {
//         printf("TOKO KOSONG\n");
//     }
// }

// int main() {
//     DoublyLinkedListNode* wishlist = NULL;

//     ArrayDin inventory;
//     MakeEmptyArrayDin(&inventory);

//     Barang item1 = createBarang("Laptop", 15000000);
//     Barang item2 = createBarang("Smartphone", 8000000);
//     Barang item3 = createBarang("Headphones", 250000);

//     ArrayDinInsertEnd(&inventory, item1);
//     ArrayDinInsertEnd(&inventory, item2);
//     ArrayDinInsertEnd(&inventory, item3);

//     store_list(inventory);

//     printf("\nCurrent wishlist:\n");
//     printDoublyLinkedListNode(wishlist);

//     printf("\n=== Add items to wishlist ===\n");
//     WishlistAdd(&wishlist, inventory);
//     WishlistAdd(&wishlist, inventory);
//     WishlistAdd(&wishlist, inventory);
//     WishlistAdd(&wishlist, inventory);

//     printf("\nCurrent wishlist:\n");
//     printDoublyLinkedListNode(wishlist);

//     return 0;
// }


// gcc -o wishlist_add_new wishlist_add_new.c doublyLinkedList.c MesinKarakter.c MesinKata.c Barang.c ArrayDin.c