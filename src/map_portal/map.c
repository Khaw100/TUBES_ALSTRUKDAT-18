#include "map.h"
#include "../mesin_kar_mesin_kata/mesin_kar.h"
#include "../mesin_kar_mesin_kata/mesin_kata.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createEmptyMap (MAP *M ){
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    (*M).nEffM = 0;
}


void displayMap (MAP M, int posisi){
    /*KAMUS LOKAL*/
    int i;

    /*ALGORITMA*/
    i = 1;
    for (i; i<=(M).nEffM;i++) {
        if (i==posisi){
            printf("%c", '*');
        }
        else{
            printf("%c",M.contents[i]);
        }    
    }
    printf("\n");
}

boolean IsPortalEmpty (Portal P) {
    return (P.Neff = 0 );
}

void createEmptyPortal (Portal *P) {
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    (*P).Neff = 0;
}


Portal setPortal(Portal P, int n){
    createEmptyPortal(&P);
    P.Neff = n;
    int j;
    for(j=1;j<=P.Neff;j++){
        P.contents[j] = -1; 
    }
    return P;
}

int roll (time_t y, int maksdadu){ 
    return (rand() % maksdadu) + 1;
}