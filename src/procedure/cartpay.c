#include <stdio.h>
#include "../adt/Stack/stack.h"
#include "../adt/User/User.h"
#include "../util/util.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/ArrayDin/ArrayDin.h"
#include "../adt/SetMap/setmap.h"
#include "../adt/Barang/Barang.h"

extern ArrayStat user;
extern int IndeksUser;

void Pay(int total_biaya);

void showCart(ArrayDin arr)
{
    Map cart = user.arr[IndeksUser].keranjang;
    if (cart.count == 0){
        printf("Keranjang kamu kosong!\n");
    }
    else {
        int Counter;
        int total_biaya = 0;
        printf("Berikut adalah isi keranjangmu.\n");
        printf("Kuantitas  Nama    Total\n");
        for (Counter = 0; Counter < cart.count; Counter++){
            char barangtemp[100];
            strcpyHomemade(barangtemp, cart.data[Counter].nama_barang);
            int quantity = MapGetEl(cart, barangtemp);

            Barang currentBarang = getArrayDinElmtByName(arr,barangtemp);
            int harga = currentBarang.price;
            int total = quantity * harga;
            total_biaya = total_biaya + total;
            printf("%d          %s    %d\n", quantity, barangtemp, total);
        }
        printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli?\n", total_biaya);
        Pay(total_biaya);
    }
    return;
}

void Pay(int total_biaya){
    int HasilTemp = 0;
    // int Counter = 0;
    printf("Ya/Tidak : ");
    startKata(NULL);
    if (is_same_string(currentKata.buffer, "Ya")){
        HasilTemp = user.arr[IndeksUser].money - total_biaya;
        // 3 - 4 = -1
        if (HasilTemp < 0){
            printf("Uangmu kurang %d bro, Balik lagi kalau uangmu cukup ya :3c\n", total_biaya - user.arr[IndeksUser].money);
        }
        else {
            user.arr[IndeksUser].money = user.arr[IndeksUser].money - total_biaya;
            printf("Barang-barang sudah terbeli :D\n");
        }
        return;
    }
    else if (is_same_string(currentKata.buffer, "Tidak")){
        printf("Baik, Kembali ke Menu\n");
        return;
    }
    else {
        printf("Masukkanmu aneh :skull:, Kembali ke Menu\n");
    }

}


// int main(){
//     User user1 = createUser("Atma","wwww",50000);
//     addUser(&USERS,user1);
//     total_biaya = 0;

//     MapCreateEmpty(&cart);
    
//     Barang barang1 = {"Skibidi", 2000};
//     Barang barang2 = {"Toilet", 3000};
//     Barang barang3 = {"Kai Cenat", 20000};
//     Barang barang4 = {"Mewing", 30000};

//     int quantity = 1;

//     MakeEmptyArrayDin(&arr);
//     ArrayDinInsertEnd(&arr, barang1);
//     ArrayDinInsertEnd(&arr, barang2);
//     ArrayDinInsertEnd(&arr, barang3);
//     ArrayDinInsertEnd(&arr, barang4);

//     MapInsert(&cart, &barang1, quantity);
//     MapInsert(&cart, &barang2, quantity);
//     MapInsert(&cart, &barang3, quantity);
//     MapInsert(&cart, &barang4, quantity);

//     showCart();
    

//     return 0;
// }
