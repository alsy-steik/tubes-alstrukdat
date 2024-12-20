#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "doublyLinkedList.h"

void Wishlist_show(DoublyLinkedListNode *head){
    if (head != NULL){
        int i = 1;
        while(head != NULL) {
            printf("%d. %s\n", i, head->data);
            head = head->next;
            i++;
        }
    }

    else{
        printf("Wishlist kamu kosong!\n");
    }
    putchar('\n');
}

// gcc -o wishlist_show_new wishlist_show_new.c doublyLinkedList.c