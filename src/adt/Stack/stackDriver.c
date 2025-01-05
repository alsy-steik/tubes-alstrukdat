#include "stack.h"
#include <stdio.h>
int main() {
    Stack st;
    StackInitEmpty(&st);

    printf("%d\n", st.len);

    pushNT(&st, "AK47", 40);
    pushNT(&st, "AK47", 100);
    pushNT(&st, "Lalabu", 35);
    pushNT(&st, "AK47", 10);
    pushNT(&st, "Meong", 500);
    pushNT(&st, "Ayam Goreng Crisbar", 20);

    StackNode* bjir = st.top;
    while(bjir != NULL) {
        printf("%s| %d\n", bjir->data.nama_barang, bjir->data.harga_total);
        bjir = bjir->link;
    }

    puts("========================================");
    printf("%d\n", StackisEmpty(st));
    printf("%s\n", top(st).nama_barang);
    pop(&st);
    printf("%s\n", top(st).nama_barang);
    pop(&st);
    printf("%s\n", top(st).nama_barang);
    pop(&st);
    printf("%s\n", top(st).nama_barang);
    pop(&st);
    printf("%s\n", top(st).nama_barang);
    pop(&st);
    printf("%s\n", top(st).nama_barang);
    pop(&st);
    printf("%d\n", StackisEmpty(st));
    return 0;
}
