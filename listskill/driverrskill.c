// 1. Pintu Ga Ke Mana-Mana 10% || 0
// 2. Cermin Pengganda 10% || 1
// 3. Senter Pembesar Hoki 20% || 2, 3
// 4. Senter Pengecil Hoki 20% || 4, 5
// 5. Mesin Penukar Hoki 10% || 6
// 6. Teknologi Gagal 30% || 7, 8, 9

#include "listskill.h"
#include <stdio.h>
#include <time.h>

int main (){
    time_t t;
    srand((unsigned) (time(&t)));
    printf("%d\n", rskill(t));
    printf("%d\n", rskill(t));
}