#include "doublyLinkedList.h"
#include <stdio.h>
#include "../../boolean.h"
#include <stdlib.h>
#include "../../util/util.h"

void createEmptyLinkedList(DoublyLinkedList* list) {
    list->len = 0;
    list->head = NULL;
}

boolean LinkedListIsEmpty(DoublyLinkedList list) {
    return !(list.head);
}

void LinkedListInsertBeginning(DoublyLinkedList* list, const char* elem) {

    DoublyLinkedListNode* new_DoublyLinkedListNode = (DoublyLinkedListNode* ) malloc(sizeof(DoublyLinkedListNode));
    if(!new_DoublyLinkedListNode) return;

    strcpyHomemade(new_DoublyLinkedListNode->data, elem);

    new_DoublyLinkedListNode->next = list->head;
    if( list->head != NULL) {
        list->head->prev = new_DoublyLinkedListNode;
    }
    new_DoublyLinkedListNode->prev = NULL;
    list->head = new_DoublyLinkedListNode;
    (list->len)++;
}

void LinkedListInsertElem(DoublyLinkedList* list, const char* elem, int pos) {
    if(pos == 0) {
        LinkedListInsertBeginning(list, elem);
        return;
    }

    DoublyLinkedListNode *temp = list->head;
    while (pos--)
    {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        DoublyLinkedList temp_list;
        temp_list.head = temp;
        LinkedListInsertEnd(&temp_list, elem);
        return;
    }

    DoublyLinkedListNode *new_node = (DoublyLinkedListNode* ) malloc(sizeof(DoublyLinkedListNode));
    strcpyHomemade(new_node->data, elem);
    
    temp->prev->next = new_node;
    new_node->prev = temp->prev;

    new_node->next = temp;
    temp->prev = new_node;

    list->len++;
}

const char* LinkedListGetElmt(DoublyLinkedList list, int pos) {
    while(pos--) {
        list.head = list.head->next;
    }

    return list.head->data;
}

void LinkedListInsertEnd(DoublyLinkedList* list, const char* elem) {
    
    DoublyLinkedListNode* temp = list->head;
    if(temp == NULL) {
        LinkedListInsertBeginning(list, elem);
        return;
    }

    DoublyLinkedListNode* new_DoublyLinkedListNode = (DoublyLinkedListNode* ) malloc(sizeof(DoublyLinkedListNode));
    strcpyHomemade(new_DoublyLinkedListNode->data, elem);
    new_DoublyLinkedListNode->next = NULL;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    
    temp->next = new_DoublyLinkedListNode;
    new_DoublyLinkedListNode->prev = temp;

    list->len++;
}

void LinkedListDeleteElem(DoublyLinkedList* list, int pos) {
    DoublyLinkedListNode *temp = list->head;
    while(pos--) {
        temp = temp->next;
    }

    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        list->head = temp->next;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    list->len--;
    free(temp);
}

void LinkedListDeleteBeginning(DoublyLinkedList* list) {
    LinkedListDeleteElem(list, 0);
}

void LinkedListDeleteEnd(DoublyLinkedList* list) {
    LinkedListDeleteElem(list, list->len - 1);
    // DoublyLinkedListNode *temp = *head;
    // while(temp->next != NULL) {
    //     temp = temp->next;
    // }

    // DoublyLinkedListNode* prev = temp->prev;
    // prev->next = NULL;
    // free(temp);
}

void printDoublyLinkedList(DoublyLinkedList list) {
    
    if (list.head != NULL){
        int i = 1;
        while(list.head != NULL) {
            printf("%d. %s\n", i, list.head->data);
            list.head = list.head->next;
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


