#include "listskill.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    Listskill L;
    int X;
    CreateEmpty(&L);
    nambahskill(&L, 2);
    nambahskill(&L, 4);
    nambahskill(&L, 3);
    PrintForward(L);
    printf("\n");
    X = lihatisi(L, 1);
    printf("%d", X);
    // printskill(L);
}