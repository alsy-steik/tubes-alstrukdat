#include "MesinKata.h"
#include "../ArrayStat/ArrayStat.h"
#include "../ArrayDin/ArrayDin.h"
#include "../Barang/Barang.h"
#include "../User/User.h"
#include "../../function.h"
#include <stdio.h>

int main() {
    startKata(NULL);
    
    ArrayStat user;
    createEmpty(&user);

    // USER 2
    User u1;
    setName(&u1, "user1");
    setPassword(&u1, "alstrukdatkeren");
    setMoney(&u1, 100);

    MapCreateEmpty(&(u1.keranjang));
    
    StackInitEmpty(&(u1.riwayat_pembelian));
    pushNT(&(u1.riwayat_pembelian), "AK47", 40);
    pushNT(&(u1.riwayat_pembelian), "AK47", 100);
    pushNT(&(u1.riwayat_pembelian), "Labubu", 35);
    pushNT(&(u1.riwayat_pembelian), "AK47", 35);
    pushNT(&(u1.riwayat_pembelian), "Meong", 500);
    pushNT(&(u1.riwayat_pembelian), "Ayam Goreng Crisbar", 20);


    createEmptyLinkedList(&(u1.wishlist));
    LinkedListInsertEnd(&(u1.wishlist), "Ayam Goreng Crisbar");
    LinkedListInsertEnd(&(u1.wishlist), "AK47");

    insertEnd(&user, u1);
    
    // USER 2
    User u2;
    setName(&u2, "user2");
    setPassword(&u2, "kerenbangetkak");
    setMoney(&u2, 25);

    MapCreateEmpty(&(u2.keranjang));
    
    StackInitEmpty(&(u2.riwayat_pembelian));

    createEmptyLinkedList(&(u2.wishlist));
    LinkedListInsertEnd(&(u2.wishlist), "Meong");
    insertEnd(&user, u2);

    ArrayDin barang;
    MakeEmptyArrayDin(&barang);
    
    Barang b1;
    setBarangName(&b1, "AK47");
    setBarangPrice(&b1, 10);
    ArrayDinInsertEnd(&barang, b1);

    Barang b2;
    setBarangName(&b2, "Labubu");
    setBarangPrice(&b2, 20);
    ArrayDinInsertEnd(&barang, b2);
    
    Barang b3;
    setBarangName(&b3, "Ayam Goreng Crisbar");
    setBarangPrice(&b3, 20);
    ArrayDinInsertEnd(&barang, b3);
    
    Barang b4;
    setBarangName(&b4, "Meong");
    setBarangPrice(&b4, 500);
    ArrayDinInsertEnd(&barang, b4);
    
    if(!endKata) {
        saveFile(currentKata.buffer, &user, &barang);
    }
}
