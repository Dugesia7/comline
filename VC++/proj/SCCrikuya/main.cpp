#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "mydebug.h"
#include "main.h"

bigstruct* calc(bigstruct*);//ƒAƒ‹ƒSƒŠƒYƒ€‚Í‚±‚±‚ÅŽÀ‘•

//mainŠÖ”
int main() {
	bigstruct big;
	input(&big);
	calc(&big);
	output(&big);
	//showbig(&big);
	//for(;;);
	return 0;
}

bigstruct* calc(bigstruct* b) {
	if (b->abln == 0)b->yn = false;
	else {
		b->yn=true;
		int x, y;
		for (x = 0; !b->abls[x]; x++);
		for (y = x + 1; !b->abls[y]; y++);
		while(y<b->n) {
			marry(b, x, y, true);
			x = b->n + b->m-1;
			for (y++; !b->abls[y]; y++);
		}
		marry(b, x, x, false);
	}
	return b;
}