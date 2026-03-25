#include <dos.h>
#include <stdio.h>
#include <conio.h>

void textBackgroundColor(char color){
	union REGS inregs, outregs;

	inregs.h.ah= 0x09;
	inregs.h.al = ' ';
	inregs.h.bh =0x00;

  inregs.h.bl = color << 4;
	inregs.x.cx = 1;

	int86(0x10, &inregs, &outregs);

}


int main(){
	int color;
	printf("Elige un color de fondo");
	printf("\n 0.Negro \n 1.Azul \n 2.Verde \n 3.Cian \n 4.Rojo \n .Magenta \n");
	scanf("%i",&color);

	textBackgroundColor(color);
	cprintf("\n Se ha pintado el fondo del color seleccionado");

	getch();
	return 0;

}
