#include <dos.h>
#include <stdio.h>
void setCursorType(int tipo_cursor){
	union REGS inregs, outregs;
	inregs.h.ah = 0x01;
	switch(tipo_cursor){
		case 0:
			inregs.h.ch = 010;
			inregs.h.cl = 000;
			break;
		case 1:
			inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;
		case 2:
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
	}
	int86(0x10, &inregs, &outregs);

}



int main () {
	int num_cursor;
	printf("Selecciona un valor para el tipo de cursor, 0 para invisible, 1 para normal y 2 para grueso: ");
	scanf("%d",&num_cursor);

	setCursorType(num_cursor);
	getch();

	return 0;

}