#include "doublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void copyStr(char* dest, const char* source) {
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }

    dest[i] = source[i];
}

void LinkedListInsertBeginning(DoublyLinkedListNode** head, const char* elem) {

    DoublyLinkedListNode* new_DoublyLinkedListNode = (DoublyLinkedListNode* ) malloc(sizeof(DoublyLinkedListNode));
    if(!new_DoublyLinkedListNode) return;

    copyStr(new_DoublyLinkedListNode->data, elem);

    new_DoublyLinkedListNode->next = *head;
    if( *head != NULL) {
        ( *head) -> prev = new_DoublyLinkedListNode;
    }
    new_DoublyLinkedListNode->prev = NULL;
    *head = new_DoublyLinkedListNode;
}

void LinkedListInsertElem(DoublyLinkedListNode** head, const char* elem, int pos) {
    if(pos == 0) {
        LinkedListInsertBeginning(head, elem);
        return;
    }

    DoublyLinkedListNode *temp = *head;
    while (pos--)
    {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        LinkedListInsertEnd(head, elem);
        return;
    }

    DoublyLinkedListNode *new_node = (DoublyLinkedListNode* ) malloc(sizeof(DoublyLinkedListNode));
    copyStr(new_node->data, elem);
    
    DoublyLinkedListNode *prev = temp->prev;
    prev->next = new_node;
    new_node->prev = temp;

    new_node->next = temp;
    temp->prev = new_node;
}

void LinkedListInsertEnd(DoublyLinkedListNode** head, const char* elem) {
    
    DoublyLinkedListNode* temp = *head;
    if(temp == NULL) {
        LinkedListInsertBeginning(head, elem);
        return;
    }

    DoublyLinkedListNode* new_DoublyLinkedListNode = (DoublyLinkedListNode* ) malloc(sizeof(DoublyLinkedListNode));
    copyStr(new_DoublyLinkedListNode->data, elem);
    new_DoublyLinkedListNode->next = NULL;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    
    temp->next = new_DoublyLinkedListNode;
    new_DoublyLinkedListNode->prev = temp;
}

void LinkedListDeleteElem(DoublyLinkedListNode** head, int pos) {
    DoublyLinkedListNode *temp = *head;
    while(pos--) {
        temp = temp->next;
    }

    if(temp->prev != NULL) {
        DoublyLinkedListNode* prev_node = temp->prev;
        prev_node->next = temp->next;
    } else {
        *head = temp->next;
    }

    if(temp->next != NULL) {
        DoublyLinkedListNode* next_node = temp->next;
        next_node->prev = temp->prev;
    }

    free(temp);
}

void LinkedListDeleteBeginning(DoublyLinkedListNode** head) {
    DoublyLinkedListNode *temp = *head;
    *head = temp->next;
    if( *head != NULL) {
        ( *head)->prev = NULL;
    }
    free(temp);
}

void LinkedListDeleteEnd(DoublyLinkedListNode** head) {
    DoublyLinkedListNode *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    DoublyLinkedListNode* prev = temp->prev;
    prev->next = NULL;
    free(temp);
}

void printDoublyLinkedListNode(DoublyLinkedListNode* head) {
    if (head != NULL){
        int i = 1;
        while(head != NULL) {
            printf("%d. %s\n", i, head->data);
            head = head->next;
            i++;
            /*Loop dari awal list hingga akhir dan print tiap elmt*/
        }
        /*Wishlist tidak kosong*/
    }

    else{
        printf("Wishlist kamu kosong!\n");
        /*Bila wishlist masih kosong*/
    }
    putchar('\n');
}

// void printReverse(DoublyLinkedListNode* head) {
//     if(head == NULL) return;

//     while(head->next != NULL) {
//         head = head->next;
//     }

//     while(head != NULL) {
//         printf("%d ", head->data);
//         head = head->prev;
//     }

//     putchar('\n');
// }


