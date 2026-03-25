#include <dos.h>
#include <stdio.h>
#include <conio.h>

char* getVideoMode(){
	int modo;
	union REGS inregs, outregs;
	inregs.h.ah = 0x0F;
	int86(0x10,&inregs, &outregs);

	modo = outregs.h.al;

	if(modo == 0x00 || modo == 0x01 || modo == 0x02 || modo == 0x03|| modo == 0x07){
		return "modo texto";
	} else {
		return "modo grafico";
	}

}

int main(){

	printf("El modo de vido actual es %s", getVideoMode());
	getch();

	return 0;

}