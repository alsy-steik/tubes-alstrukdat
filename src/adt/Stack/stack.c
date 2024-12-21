#include "stack.h"
#include "../../util/util.h"
#include <stdlib.h>
#include <stdio.h>

int isEmpty(Stack* st) {
    return st == NULL;
}

void push(Stack** stack, StackElType el) {
    pushNT(stack, el.nama_barang, el.harga_total);
}

void pushNT(Stack** stack, const char* nama_barang, int total_harga) {
    Stack* new_node = (Stack* ) malloc(sizeof(Stack));
    (new_node->data).harga_total = total_harga;
    strcpyHomemade((new_node->data).nama_barang, nama_barang);
    new_node->link = *stack;
    *stack = new_node;
}

void pop(Stack** stack) {
    if(isEmpty(*stack)) return;
    Stack* temp_head = *stack;
    *stack = ( *stack) -> link;
    free(temp_head);
}

StackElType top(Stack* stack) {
    if(isEmpty(stack)) {
        printf("ga ada nbri");
        StackElement st;
        st.harga_total = -1;
        return st;
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


