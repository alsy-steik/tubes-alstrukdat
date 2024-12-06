#include "Queue.h"
#include "../ArrayDin/ArrayDin.h"
#include "../Barang/Barang.h"
#include "../../boolean.h"
#include "../MesinKata/MesinKata.h"
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

void dequeue(Queue* q) {
    ArrayDinDeleteBeginning(&(q->arr));
}

boolean contains(Queue q, const char* search) {
    boolean result = false;
    int i = 0;
    while(i < q.arr.len) {
       result = result || is_same_string(search, q.arr.arr[i].name);
       ++i;
    }

    puts("asvga");
    return result;
}


char* front(Queue q) {
    return q.arr.arr[0].name;
}

// int main() {
//     // puts("hai");
//     Queue q;
//     initQueue(&q);

//     enqueue(&q, "aj");
//     enqueue(&q, "as");
//     enqueue(&q, "ad");
//     printf("%d\n", contains(q, "acd"));
   
//    return 0;
// }





