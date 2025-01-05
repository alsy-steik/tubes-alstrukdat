#ifndef USER_H
#define USER_H

#include "../SetMap/setmap.h"
#include "../Stack/stack.h"
#include "../LinkedList/doublyLinkedList.h"

#define MAX_USER_NAME 128
#define MAX_USER_PASS 128
#define MAX_USERS 150

typedef struct user
{
    char name[MAX_USER_NAME];
    char password[MAX_USER_PASS];
    int money;
    Map keranjang;
    Stack riwayat_pembelian;
    DoublyLinkedList wishlist;
} User;

typedef struct {
    User ElUser[MAX_USERS];
    int lengthEff;
} ListUser;

void setName(User *user, const char *name);
void setPassword(User *user, const char *password);
// set be lgsung njir sbnernya mah
void setMoney(User *user, int money);
User createUser(const char *name, const char *password, int money);
// void addUser(ArrayStat *LUser, User u);

#endif
