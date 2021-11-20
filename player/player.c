/* File : pemain.c */

#include "player.h"
#include "listskill.c"
#include <stdio.h>
#include <stdlib.h>


/*** Konstruktor Player ***/
void CreatePlayer (Player *P)
{
    /* ALGORITMA */
    FirstPlayer(*P) = Nil;
}

void inputPlayer (Player *P, int n) {
    address P;
    CreatePlayer(&P);
    P = FirstPlayer(*P);
    address NP;
    for (int i = 1; i <= n; i++) {
        NP = newPlayer();
        P = NP;
        printf("Nama Player ke %d: ", n);
        scanf("%s", &(playerName(P)));
        P = NEXT(P);
    }
    P = FirstPlayer(*P);
}

address newPlayer ()
{
    /* ALGORITMA */
    ElmtPlayer *P = (ElmtPlayer *)malloc(sizeof(ElmtPlayer));
    if (P != Nil) {
        kodePlayer(P) = 0;
        nextPlayer(P) = Nil;
        FirstSkill(skill(P)) = Nil;
        return P;
    } else {
        return Nil; 
    }
}

/*** Konstruktor Skill ***/
void CreateListSkill (ListSkill *S)
{
    /* ALGORITMA */
    FirstSkill(*S) = Nil;
}

address newSkill ()
{
    /* ALGORITMA */
    ElmtSkill *P = (ElmtSkill *)malloc(sizeof(ElmtSkill));
    if (P != Nil) {
        skillName(P) = "";
        nextSkill(P) = Nil;
        return P;
    } else {
        return Nil;
    }
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchPemain (Player P, infotype X)
{/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    /* ALGORITMA */
    boolean found;
    address found_add, CP;
    /* ALGORITMA */
    found = false;
    found_add = Nil;
    CP = FirstPlayer(P);
    if (!IsEmpty(P)) {
        do {
            if (Info(CP) == X) {
                found = true;
                found_add = CP;
            } else {
                CP = Next(CP);
            }
        } while ((CP != Nil) && !found);
    }
    return found_add;
}

/*** Lain-lain ***/
void UpdateSkill (ListSkill S, infotype X)
{/* Menambahkan skill baru seorang pemain ke dalam ListSkill */
    Player P;
    SearchPemain(P, X);
    nambahskill(L, r);
}

int NbSkill (ListSkill S, infotype X)
{/* Mengirimkan banyaknya skill yang dimiliki oleh seorang pemain. */
    address CP;
    Player P;
    /* ALGORITMA */
    CP = SearchPemain (P, X);
    NbElmt (skill);
}

void PrintSkill (ListSkill S, infotype X)
{

}

void MovePlayer () 
{

}

boolean isBuffEmpty (Buff B)
{
    return B.Neff = 0;
}

void CreateEmptyBuff (Buff *B)
{
    (*B).Neff = 0;
}

void PrintBuff (Buff B, infotype X)
{

}