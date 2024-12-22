#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "doublyLinkedList.h"
#include "MesinKarakter.h"
#include "MesinKata.h"

int NbElmt_list(DoublyLinkedListNode* head){
    int count = 0;
    while (head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

int LinkedListSearch_Index(DoublyLinkedList list, const char* string){
    int index = 1;
    while (list.head != NULL){
        if (is_same_string(list.head->data, string)){
            break;
        }
        index++;
        list.head = list.head->next;
    }
    return index;
}

boolean IsEmpty(DoublyLinkedList head){
    return (head == NULL);
}

void Wishlist_remove_i(DoublyLinkedList* list, int i){
    i--;
    /*Menyesuaikan index dari input (1 sampai n) ke list(0 sampai n-1)*/
    int NbElmt = list->len;
    if (IsEmpty(*list)){
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
    }

    else if (i >= 0 && i < NbElmt){
        if (i == 0){
            LinkedListDeleteBeginning(list);
            /*Bila indeks - 1 == 0 (menandakan di elmt awal), akan delete Beginning*/
        }
        else if (i == NbElmt){
            LinkedListDeleteEnd(list);
            /*Bila indeks - 1 == NbElmt(menandakan di elmt akhir), akan delete End*/
        }
        else{
            LinkedListDeleteElem(list, i);
            /*Bila indeks bukan di ujung, akan delete elmt*/
        }
        
        if ((NbElmt - 1) == list->len){
            printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", i+1);
            /*Memvalidasi apakah penghapusan barang sukses*/
        }
        else{
            printf("Penghapusan barang posisi ke-%d dari wishlist GAGAL!, silahkan coba kembali\n", i+1);
        }
    }
    else{
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!", i+1);
    }
}

void Wishlist_remove(DoublyLinkedList* list){
    printf("Masukkan nama barang yang akan dihapus: ");
    startKataMajemuk(NULL);
    /*Meminta input user untuk barang yang ingin dihapus*/


    int NbElmt = list->len;
    /*Untuk mendapatkan banyaknya element sebagai ref. max index*/

    int index = LinkedListSearch_Index(*list, currentKata.buffer);
    /*Mendapatkan index dari barang tersebut, bila tidak ada akan melebihi NbElmt*/

    if (index > 0 && index <= NbElmt){
        Wishlist_remove_i(list, index);
        printf("%s berhasil dihapus dari wishlist!\n", currentKata.buffer);
        /*Validasi bahwa index in range of 1 sampai NbElmt*/
    }
    else{
        printf("Penghapusan barang wishlist gagal dilakukan, %s tidak ada di wishlist!\n", currentKata.buffer);
    }
}


// int main() {
//     DoublyLinkedListNode* wishlist = NULL;

//     LinkedListInsertEnd(&wishlist, "Laptop");
//     LinkedListInsertEnd(&wishlist, "Smartphone");
//     LinkedListInsertEnd(&wishlist, "Headphone");
//     LinkedListInsertEnd(&wishlist, "Monitor");
//     LinkedListInsertEnd(&wishlist, "Keyboard");
//     LinkedListInsertEnd(&wishlist, "Mouse");

//     printf("\nCurrent wishlist:\n");
//     printDoublyLinkedListNode(wishlist);

//     Wishlist_remove(&wishlist);


//     printf("\nCurrent wishlist:\n");
//     printDoublyLinkedListNode(wishlist);

//     return 0;
// }



// gcc -o wishlist_remove_together wishlist_remove_together.c doublyLinkedList.c MesinKarakter.c MesinKata.c
