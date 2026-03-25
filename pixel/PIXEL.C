#include <dos.h>
#include <stdio.h>
#include <conio.h>

void pixel(int x, int y, char color){
	union REGS inregs, outregs;

	inregs.h.ah = 0x0C;
	inregs.h.al = color;
	inregs.h.bh = 0x00;
	inregs.x.cx = x;
	inregs.x.dx = y;

	int86(0x10, &inregs, &outregs);
}

int main(){
	union REGS inregs, outregs;

	inregs.h.ah = 0x00;
	inregs.h.al = 0x13;
	int86(0x10, &inregs, &outregs);


	pixel(160,100,4);

	pixel(161,100,3);
	pixel(160,101,5);
	pixel(161,101,6);

	getch();

	inregs.h.ah=0x00;
	inregs.h.al=0x03;

	return 0;

}

