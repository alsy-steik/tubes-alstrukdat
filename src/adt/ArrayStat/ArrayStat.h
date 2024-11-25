#ifndef ARRAY_STAT_H
#define ARRAY_STAT_H

#include "../Barang/Barang.h"
#include "../User/User.h"
#include <stdio.h>

#define MAX_ARRAY_STAT_SIZE 1000

typedef struct arraystat
{
    User arr[MAX_ARRAY_STAT_SIZE];
    int len;
} ArrayStat;

void createEmpty(ArrayStat *arr);
int getLength(ArrayStat arr);

User getElmt(ArrayStat a, int pos);
void setElmt(ArrayStat *a, User val, int pos);

void insert(ArrayStat *a, User val, int pos);
void insertBeginning(ArrayStat *a, User val);
void insertEnd(ArrayStat *a, User val);

void deleteElem(ArrayStat *a, int pos);
void deleteBeginning(ArrayStat *a);
void deleteEnd(ArrayStat *a);

ArrayStat concat(ArrayStat a1, ArrayStat a2);
#endif
