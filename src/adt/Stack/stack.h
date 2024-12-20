#ifndef STACK_H
#define STACK_H

typedef struct {
    char nama_barang[100];
    int harga_total;
} StackElement;

typedef StackElement ElType;
typedef struct stack
{
    ElType data;
    struct stack *link;
} Stack;

int isEmpty(Stack *st);
void push(Stack **stack, ElType el);
void pushNT(Stack **stack, const char *nama_barang, int total_harga);
void pop(Stack **stack);
ElType top(Stack *stack);

#endif
