#include <stdio.h>
#include <stdlib.h>
#include "mesin_kata.h"

int main(){
    char input[100] = "test.txt";
    STARTKATA(input);
    PrintKata(CKata);
    ADVKATA();
    PrintKata(CKata);
}