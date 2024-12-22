#ifndef ARRAY_DIN_H
#define ARRAY_DIN_H

#include "../Barang/Barang.h"
#include "../MesinKata/MesinKata.h"
#include "../../util/util.h"

#define INITIAL_ARRAY_DIN_SIZE 100

typedef struct arraydin
{
    Barang *arr;
    int size;
    int len;
} ArrayDin;

void MakeEmptyArrayDin(ArrayDin *a);

int getArrayDinLength(ArrayDin arr);

// I.S. : `a` tidak kosong, `pos` < `a.len`
// F.S. : elemen pada `pos`
Barang getArrayDinElmt(ArrayDin a, int pos);
Barang getArrayDinElmtByName(ArrayDin a, const char* name);
void setArrayDinElmnt(ArrayDin *a, Barang val, int pos);
void ArrayDinInsert(ArrayDin *a, Barang val, int pos);
void ArrayDinInsertBeginning(ArrayDin *a, Barang val);
void ArrayDinInsertEnd(ArrayDin *a, Barang val);
void ArrayDinDeleteElem(ArrayDin *a, int pos);
void ArrayDinDeleteBeginning(ArrayDin *a);
void ArrayDinDeleteEnd(ArrayDin *a);
ArrayDin ArrayDinConcat(ArrayDin a1, ArrayDin a2);

#endif
