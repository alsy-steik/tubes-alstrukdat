#include "stack.h"
#include <stdio.h>
int main() {
    Stack *st = NULL;

    printf("%d\n", isEmpty(st));

    pushNT(&st, "ayam", 9299);
    pushNT(&st, "diddy", 9239);
    pushNT(&st, "ijat", 92949);
    
    printf("%d\n", isEmpty(st));
    printf("%s\n", top(st).nama_barang);
    pop(&st);
    printf("%s\n", top(st).nama_barang);
    pop(&st);
    pop(&st);
    printf("%d\n", isEmpty(st));
    return 0;
}
