#include "ArrayStat.h"
#include "../Barang/Barang.h"
#include "../User/User.h"
#include <stdio.h>

void createEmpty(ArrayStat* arr) {
    arr->len = 0;
}

int getLength(ArrayStat arr) {
    return arr.len;
}

// I.S. : `a` tidak kosong, `pos` < `a.len`
// F.S. : elemen pada `pos`
User getElmt(ArrayStat a, int pos) {
    if(pos)
    return a.arr[pos];
}

void setElmt(ArrayStat* a, User val, int pos) {
    if(pos < a->len) {
        a->arr[pos] = val;
        return;
    }

    puts("Invalid index.");
}

void insert(ArrayStat* a, User val, int pos) {
    if(a->len == MAX_ARRAY_STAT_SIZE) {
        puts("Penuh dawg 💀");
        return;
    }

    if(pos > a->len) {
        puts("Invalid index.");
        return;
    }

    for(int i = a->len; i > pos; --i) {
        a->arr[i] = a->arr[i - 1];
    }
    
    ++(a->len);
    a->arr[pos] = val;
}

void insertBeginning(ArrayStat* a, User val) {
    insert(a, val, 0);
}

void insertEnd(ArrayStat* a, User val) {
    insert(a, val, a->len);
}

void deleteElem(ArrayStat* a, int pos) {
    --(a->len);
    for(int i = pos; i < a->len; ++i) {
        a->arr[i] = a->arr[i + 1];
    }
}

void deleteBeginning(ArrayStat* a) {
    deleteElem(a, 0);
}

void deleteEnd(ArrayStat* a) {
    deleteElem(a, a->len);
}

ArrayStat concat(ArrayStat a1, ArrayStat a2) {
    ArrayStat a3;
    createEmpty(&a3);

    for(int i = 0; i < a1.len; ++i) {
        insertEnd(&a3, a1.arr[i]);
    }
    
    for(int i = 0; i < a2.len; ++i) {
        insertEnd(&a3, a2.arr[i]);
    }
}


