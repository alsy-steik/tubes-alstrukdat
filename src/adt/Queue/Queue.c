#include "Queue.h"
#include "ArrayDin.h"
#include "Barang.h"
#include "../boolean.h"

#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue* q) {
    MakeEmptyArrayDin(&(q->arr));
}

boolean isEmpty(Queue q) {
    return !(q.arr.len);
}

void enqueue(Queue* q, const char* nama_barang) {
    ArrayDinInsertEnd(&(q->arr), createBarang(nama_barang, -1));
}

char* dequeue(Queue* q) {
    char* a = (q->arr).arr[0].name;
    ArrayDinDeleteBeginning(&(q->arr));

    return a;
}

char* front(Queue q) {
    return q.arr.arr[0].name;
}





