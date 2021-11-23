#ifndef player_H
#define player_H

#include "boolean.h"
#include "listskill.h"

#define Nil NULL

#define Max_length 4



typedef int infotype;

typedef struct {
    boolean isImun;
    boolean isCerminPengganda;
    boolean isSenterPembesar; 
    boolean isSenterPengecil;
} Buff;

typedef struct tPlayer *address;

typedef struct tPlayer {
    // infotype kodePlayer;
	char playerName; // nama
	Listskill skill;  // listskill hrsny
	Buff playerBuff;  // buff yang dimiliki player 
    int position;
    //address nextPlayer;
} Player;

typedef struct {
    Player contents [Max_length];
    int Neff;
} ArrayP;

#define Length(P) (P).Neff
#define nextSkill(S) (S)->nextSkill
#define kodePlayer(P) (P).kodePlayer
#define playerName(P) (P).playerName
#define skill(S) (S)->skill
#define BuffImunitas(P) (P).playerBuff.isimun
#define BuffCerminPengganda(P) (P).playerBuff.iscerminpengganda
#define BuffPembesarHoki(P) (P).playerBuff.ispembesarhoki
#define BuffPengecilHoki(P) (P).playerBuff.ispengecilhoki
#define position(P) (P).position
#define FirstPlayer(P) (P).firstPlayer
// #define NextPlayer(P) (P).nextPlayer

/*** Konstruktor Player ***/
void CreatePlayer (Player *P);

void inputPlayerName (Player *P);

// address newPlayer (infotype X);

void PrintSkill (Listskill S);

void MovePlayer (Player *P, int n);



#endif