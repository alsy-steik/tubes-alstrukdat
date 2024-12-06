typedef char ElType;
typedef struct stack
{
    ElType data;
    struct stack *link;
} Stack;

ElType isEmpty(Stack *st);

void push(Stack **stack, ElType elem);

void pop(Stack **stack);

ElType top(Stack *stack);
