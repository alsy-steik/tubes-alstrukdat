#include "MesinKarakter.h"
#include "../../boolean.h"
#include <stdio.h>

char cc;
char eop;

static FILE* pita;
static int retval;

boolean start(const char* path) {
    cc = ' ';
    if(path == NULL) {
        pita = stdin;
        return true;
    }

    pita = fopen(path, "r");
    return pita != NULL;
}

void adv() {
    // puts("asbhab");
    cc = getc(pita);
    // printf("%c %d\n", cc,((int)cc));
    // puts("cb");
    eop = cc == EOF;
    if(eop && pita != stdin ) {
        puts("Something happening...");
        fclose(pita);
    }
}

void close() {
    if(pita != stdin) fclose(pita);
}
