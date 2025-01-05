#include "stack.h"
#include "../../util/util.h"
#include <stdlib.h>
#include <stdio.h>

void StackInitEmpty(Stack *st) {
    st->len = 0;
    st->top = NULL;
}

int StackisEmpty(Stack st) {
    return !(st.len);
}

void push(Stack* stack, StackElType el) {
    pushNT(stack, el.nama_barang, el.harga_total);
}

void pushNT(Stack* stack, const char* nama_barang, int total_harga) {
    // printf("STACK|%s %d|\n", nama_barang, total_harga);
    StackNode* new_node = (StackNode* ) malloc(sizeof(StackNode));
    (new_node->data).harga_total = total_harga;
    strcpyHomemade((new_node->data).nama_barang, nama_barang);
    // printf("%s|\n", (new_node->data).nama_barang);
    new_node->link = stack->top;
    stack->top = new_node;
    (stack->len)++;
}

void pop(Stack* stack) {
    if(StackisEmpty(*stack)) return;
    StackNode* temp_head = stack->top;
    stack->top = temp_head->link;
    free(temp_head);
    (stack->len)--;
}

StackElType top(Stack stack) {
    if(StackisEmpty(stack)) {
        printf("ga ada nbri");
        StackElement st;
        st.harga_total = -1;
        return st;
    }

    return stack.top->data;
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


