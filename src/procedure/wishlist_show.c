#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../adt/LinkedList/doublyLinkedList.h"

void Wishlist_show(DoublyLinkedList list){
    printDoublyLinkedList(list);
}

// int main(){
//     DoublyLinkedList wishlist;
//     createEmptyLinkedList(&wishlist);

//     LinkedListInsertEnd(&wishlist, "Laptop");
//     LinkedListInsertEnd(&wishlist, "Smartphone");
//     LinkedListInsertEnd(&wishlist, "Headphone");
//     LinkedListInsertEnd(&wishlist, "Monitor");
//     LinkedListInsertEnd(&wishlist, "Keyboard");
//     LinkedListInsertEnd(&wishlist, "Mouse");

//     printf("\nCurrent wishlist:\n");
//     Wishlist_show(wishlist);

//     return 0;
// }

// gcc -o wishlist_show wishlist_show.c doublyLinkedList.c
