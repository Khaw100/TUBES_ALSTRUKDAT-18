#ifndef status_H
#define status_H

#include "boolean.h"
#include "listskill.h"
#include "listdp.h"
#include "map.h"

// roll
void roll(List L, int MaxRoll); 
/* I.S. Sebuah nilai Maxroll untuk mendefinisikan nilai maksimal dari roll yang akan dilakukan*/
/* F.S. Sebuah angka antara 1 hingga MaxRoll secara random*/

// posisi pemain
int posisi(MAP M);
/* I.S. Sebuah Map M yang terdefinisi*/
/* F.S. Mengembalikan integer yang berupa posisi pemain pada peta*/

// ronde
int startRonde();
// Memulai permainan dengan membuat pemain terlebih dahulu yang terdiri dari 2 pemain dan memulai permainan dari ronde 1

// list player
void listPlayer(Player *P, List *L);
// Menyimpan pemain yang bermain dalam permainan ke dalam suatu list dengan asumsi hanya terdapat 2 pemain pada sebuah permainan

// List skill player
void listskillplayer(Listskill *L1, Listskill *L2);
/* I.S. Sebuah Listskill L1 & l2 yang terdefinisi*/
/* F.S. Menyimpan skill yang dimiliki setiap pemain ke dalam suatu list (skill pemain pertama disimpan pada L1 dan pemain kedua disimpan pada L2)*/
#endif