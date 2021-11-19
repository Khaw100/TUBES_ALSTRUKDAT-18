#include "map.h"
#include "mesin_kar.h"
#include "mesin_kata.h"
#include <stdio.h>
#include <stdlib.h>

void createEmptyMap (MAP *M ){
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    (*M).nEff = 0;
}

void loadMap (){
    ;
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
    createEmptyMap(&M2);
    for (i; i<=Length(M1);i++) {
        M2.contents[i] = M1.contents[i];
    }
}

boolean IsPortalEmpty (Portal P) {
    return (P.Neff = 0 );
}

void createEmptyPortal (Portal *P) {
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    (*P).Neff = 0;
}

void setPortal(Portal P, int n) {
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    for(i=0;i<P.Neff+1;i++){
        P.contents[i] = -1;
    }
}