#include "mesin_kata.h"
#include "listskill.h"
#include "boolean.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "time.h"


int rolldadu(int maks){
    int ndadu;
    srand((unsigned)time(0));
    ndadu=(rand() % maks) + 1; 
    return ndadu;
}


int main() {
    int npemain;
    int i;
    // Player P;

    printf("SELAMAT DATANG DIPERMAINAN MOBITANGGA\n");
    printf("Silahkan masukkan jumlah pemain: ");
    scanf("%d\n", &npemain);

    // MSUKIN KE LIST OF PLAYER
    ArrayP P;
    CreateEmptyPlayer(&P);
    P.Neff = npemain;

    for(i=0;i<npemain;i++){
        inputPlayer(P, i);
    }

    // MENU
    boolean endgame = false;
    while (endgame){
        char cmd;
        printf("Masukkan command: ");
        scanf("%c\n", &cmd);

        switch (cmd)
        {
        case 'ROLL':

            break;
        case 'INSPECT':
            break;
        
        case 'SKILL':
            int x, tukar;
            printskill(S); // L di sini listskill per player
            printf("\n");
            scanf("%d Masukkan skill: ", &x);
            if (x<0){
                buangskill(*L, x);
            }
            else if (x>0){ // pakai skill
                if (lihatisi(L, x)==1){
                    BuffImunitas(P) = true; // P di sini list player
                    printf("%s ", playerName(P));
                    printf("memakai skill Pintu Ga Kemana-Mana.\n");
                    // efek bisa menolak teleport
                }
                else if (lihatisi(L,x)==2){
                    BuffCerminPengganda(P) = true;
                    printf("%s ", playerName(P));
                    printf("memakai skill Cermin Pengganda.\n");
                    // efek nya mengcopy skill ke InsertLast(L)
                }
                else if (lihatisi(L,x)==3){
                    BuffPembesarHoki(P) = true;
                    printf("%s ", playerName(P));
                    printf("memakai skill Senter Pembesar Hoki.\n");
                    // efek nya ke dadu
                }
                else if (lihatisi(L,x)==4){
                    BuffPengecilHoki(P) = true;
                    printf("%s ", playerName(P));
                    printf("memakai skill Senter Pengecil Hoki\n");
                    // efek nya ke dadu
                }
                else if (lihatisi(L,x)==5){
                    printf("memakai skill Penukar Posisi\n");
                    // buat fungsi print nama ada siapa aja
                    printf("%d Masukkan nomor berapa yang ingin Anda tukar :", &tukar);
                    // buat fungsi penukar posisi yaitu dengan menukar nama dari list player
                }
                // kalo 0 langsung skip
            }
            break;
        
        case 'MAP':
            break;

        case 'UNDO':
            break;
        
        case 'ENDTURN':
            break;
        
        case 'BUFF':
            break;
        }
    }
}

