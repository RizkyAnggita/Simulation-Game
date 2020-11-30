/* Driver ADT ListCommand */
/* List Implementasi Array, yang berisi daftar command dan durasi yg dibutuhkan */

#include "listcommand.h"
#include "command.h"
#include <stdio.h>

int main(){
    TabCommand T;
    Kata test;
    Commtype C;

    createEmptyListCommand(&T);
    printCommand(T);

    test.TabKata[0] = 'n';
    test.TabKata[1] = 'e';
    test.TabKata[2] = 'w';
    test.Length = 3;

    C.duration = 5;
    C.perintah = test;
    InsertNewCommand(&T, C);
    printCommand(T);
    
    Kata CLoad;
	CLoad.TabKata[0] = 'l';
	CLoad.TabKata[1] = 'o';
	CLoad.TabKata[2] = 'a';
	CLoad.TabKata[3] = 'd';
	CLoad.Length = 4;

    C.duration = 10;
    C.perintah = CLoad;
    
    InsertNewCommand(&T, C);
    printCommand(T);

    printf("\n\n");

    printf("\n NBELmtCommand: %d\n", NbElmtCommand(T));
    printf("\n\n");

    Commtype A = makeCommtype(CLoad, 10);
    InsertNewCommand(&T,A);
    printCommand(T);    

    return 0;
}

