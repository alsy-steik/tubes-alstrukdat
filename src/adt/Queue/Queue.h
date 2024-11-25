#ifndef QUEUE_H
#define QUEUE_H

#include "../boolean.h"
#include "ArrayDin.h"

#define QUEUE_INITIAL_SIZE 100;
typedef struct
{
    ArrayDin arr;
} Queue;

void initQueue(Queue *q);

boolean isEmpty(Queue q);

void enqueue(Queue *q, const char *nama_barang);

char *dequeue(Queue *q);

char *front(Queue q);

#endif
