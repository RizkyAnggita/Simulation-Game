
#ifndef stackins_H
#define stackins_H

#include "boolean.h"
#include "instruction.h"

#define Nil -1
#define MaxEl 30
/*
Nil   : Nilai Top(S) yang kosong (index di luar batas array)
MaxEl : Nilai sementara max number of instructions
*/

/*
StackI adalah ADT Stack yang diimplementasikan dengan array statik
StackI berisi info yang berupa tipe data buatan Instruction 
(see: instruction.h)
*/
typedef int address;
typedef struct {
	Instruction I[MaxEl];
	address Top;
} StackI;

// !!!======!!! Selektor !!!======!!!
#define Top(S) (S).Top
#define InfoTop(S) (S).I[(S).Top]
/*
Top(S) : Index elemen terbaru/teratas (Top) dari stack
InfoTop(S) : Instruction di index Top; Instruction terbaru di stack
*/

// !!!====!!! Prototypes !!!======!!!

// ========== Konstruktor ===========
void CreateEmpty(StackI *S);
/*
I.S. Sembarang
F.S. Terbentuk StackI kosong S dengan besar MaxEl
	 StackI kosong memiliki ciri : Top = Nil
*/

// ========= Check Keadaan ==========
boolean IsEmpty(StackI S);
/*
Returns true jika S kosong, false jika tidak
S kosong : Top = Nil
*/
boolean IsFull(StackI S);
/*
Returns true jika S penuh, false jika tidak
S penuh : Top = MaxEl - 1
*/

// === Menambahkan elemen ke stack ===
void Push(StackI *S, Instruction I);
/*
Menambahkan elemen I ke Stack S

I.S. S mungkin kosong, S tidak penuh
F.S. I menjadi elemen Top baru
Proses: Top(S) bertambah 1, I menjadi InfoTop(S) baru
*/

// == Mengurangkan elemen dari stack ==
void Pop(StackI *S, Instruction *I);
/*
Mengurangkan elemen I dari Stack S

I.S. S mungkin penuh, S tidak kosong
F.S. I menjadi elemen Top lama, Top menjadi elemen "di bawah" I
Proses: I adalah InfoTop(S), Top(S) berkurang 1
*/

// ============ Undo action ============
void Undo(StackI *S);
/*
Undo instruction dari S

I.S. Elemen I adalah elemen paling baru ditambahkan ke stack
F.S. Elemen sebelum I menjadi Top (Seakan-akan I tidak ada di stack)
Proses: Top(S) berkurang 1
*/

StackI ReverseStack(StackI SPrev);
/*  Mengembalikan Stack of Instruction kebalikan dari SPrev
    Top dari SPrev menjadi elemen pertama Stack baru dan seterusnya*/
#endif