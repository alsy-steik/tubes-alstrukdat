#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "../MesinKarakter/MesinKarakter.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../ArrayStat/ArrayStat.h"
#include "../ArrayDin/ArrayDin.h"


#define BUFFER_SIZE 100
#define BLANK ' '

#define MARK NEW_LINE

typedef struct {
    char buffer[BUFFER_SIZE];
    int length;
} Kata;

extern bool endKata;
extern Kata currentKata;

void ignoreBlank();
void startKata(const char* path);
void startKataMajemuk(const char* path);
void advKata();
void salinKata();
void salinKataMajemuk();
int Uppercased_Char(int num);
boolean is_same_string (const char str1[], const char str2[]);
int getNum();
void saveFile(const char *filename, ArrayStat *user, ArrayDin *barang);
void PrintKata(Kata kata);
boolean Load(const char *filename, ArrayStat* user, ArrayDin *barang);

#endif


