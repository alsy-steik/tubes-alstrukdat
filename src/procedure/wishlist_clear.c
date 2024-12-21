#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "doublyLinkedList.h"

void Wishlist_clear(DoublyLinkedListNode **head){
    *head = NULL;
    /*Membuat linked list menjadi list baru yang empty*/
    if(*head == NULL){
        printf("Wishlist kamu berhasil dihapus!\n");
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

//     Wishlist_clear(&wishlist);

//     printf("\nCurrent wishlist:\n");
//     printDoublyLinkedListNode(wishlist);

//     return 0;
// }

// gcc -o wishlist_clear wishlist_clear.c doublyLinkedList.c
