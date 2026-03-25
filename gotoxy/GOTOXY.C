#include <dos.h>
#include <stdio.h>

void gotoxy(int fila, int columna){
	union REGS inregs, outregs;
	inregs.h.ah = 2;
	inregs.h.bh = 0;
	inregs.h.dh = fila;
	inregs.h.dl = columna;

	int86(0x10, &inregs, &outregs);




}

int main (){

	int valorx;
	int valory;


	printf("Introduce un valor para fila: ");
	scanf("%d", &valorx);

	while(valorx >= 25){
		printf("Introduce un valor valido - inferior a 25 -: ");
		scanf("%d", &valorx);
		}

	printf("Introduce un valor para columna: ");
	scanf("%d",&valory);
	while(valory >= 80){
		printf("Introduce un valor valido - inferior a 80 -: ");
		scanf("%d", &valory);
	}

	gotoxy(valorx, valory);
	getch();

	return 0;

}