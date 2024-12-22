#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "doublyLinkedList.h"

// int NbElmt_list(DoublyLinkedListNode* head){
//     int count = 0;
//     while (head != NULL){
//         count++;
//         head = head->next;
//     }
//     return count;
// }

int absolute(int a){
    if (a >= 0){
        return a;
    }
    else{
        return (-a);
    }
}

void Wishlist_swap(DoublyLinkedList* list, int a, int b){
    int count = list->len;
    /*Menghitung berapa banyak element pada head*/


    if (a > b){
        int temp = b;
        b = a;
        a = temp;
    }
    /*Memastikan a < b*/

    if (a == b){
        printf("Tidak perlu ditukar, index-%d dan index-%d sudah sama", a, b);
    }
    else if (a > count || b > count || a <= 0 || b <= 0){
        printf("Tidak bisa ditukar, index yang diberikan tidak valid [1 - %d]", count);
    }
    
    else{
        DoublyLinkedListNode *P1 = list->head;
        for (int i = 1; i < a; i++){
            P1 = P1->next;
        }

        DoublyLinkedListNode *P2 = list->head;
        for (int i = 1; i < b; i++){
            P2 = P2->next;
        }

        DoublyLinkedListNode *P1_after = P1->next; DoublyLinkedListNode *P1_before = P1->prev;
        DoublyLinkedListNode *P2_after = P2->next; DoublyLinkedListNode *P2_before = P2->prev;

        
        if (P1->next == P2){
            P1->next = P2_after;P1->prev = P2;
            P2->prev = P1_before;P2->next = P1;
            /*Menukar address yang diminta*/
            
            if (P1_before != NULL){
                P1_before->next = P2;
            } 
            if (P2_before != NULL){
                P2_after->prev = P1;
            }
            /*Mengganti address disekitar yang mau diganti*/
            /*Bila di ujung(NULL), maka tak akan si NULL gabakal menunjuk apa-apa*/
        }
        else{
            P1->next = P2_after;P1->prev = P2_before;
            P2->next = P1_after;P2->prev = P1_before;
            /*Menukar address yang diminta*/

            if (P1_before != NULL){
                P1_before->next = P2;
            }
            if(P1_after != NULL){
                P1_after->prev = P2;

            }
            if(P2_before != NULL){
                P2_before->next = P1;

            }
            if(P2_after != NULL){
                P2_after->prev = P1;
            }
            /*Mengganti address disekitar yang mau diganti*/
            /*Bila di ujung(NULL), maka tak akan si NULL gabakal menunjuk apa-apa*/
        }
        if (a == 1){
            list->head = P2;
        }
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

//     Wishlist_swap(&wishlist, 1, 4);


//     printf("\nCurrent wishlist:\n");
//     printDoublyLinkedListNode(wishlist);

//     return 0;
// }


// gcc -o wishlist_swap wishlist_swap.c doublyLinkedList.c
