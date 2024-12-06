// #include "doublyLinkedList.h"
// #include <stdio.h>
// #include <stdlib.h>

// void insertBeginning(DoublyLinkedListNode** head, int elem) {

//     DoublyLinkedListNode* new_DoublyLinkedListNode = (DoublyLinkedListNode* ) malloc(sizeof(DoublyLinkedListNode));
//     if(!new_DoublyLinkedListNode) return;
//     new_DoublyLinkedListNode->data = elem;
//     new_DoublyLinkedListNode->next = *head;
//     if( *head != NULL) {
//         ( *head) -> prev = new_DoublyLinkedListNode;
//     }
//     new_DoublyLinkedListNode->prev = NULL;
//     *head = new_DoublyLinkedListNode;
// }

// void insertEnd(DoublyLinkedListNode** head, int elem) {
    
//     DoublyLinkedListNode* temp = *head;
//     if(temp == NULL) {
//         insertBeginning(head, elem);
//         return;
//     }

//     DoublyLinkedListNode* new_DoublyLinkedListNode = (DoublyLinkedListNode* ) malloc(sizeof(DoublyLinkedListNode));
//     new_DoublyLinkedListNode->data = elem;
//     new_DoublyLinkedListNode->next = NULL;
//     while(temp->next != NULL) {
//         temp = temp->next;
//     }

    
//     temp->next = new_DoublyLinkedListNode;
//     new_DoublyLinkedListNode->prev = temp;
// }

// void printDoublyLinkedListNode(DoublyLinkedListNode* head) {
//     while(head != NULL) {
//         printf("%d ", head->data);
//         head = head->next;
//     }

//     putchar('\n');
// }

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

// // int main() {

// //     DoublyLinkedListNode* head = NULL;
// //     insertBeginning(&head, 1);
// //     insertBeginning(&head, 2);
// //     insertBeginning(&head, 3);

// //     insertEnd(&head, 4);
// //     insertEnd(&head, 5);
// //     insertEnd(&head, 6);

// //     printDoublyLinkedListNode(head);
// //     printReverse(head);

// // }
