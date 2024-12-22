#ifndef STACK_H
#define STACK_H


typedef struct {
    char nama_barang[100];
    int harga_total;
} StackElement;

typedef StackElement StackElType;
typedef struct stackNode
{
    StackElType data;
    struct stackNode *link;
} StackNode;

typedef struct stack {
    int len;
    StackNode* top;
} Stack;

void StackInitEmpty(Stack *st);
int isEmpty(Stack st);
void push(Stack *stack, StackElType el);
void pushNT(Stack *stack, const char *nama_barang, int total_harga);
void pop(Stack *stack);
StackElType top(Stack stack);

#endif
