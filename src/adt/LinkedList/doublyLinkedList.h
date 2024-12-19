#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#define MAX_BARANG_LEN 100
typedef struct doublylinkedlist
{
    char data[MAX_BARANG_LEN];
    struct doublylinkedlist *prev;
    struct doublylinkedlist *next;
} DoublyLinkedListNode;

void copyStr(char *dest, const char *source);
void LinkedListInsertBeginning(DoublyLinkedListNode **head, const char *elem);
void LinkedListInsertElem(DoublyLinkedListNode **head, const char *elem, int pos);
void LinkedListInsertEnd(DoublyLinkedListNode **head, const char *elem);
void LinkedListDeleteElem(DoublyLinkedListNode **head, int pos);
void LinkedListDeleteBeginning(DoublyLinkedListNode **head);
void LinkedListDeleteEnd(DoublyLinkedListNode **head);
void printDoublyLinkedListNode(DoublyLinkedListNode *head);

#endif
