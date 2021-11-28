#include "map.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    MAP M;
    Portal P;
    int i, n;
    n = 10;
    createEmptyMap(&M);
    M.nEffM = n;
    printf("Panjang efektif dari Map: %d\n", M.nEffM);
    for (i = 1; i<= M.nEffM; i++){
        M.contents[i] = '.';
    }
    printf("Isi dari MAP: \n");
    displayMap(M, 2);
    P = setPortal(P, M.nEffM);
    int j;
    P.Neff = 4;
    printf("Isi dari Portal: \n");
    for(j=1;j<=P.Neff;j++){
        printf("%d ", P.contents[j]);
    }
    printf("\n");
    if (IsPortalEmpty(P)){
        printf("Kosong\n");
    }else{
        printf("Ada isinya\n");
    }
    int rnd;
    time_t t;
    srand((unsigned) (time(&t)));
    rnd = roll(t, 10);
    printf("%d", rnd);
}