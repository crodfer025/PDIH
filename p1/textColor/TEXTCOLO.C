#include <dos.h>
#include <stdio.h>
#include <conio.h>


unsigned char color_actual = 15;

void textColor(unsigned char color){
	union REGS inregs, outregs;
	inregs.h.ah = 0x09;
	inregs.h.al = ' ';
	inregs.h.bh = 0x00;
	inregs.h.bl = color;
	inregs.x.cx = 1;

	int86(0x10, &inregs, &outregs);


}

int main (){
	int color;
	int bucle = 1;

	char texto[100];

	printf("Elige un color");
	printf("\n 0.Negro \n 1.Azul \n 2.Verde \n 3.Cian \n 4.Rojo \n 5.Magenta \ 6.Marron \n 7.Gris Claro \n 8.Gris Oscuro \n 9.Azul Claro \n 10.Verde Claro \n 11.Cian Claro \n 12.Rojo claro \n 13.Magenta Claro \n 14.Amarillo \n 15.Blanco");
	scanf("%i", &color);

	textColor(color);
	while (bucle == 1){

		cprintf("\r\n El texto se encuentra del color que se ha seleccionado");
		scanf("%s", texto);

		cprintf("\r\n Desea seguir escribiendo? \n 1.Si 2.No");
		scanf("%i", &bucle);
	}

	return 0;
}