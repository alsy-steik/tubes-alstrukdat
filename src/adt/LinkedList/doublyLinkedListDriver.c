#include "doublyLinkedList.h"

int main()
{
    DoublyLinkedListNode *head = NULL;
    LinkedListInsertBeginning(&head, "fakyumanig");
    LinkedListInsertBeginning(&head, "nigga :D");
    printDoublyLinkedListNode(head);

    putchar('\n');
    LinkedListInsertEnd(&head, "linggangguliguli");
    LinkedListInsertEnd(&head, "WAZZZAAAA");
    printDoublyLinkedListNode(head);
    putchar('\n');

    LinkedListInsertElem(&head, "diddy", 1);
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
