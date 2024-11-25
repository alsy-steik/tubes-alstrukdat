#include "adt/MesinKata/MesinKata.h"
#include "boolean.h"
#include "adt/Queue/Queue.h"
#include "adt/ArrayDin/ArrayDin.h"
#include "adt/ArrayStat/ArrayStat.h"
#include "adt/MesinKarakter/MesinKarakter.c"

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
void StoreRequest(ArrayDin arr, Queue requestQueue);
void StoreSupply(ArrayDin arr, Queue requestQueue);
void Quit();
