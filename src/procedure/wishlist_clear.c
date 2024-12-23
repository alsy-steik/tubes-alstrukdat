#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../adt/LinkedList/doublyLinkedList.h"

void Wishlist_clear(DoublyLinkedList* list){
    createEmptyLinkedList(list);

    if(list->head == NULL){
        printf("Wishlist kamu berhasil dihapus!\n");
    }
}


// int main() {
//     DoublyLinkedList wishlist;
//     createEmptyLinkedList(&wishlist);

//     LinkedListInsertEnd(&wishlist, "Laptop");
//     LinkedListInsertEnd(&wishlist, "Smartphone");
//     LinkedListInsertEnd(&wishlist, "Headphone");
//     LinkedListInsertEnd(&wishlist, "Monitor");
//     LinkedListInsertEnd(&wishlist, "Keyboard");
//     LinkedListInsertEnd(&wishlist, "Mouse");

//     printf("\nCurrent wishlist:\n");
//     printDoublyLinkedList(wishlist);

//     Wishlist_clear(&wishlist);

//     printf("\nCurrent wishlist:\n");
//     printDoublyLinkedList(wishlist);

//     return 0;
// }

// gcc -o wishlist_clear wishlist_clear.c doublyLinkedList.c
