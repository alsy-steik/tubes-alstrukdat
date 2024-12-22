#include "adt/MesinKata/MesinKata.h"
#include "boolean.h"
#include "adt/Queue/Queue.h"
#include "adt/ArrayDin/ArrayDin.h"
#include "adt/ArrayStat/ArrayStat.h"
#include "adt/MesinKarakter/MesinKarakter.h"
#include "adt/LinkedList/doublyLinkedList.h"
#include "adt/SetMap/setmap.h"
#include "adt/Stack/stack.h"

boolean START(ArrayStat *pengguna, ArrayDin *barang);
void help(int menu);
boolean Login();
boolean Register();
void Logout();
void Work();
void TebakAngka();
void W0RDL3();
void WorkChallenge();
void store_list(ArrayDin arr);
void store_remove(ArrayDin *arr);
void StoreRequest(ArrayDin arr, Queue* requestQueue);
void StoreSupply(ArrayDin arr, Queue requestQueue);
void Quit();
void WishlistAdd(DoublyLinkedList *head, ArrayDin arr);
void Wishlist_clear(DoublyLinkedList *list);
void Wishlist_remove(DoublyLinkedList *list);
void Wishlist_show(DoublyLinkedList list);
void Wishlist_swap(DoublyLinkedList *list, int a, int b);
void showProfile();
void cartShow(Map *cart, ArrayDin *arr);
