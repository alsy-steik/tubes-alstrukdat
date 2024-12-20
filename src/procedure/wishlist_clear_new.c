#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "doublyLinkedList.h"

boolean IsEmpty(DoublyLinkedListNode* head){
    return (head == NULL);
}

void Wishlist_clear(DoublyLinkedListNode **head){
    *head = NULL;
}

int main() {
    DoublyLinkedListNode* wishlist = NULL;

    LinkedListInsertEnd(&wishlist, "Laptop");
    LinkedListInsertEnd(&wishlist, "Smartphone");
    LinkedListInsertEnd(&wishlist, "Headphone");
    LinkedListInsertEnd(&wishlist, "Monitor");
    LinkedListInsertEnd(&wishlist, "Keyboard");
    LinkedListInsertEnd(&wishlist, "Mouse");

    printf("\nCurrent wishlist:\n");
    printDoublyLinkedListNode(wishlist);

    Wishlist_clear(&wishlist);

    printDoublyLinkedListNode(wishlist);

    return 0;
}

// gcc -o wishlist_clear_new wishlist_clear_new.c doublyLinkedList.c