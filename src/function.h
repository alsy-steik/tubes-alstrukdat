#include "adt/MesinKata/MesinKata.h"
#include "boolean.h"
#include "adt/Queue/Queue.h"
#include "adt/ArrayDin/ArrayDin.h"
#include "adt/ArrayStat/ArrayStat.h"
#include "adt/MesinKarakter/MesinKarakter.h"
#include "adt/LinkedList/doublyLinkedList.h"
#include "adt/SetMap/setmap.h"
#include "adt/Stack/stack.h"
#include "util/util.h"

boolean START(ArrayStat *pengguna, ArrayDin *barang);
void help(int menu);

// Authentication
boolean Login();
boolean Register();
void Logout();

void Work();
void WorkChallenge();

// Challenge
void TebakAngka();
void W0RDL3();

// Store
void store_list(ArrayDin arr);
void store_remove(ArrayDin *arr);
void StoreRequest(ArrayDin arr, Queue* requestQueue);
void StoreSupply(ArrayDin* arr, Queue* requestQueue);

void Quit(ArrayStat *user, ArrayDin* barang);

// Wishlist
void WishlistAdd(DoublyLinkedList *head, ArrayDin arr);
void Wishlist_clear(DoublyLinkedList *list);
void Wishlist_remove(DoublyLinkedList *list);
void Wishlist_remove_i(DoublyLinkedList *list, int i);
void Wishlist_show(DoublyLinkedList list);
void Wishlist_swap(DoublyLinkedList *list, int a, int b);

// Cart
void cartAdd(Map *cart, ArrayDin *arr, const char* nama_barang, int quantity);
void cartShow(Map *cart, ArrayDin *arr);
void cartRemove(Map *cart, const char* nama_barang, int quantity);
void showCart(ArrayDin arr);

void showProfile();
void showHistory(Stack history, int n);
