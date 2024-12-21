#include <stdio.h>
#include "../adt/ArrayDin/ArrayDin.h"
#include "../adt/Barang/barang.h"

void store_list(ArrayDin arr)
{
    int N = getArrayDinLength(arr);
    printf("List barang yang ada di toko:\n");
    if (N > 0)
    {
        for (int i = 0; i < N; i++)
        {
            Barang storelist = getArrayDinElmt(arr, i);
            printf("- %s - Harga: %d\n", storelist.name, storelist.price);
        }
    }

    else
    {
        printf("TOKO KOSONG\n");
    }
}

