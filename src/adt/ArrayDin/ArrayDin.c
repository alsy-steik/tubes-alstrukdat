#include "ArrayDin.h"
#include "../../util/util.h"
#include <stdio.h>
#include <stdlib.h>

void MakeEmptyArrayDin(ArrayDin* a) {
    a->len = 0;
    a->size = INITIAL_ARRAY_DIN_SIZE;
    a->arr = (Barang* ) malloc(sizeof(Barang) * a->size);
}

int getArrayDinLength(ArrayDin arr)
{
    return arr.len;
}

// I.S. : `a` tidak kosong, `pos` < `a.len`
// F.S. : elemen pada `pos`
Barang getArrayDinElmt(ArrayDin a, int pos)
{
    return a.arr[pos];
}

Barang getArrayDinElmtByName(ArrayDin a, const char* name)
{
    for (int i = 0; i < a.len; ++i)
    {
        if (is_same_string(a.arr[i].name, name))
        {
            return a.arr[i];
        }
    }

    puts("Element not found.");
    return createBarang("", 0);
}

void setArrayDinElmnt(ArrayDin *a, Barang val, int pos)
{
    if (pos < a->len)
    {
        a->arr[pos] = val;
        return;
    }

    puts("Invalid index.");
}

void ArrayDinInsert(ArrayDin *a, Barang val, int pos)
{
    if (pos > a->len)
    {
        puts("Invalid index.");
        return;
    }

        // puts("called"); // ?
    if (a->len == a->size)
    {   
        a->size *= 2;
        a->arr = realloc(a->arr, sizeof(Barang) * a->size);
    }

    for (int i = a->len; i > pos; --i)
    {
        a->arr[i] = a->arr[i - 1];
    }

    ++(a->len);
    a->arr[pos] = val;
}

void ArrayDinInsertBeginning(ArrayDin *a, Barang val)
{
    ArrayDinInsert(a, val, 0);
}

void ArrayDinInsertEnd(ArrayDin *a, Barang val)
{
    ArrayDinInsert(a, val, a->len);
}

void ArrayDinDeleteElem(ArrayDin *a, int pos)
{
    --(a->len);
    for (int i = pos; i < a->len; ++i)
    {
        a->arr[i] = a->arr[i + 1];
    }

    if(a->len <= a->size / 4) {
        a->size /= 2;
        a->arr = realloc(a->arr, sizeof(Barang) * a->size);
    }

    // for(int i = 0; i < a->len; ++i) {
    //     printf("%d. %s\n", i + 1, a->arr[i].name);
    // }
}

void ArrayDinDeleteBeginning(ArrayDin *a)
{
    ArrayDinDeleteElem(a, 0);
}

void ArrayDinDeleteEnd(ArrayDin *a)
{
    ArrayDinDeleteElem(a, a->len);
}

ArrayDin ArrayDinConcat(ArrayDin a1, ArrayDin a2)
{
    ArrayDin a3;
    a3.len = 0;
    a3.size = a1.len + a2.len;
    a3.arr = (Barang* ) malloc(sizeof(Barang) * a3.size);


    for (int i = 0; i < a1.len; ++i)
    {
        ArrayDinInsertEnd(&a3, a1.arr[i]);
    }

    for (int i = 0; i < a2.len; ++i)
    {
        ArrayDinInsertEnd(&a3, a2.arr[i]);
    }
}
