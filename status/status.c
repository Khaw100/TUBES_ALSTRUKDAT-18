#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll(List L, int MaxRoll){
    int random;
    srand (time(NULL));
    random = rand() % MaxRoll + 1;
    printf("%d",random);
}

int posisi(MAP M){
    char nilai_posisi = '*';
    for (int i = 1; i<= Length(M); i++){
        if(M.contents[(i)] == nilai_posisi){
            return i;
        }
    }
}
int startRonde(){
    CreatePlayer(P1,1);
    CreatePlayer(P2,2);
    return 1;
}

void listPlayer(Player *P, List *L){
    for(int i = 1; i <= 2; i++){ // Asumsi pemain pada permainan berjumlah 2
        InsVFirst(L, P);
    }
}

void listskillplayer(Listskill *L1, Listskill *L2){ // L1 = list skill pemain 1 & L2 = list skill pemain 2
    nambahskill(L1, rskill);
    nambahskill(L2, rskill);
}


