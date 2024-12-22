#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#define MAX_BARANG_LEN 100
typedef struct doublylinkedlistNode
{
    char data[MAX_BARANG_LEN];
    struct doublylinkedlistNode *prev;
    struct doublylinkedlistNode *next;
} DoublyLinkedListNode;

typedef struct doublylinkedlist 
{
    int len;
    DoublyLinkedListNode* head;
} DoublyLinkedList;

void createEmptyLinkedList(DoublyLinkedList *list);
void LinkedListInsertBeginning(DoublyLinkedList* list, const char *elem);
void LinkedListInsertElem(DoublyLinkedList* list, const char *elem, int pos);
void LinkedListInsertEnd(DoublyLinkedList* list, const char *elem);
void LinkedListDeleteElem(DoublyLinkedList* list, int pos);
void LinkedListDeleteBeginning(DoublyLinkedList* list);
void LinkedListDeleteEnd(DoublyLinkedList* list);
void printDoublyLinkedList(DoublyLinkedList list);
const char* LinkedListGetElmt(DoublyLinkedList list, int pos);

#endif
