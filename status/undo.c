#include "undo.h"
#include "status.c"


void CreateEmpty (Stack *S){
    Top(*S) = Nil;
}

boolean IsEmpty (Stack S){
    return (Top(S) ==  Nil);
}
boolean IsFull (Stack S){
    return (Top(S)== MaxEl);
}

void Push (Stack * S, infotipe X){
    Top(*S) += 1;
    InfoTop(*S) = X;
}

void Pop (Stack * S, infotipe* X){
    *X = InfoTop(*S);
    Top(*S) -= 1;
}