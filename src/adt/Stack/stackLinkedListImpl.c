#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

ElType isEmpty(Stack* st) {
    return st == NULL;
}

void push(Stack** stack, ElType elem) {
    Stack* new_node = (Stack* ) malloc(sizeof(Stack));
    new_node->data = elem;
    new_node->link = *stack;
    *stack = new_node;
}

void pop(Stack** stack) {
    if(isEmpty(*stack)) return;
    Stack* temp_head = *stack;
    *stack = ( *stack) -> link;
    free(temp_head);
}

ElType top(Stack* stack) {
    if(isEmpty(stack)) {
        printf("ga ada nbri");
        return -1;
    }

    return stack->data;
}

// reverse a string using stack;
// char* reverse(char* str) {
//     Stack* stack = NULL;
//     int i = 0;
//     while (str[i] != '\0')
//     { 
//         printf("%d " ,i);
//         push(&stack, str[i++]);
//     }
    
//     i = 0;
//     while(!isEmpty(stack)) {
//         str[i++] = top(stack);
//         pop(&stack);
//     }

    
//     return str;
// }

// void reverseLinkedList()

// int main() {
//     char c[4] = "abc"; 
//     printf("%s",reverse(c));
//     return 0;
// }


