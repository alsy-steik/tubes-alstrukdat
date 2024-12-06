typedef struct doublylinkedlist
{
    int data;
    struct node *prev;
    struct node *next;
} DoublyLinkedListNode;


void insertBeginning(DoublyLinkedListNode **head, int elem);
void insertEnd(DoublyLinkedListNode **head, int elem);
void printNode(DoublyLinkedListNode *head);
void printReverse(DoublyLinkedListNode *head);
