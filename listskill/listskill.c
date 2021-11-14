#include "listskill.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L)==Nil && Last(L)==Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L)=Nil;
    Last(*L)=Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address P;
    P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info (P) = X;
        Next (P) = Nil;
        Prev(P) = Nil;
        return P;    
    }
    else {
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P = First(L) ;
    boolean found = false ;
    if (IsEmpty(L)) {
        return Nil ;
    }
    else {
        while (P != Nil && Info(P) != X) {
                P = Next(P) ;
            }
        }
        return P ;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P;
    P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        InsertLast(L, P);
    }    
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
        Prev(P) = Nil;
        Next(P) = Nil;
    }
    else {
        Prev(P) = Nil;
        Prev(First(*L)) = P;
        Next(P) = First(*L);
        First(*L) = P;
    }    
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    }
    else {
        Next(P) = Nil;
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }

}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    if (Prec == Last(*L)) {
        InsertLast(L, P) ;
    }
    else {
        Next(P) = Next(Prec) ;
        Next(Prec) = P ;
        Prev(P) = Prec ;
        Prev(Next(P)) = P ;
    }    
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
    if (Succ == First(*L)) {
        InsertFirst(L, P) ;
    }
    else {
        Next(Prev(Succ)) = P ;
        Next(P) = Succ ;
        Prev(P) = Prev(Succ) ;
        Prev(Succ) = P ;
    }
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(First(*L));
    if (First(*L)==Nil){
        Last(*L)=Nil;
    }
    else {
        Next(*P) = Nil;
        Prev(First(*L))=Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    if (Prev(Last(*L)) == Nil) {
        DelFirst(L,P);
    }
    else {
        DelAfter(L,P, Prev(Last(*L)));
    }    
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
    address P;
    P = Search(*L, X);
    if (P!=Nil){
        if (Prev(P)!=Nil) {
            DelAfter(L, P, Prev(P));
        }
        else if (Next(P)!=Nil){
            DelBefore(L, P, Next(P));
        }
        else {
            Last(*L)=Nil;
            First(*L)=Nil;
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    if (Next(*Pdel)!=Nil){
        Prev(Next(*Pdel)) = Prec;
    }
    else {
        Last(*L)=Prec;
    }
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
    *Pdel = Prev(Succ);
    Prev(Succ) = Prev(*Pdel);
    if (Prev(*Pdel)!=Nil){
        Next(Prev(*Pdel)) = Succ;
    }
    else {
        First(*L) = Succ;
    }
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
    address CP;
    printf("[");
    if (IsEmpty(L) == false){
        CP = First(L);
        do {
            printf("%d", Info(CP));
            CP = Next(CP);
            if (CP!=Nil){
                printf(",");
            }
        }while (CP!=Nil);
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
    address CP;
    printf("[");
    if (IsEmpty(L) == false){
        CP = Last(L);
        do {
            printf("%d", Info(CP));
            CP = Prev(CP);
            if (CP!=Nil){
                printf(",");
            }
        }while (CP!=Nil);
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */



void rskill (List *L){
    int r, skill; 
    time_t t;
    srand((unsigned) (time(&t)));
    for (int i = 0; i<10 ; i++){
        r = rand() % 10;
        printf("%d \n", r);
    }        
}

int NbElmt (List L){
    address P;
    P = First(L);
    int count;
    count = 0;
    while (P!=Nil){
        count = count + 1;
        P = Next(P);
    }
    return count;
}

void DelI (List *L, int n){
    address P;
    P = First(*L);
    int i;
    i = 0;
    if (n==1){
        DelFirst(L, P);
    }
    else if (n==NbElmt(*L)){
        DelLast(L, Last(*L));
    }
    else {
        while (i<n){
            i = i + 1;
            P = Next(P);
        }
        P = Prev(P);
        DelAfter(L, P, Prev(P));
    }    
}

void nambahskill (List *L, int r){
    int skill;
    if (r==0){
        skill = 1; // id skill 1 : Pintu Ga Ke Mana-Mana
        printf ("Pintu Ga Ke Mana-Mana \n");
    }
    else if (r==1){ 
        skill = 2; // id skill 2 : Cermin Pengganda
        printf ("Cermin Pengganda \n");
    }
    else if (r==2 || r==3){ 
        skill = 3; // id skill 3 : Senter Pembesar Hoki
        printf ("Senter Pembesar Hoki \n");
    }
    else if (r==4 || r==5){ 
        skill = 4; // id skill 4 : Senter Pengecil Hoki
        printf ("Senter Pengecil Hoki \n");
    }
    else if (r==6){ 
        skill = 5; // id skill 5 : Mesin Penukar Hoki
        printf ("Mesin Penukar Hoki \n");
    }  
    else if (r==7 || r==8 || r==9){ 
        skill = 0; // skill 6 ga masuk ke list
        printf("Teknologi Gagal \n");
    }    

    // harusnya udah dapet id skillnya

    if (skill!=0 && NbElmt(*L)<=10){
        InsVLast(L, skill);
        printf("Skill ");
        printf("%d", skill);
        printf(" berhasil dimasukkan\n");
    } 
    else if (skill==0){
        printf("Sayang sekali Anda mendapatkan teknologi gagal :( \n");
    }
    else if (NbElmt(*L)>10){
        printf("Jumlah skill yang dimiliki sudah mencapai maksimum\n");
    }
}

void buangskill (List *L, int x){
    if (IsEmpty(*L)) {
        printf("Anda tidak mempunyai skill \n");    
    }
    else {
        x = abs(x);
        DelI(L, x);
    }
}    
