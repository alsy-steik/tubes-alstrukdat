#include <stdio.h>
#include "ArrayDin.h"
#include "Barang.h"

void store_list(ArrayDin arr)
{
    int N = getArrayDinLength(arr);
    printf("List barang yang ada di toko:\n");
    if (N > 0)
    {
        for (int i = 0; i < N; i++)
        {
            Barang storelist = getArrayDinElmt(arr, i);
            printf("- %s\n", storelist.name);
        }
    }

    else
    {
        printf("TOKO KOSONG\n");
    }
}
