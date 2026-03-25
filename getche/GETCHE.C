#include <dos.h>
#include <stdio.h>
#include <conio.h>

char mi_getche(){
	union REGS inregs, outregs;
	char tecla;

	inregs.h.ah=0x00;

	int86(0x16, &inregs, &outregs);

	tecla = outregs.h.al;

	inregs.h.ah = 0x0E;
	inregs.h.al = tecla;
	inregs.h.bh = 0x00;

	int86(0x10, &inregs,&outregs);

	return tecla;
}

int main(){
	char resultado;

	printf("Pulsa cualquier tecla");
	resultado = mi_getche();

	printf("\nSe ha recebido la tecla \n", resultado);

	getch();
	return 0;

}