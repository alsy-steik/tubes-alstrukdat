#include "MesinKarakter.h"
#include <stdio.h>

char cc;
char eop;

static FILE* pita;
static int retval;

void start(const char* path) {
    cc = ' ';
    if(path == NULL) {
        pita = stdin;
        return;
    }

    pita = fopen(path, "r");
}

void adv() {
    // puts("asbhab");
    cc = getc(pita);
    // puts("cb");
    eop = cc == NEW_LINE;
    if(eop && pita != stdin) {
        fclose(pita);
    }
}

