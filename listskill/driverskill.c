#include "listskill.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    Listskill L;
    CreateEmpty(&L);
    nambahskill(&L, 2);
    nambahskill(&L, 4);
    printf("\n");
    buangskill(&L,1);
    PrintForward(L);
}