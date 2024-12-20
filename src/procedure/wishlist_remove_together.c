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

int LinkedListSearch_Index(DoublyLinkedListNode* head, const char* string){
    int index = 1;
    while (head != NULL){
        if (is_same_string(head->data, string)){
            break;
        }
        index++;
        head = head->next;
    }
    return index;
}

boolean IsEmpty(DoublyLinkedListNode* head){
    return (head == NULL);
}

void Wishlist_remove_i(DoublyLinkedListNode** head, int i){
    i--;
    int NbElmt = NbElmt_list(*head);
    if (i >= 0 && i < NbElmt){
        if (i == 1){
            LinkedListDeleteBeginning(head);
        }
        else if (i == NbElmt){
            LinkedListDeleteEnd(head);
        }
        else{
            LinkedListDeleteElem(head, i);
        }
        printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", i);
    }
    else{
        if (IsEmpty(*head)){
            printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        }
        else{
            printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!", i);
        }
    }
}

void Wishlist_remove(DoublyLinkedListNode** head){
    printf("Masukkan nama barang yang akan dihapus: ");
    startKataMajemuk(NULL);

    int NbElmt = NbElmt_list(*head);
    int index = LinkedListSearch_Index(*head, currentKata.buffer);

    if (index > 0 && index <= NbElmt){
        Wishlist_remove_i(head, index);
        printf("%s berhasil dihapus dari wishlist!\n", currentKata.buffer);
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