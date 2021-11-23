/* File : pemain.c */

#include "playerr.h"
#include "listskill.h"
#include <stdio.h>
#include <stdlib.h>
#include "map.h"

/*** Konstruktor Player ***/
void CreatePlayer (ArrayP *P)
{
    /* ALGORITMA */
    (*P).Neff = Nil;
}

void inputPlayerName (ArrayP P, int i) {
    char namaPlayer;
    scanf("%s", &namaPlayer);
    P.contents[i].playerName = namaPlayer;
}

// address newPlayer (infotype x)
// {   Listskill L;
//     /* ALGORITMA */
//     Player *P = (Player *)malloc(sizeof(Player));
//     if (P != Nil) {
//         kodePlayer(P) = x;
//         inputPlayer(&P);
//         CreateEmpty(&L); // pk fungsi createskill
//         playerBuff(P) = false; // inisialisasi satu2
//         position(P) = 0; 
//         return P;
//         // NextPlayer(*P) = Nil; // nextplayer
//     } else {
//         return Nil; 
//     }
// }


void PrintSkill (Listskill S)
{   
    printskill(S);
}

void MovePlayer (ArrayP *P, int ndadu, MAP M, int i) 
{
    int currPosition;
    int x;

    currPosition = (*P).contents[i].position;
    

    if (((currPosition + ndadu) <= Length(M)) && ((currPosition - ndadu) > 0)) {
        if (M.contents[currPosition + ndadu] == "#") {
            if (M.contents[currPosition - ndadu] == "#") {
                
                printf("1. Maju");
                printf("2. Mundur");
                printf("Pilih perintah yang kamu inginkan : ");
                scanf("%d", &x);

                if (x == 1) {
                    currPosition = currPosition + ndadu;
                    M.contents[currPosition] = "*";
                } else {
                    currPosition = currPosition - ndadu;
                    M.contents[currPosition] = "*";
                }
            } else {
                currPosition = currPosition + ndadu;
                M.contents[currPosition] = "*";
            }
        } else {
            if (M.contents[currPosition - ndadu] == "#") {
                printf("Kamu tidak bisa kemana-mana.");

            } else {
                currPosition = currPosition - ndadu;
                M.contents[currPosition] = "*";
            } 
        }
        
    } else {
        printf("Kamu tidak bisa kemana-mana.");
    }
    return currPosition; 
}