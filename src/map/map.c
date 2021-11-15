#include "map.h"
#include <stdio.h>
#include <stdlib.h>

void createMap (MAP *M, int n) {
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    (*M).nEff = n;
}

void displayMap (MAP M){
    /*KAMUS LOKAL*/
    int i;

    /*ALGORITMA*/
    i = 0;
    for (i; i<=Length(M);i++) {
        printf("%d",M.contents[i]);
    }
}

void copyMap (MAP M1, MAP M2){
    /*KAMUS LOKAL*/
    int i;

    /*ALGORITMA*/
    i = 0;
    createMap(&M2,Length(M1));
    for (i; i<=Length(M1);i++) {
        M2.contents[i] = M1.contents[i];
    }
}

boolean IsPortalEmpty (Portal P) {
    return (P.row == 0 ) && (P.col == 0 );
}

void createPortal (Portal *P, int n) {
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    (*P).row = n;
    (*P).col = 2;
}


void deployPortal (Portal P, int wayIn, int wayOut){
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    if (IsPortalEmpty(P)) {
        P.contents[P.row][0] = wayIn;
        P.contents[P.row][1] = wayOut;
    }
    else {
        P.contents[P.row+1][0] = wayIn;
        P.contents[P.row+1][1] = wayOut;
    }
}

