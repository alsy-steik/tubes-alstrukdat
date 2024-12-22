#include "doublyLinkedList.h"

int main()
{
    DoublyLinkedListNode *head = NULL;
    LinkedListInsertBeginning(&head, "Laptop");
    LinkedListInsertBeginning(&head, "Mouse Gaming");
    printDoublyLinkedListNode(head);

    putchar('\n');
    LinkedListInsertEnd(&head, "Beras Premium");
    LinkedListInsertEnd(&head, "PERTALITE");
    printDoublyLinkedListNode(head);
    putchar('\n');

    LinkedListInsertElem(&head, "Jam Gadang", 1);
    printDoublyLinkedListNode(head);
    putchar('\n');

    LinkedListDeleteBeginning(&head);
    LinkedListDeleteEnd(&head);
    printDoublyLinkedListNode(head);
    putchar('\n');

    LinkedListDeleteElem(&head, 1);
    printDoublyLinkedListNode(head);
    putchar('\n');

    return 0;
}
