
#include "boolean.h"
#include "stackins.h"

// !!!====!!! Prototypes !!!======!!!

// ========== Konstruktor ===========
void CreateEmpty(StackI *S){
/*
I.S. Sembarang
F.S. Terbentuk StackI kosong S dengan besar MaxEl
	 StackI kosong memiliki ciri : Top = Nil
*/
	Top(*S) = Nil;
}

// ========= Check Keadaan ==========
boolean IsEmpty(StackI S){
/*
Returns true jika S kosong, false jika tidak
S kosong : Top = Nil
*/
	return Top(S) == Nil;
}
boolean IsFull(StackI S){
/*
Returns true jika S penuh, false jika tidak
S penuh : Top = MaxEl - 1
*/
	return Top(S) == (MaxEl - 1);
}

// === Menambahkan elemen ke stack ===
void Push(StackI *S, Instruction I){
/*
Menambahkan elemen I ke Stack S

I.S. S mungkin kosong, S tidak penuh
F.S. I menjadi elemen Top baru
Proses: Top(S) bertambah 1, I menjadi InfoTop(S) baru
*/
	Top(*S)++;
	InfoTop(*S) = I;
}
// == Mengurangkan elemen dari stack ==
void Pop(StackI *S, Instruction *I){
/*
Mengurangkan elemen I dari Stack S

I.S. S mungkin penuh, S tidak kosong
F.S. I menjadi elemen Top lama, Top menjadi elemen "di bawah" I
Proses: I adalah InfoTop(S), Top(S) berkurang 1
*/
	*I = InfoTop(*S);
	Top(*S)--;
}

// ============ Undo action ============
void Undo(StackI *S){
/*
Undo instruction dari S

I.S. Elemen I adalah elemen paling baru ditambahkan ke stack
F.S. Elemen sebelum I menjadi Top (Seakan-akan I tidak ada di stack)
Proses: Top(S) berkurang 1
*/
	Top(*S)--;
}