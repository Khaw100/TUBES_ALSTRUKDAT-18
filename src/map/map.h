#ifndef MAP_H
#define MAP_H

#include "boolean.h"

/*Ukuran panjang maksimum peta*/
#define MAX_Length 100

typedef char ElTypeMap;
typedef int ElTypePortal;
typedef struct {
    ElTypeMap contents [MAX_Length];
    int nEff;
} MAP;
typedef struct {
    ElTypePortal contents [MAX_Length][MAX_Length];
    int row;
    int col;
} Portal;

/* SELEKTOR MAP */
#define Length(M) (M).nEff


boolean IsPortalEmpty (Portal P);
/* Mengirimkan true jika portal kosong */


/* PRIMITIF MAP */

/* *** Konstruktor membentuk MAP *** */
void createMap (MAP *M, int n);
/* I.S. Sebuah nilai n valid untuk memori MAP*/
/* F.S. Sebuah array map M dengan ukuran n terbentuk*/

void displayMap (MAP M);
/* I.S. Sebuah MAP M terdefinisi*/
/* F.S. Nilai dari array Map M ditulis ke layar */

void copyMap (MAP M1, MAP M2);
/* I.S. Sebuah MAP M1 terdefinisi*/
/* F.S. Sebuah MAP M2 akan terisi sama elemennya seperti MAP M1*/

void createPortal (Portal *P, int n);
/* I.S. Sebuah nilai n valid untuk memori MAP*/ 
/* F.S. Sebuah array matriks 2D Portal P dengan ukuran nx2 terbentuk*/

void deployPortal(Portal P, int wayIn, int wayOut);
/* I.S. Sebuah Portal P terdefinisi.*/
/* F.S. Sebuah Portal P akan terbentuk dengan pintu masuk teleport wayIn dan pintu keluar wayOut*/



#endif