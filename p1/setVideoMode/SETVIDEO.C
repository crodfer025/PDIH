#include <dos.h>
#include <stdio.h>
#include <conio.h>
void setVideoMode(int tipoVideo){
	union REGS inregs, outregs;
	inregs.h.ah = 0x00;
	switch(tipoVideo){
		case 0:
			inregs.h.al = 0x03;
			break;
		case 1:
			inregs.h.al = 0x00;
			break;
		case 2:
			inregs.h.al = 0x13;
			break;
		case 3:
			inregs.h.al = 0x0D;
			break;
	}
	int86(0x10, &inregs, &outregs);
}


int main (){
	int tipovideo;
	printf("Introduzca el numero del modo de video que desea");
	printf("\n0 Texto normal");
	printf("\n1 Texto reducido");
	printf("\n2 Grafico con 256 colores");
	printf("\n3 Grafico con 16 colores\n");
	scanf("%d",&tipovideo);
	setVideoMode(tipovideo);
	getch();
	return 0;

}

