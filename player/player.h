#ifndef player_H
#define player_H

#include "boolean.h"

#define Nil NULL
#define MAX_Length 4

typedef int infotype;
typedef char ElTypeBuff;

typedef struct tElmtSkill *address;
typedef struct tElmtSkill {
	char skillName[20];
	address nextSkill;
} ElmtSkill;
typedef struct {
	address FirstSkill;
	address LastSkill;
} ListSkill;

typedef struct {
	ElTypeBuff contents [MAX_Length];
	int Neff;
} Buff;

typedef struct tElmtplayer *address;
typedef struct tElmtplayer { 
	infotype kodePlayer;
	char playerName[20]; // nama
	ListSkill skill;  // listskill hrsny
	Buff playerbuff;  // buff yang dimiliki player 
	address nextPlayer;
} ElmtPlayer;
typedef struct {
	address FirstPlayer;
	address LastPlayer;
} Player;


#define FirstSkill(S) (S).FirstSkill
#define LastSkill(S) (S).LastSkill
#define FirstPlayer(P) (P).FirstPlayer
#define LastPlayer(P) (P).LastPlayer
#define skillName(S) (S)->skillName[20]
#define nextSkill(S) (S)->nextSkill
#define kodePlayer(P) (P)->kodePlayer
#define playerName(P) (P)->playerName[20]
#define skill(S) (S)->skill
#define playerBuff(P) (P)->playerBuff
#define nextPlayer(P) (P)->nextPlayer
#define Length(B) (B).Neff


/*** Konstruktor Player ***/
void CreatePlayer (Player *P);

address newPlayer ();

/*** Konstruktor Skill ***/
void CreateListSkill (ListSkill *S);
/* */

address newSkill ();

/*** PENCARIAN SEBUAH ELEMEN LIST ***/
address SearchPemain (Player P, infotype X);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/*** Lain-lain ***/
void UpdateSkill (ListSkill S, infotype X);
/* Menambahkan skill baru seorang pemain */

int NbSkill (ListSkill S, infotype X);
/* Mengirimkan banyaknya skill yang dimiliki oleh seorang pemain. */

void PrintSkill (ListSkill S, infotype X);

void MovePlayer ();

boolean isBuffEmpty (Buff B);

void CreateEmptyBuff (Buff *B);

void PrintBuff (Buff B, infotype X);

#endif



// buff itu bagusnya boolean aja true/false.. nanti di main nya tinggal lihat kurleb kayak if player1.buff.pembesar hoki == True