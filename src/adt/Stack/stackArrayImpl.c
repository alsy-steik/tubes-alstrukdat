// #include <stdlib.h>
// #include <stdio.h>

// typedef struct stack {
//     int top;
//     int arr[100];
// } Stack;

// int isEmpty(Stack st) {
//     return st.top == -1;
// }

// void push(Stack* st, int elem) {
//     st->arr[++(st->top)] = elem;
// }

// void pop(Stack* st) {
//     if(isEmpty(*st)) --(st->top);
// }

// int top(Stack st) {
//     if(isEmpty(st)) return -1;
//     return st.arr[st.top];
// }


// Stack createStack() {
//     Stack st;
//     st.top = -1;
// }

// int main() {
//     Stack st = createStack();

//     push(&st, 1);
//     push(&st, 2);
//     push(&st, 3);
//     return 0;
// }
