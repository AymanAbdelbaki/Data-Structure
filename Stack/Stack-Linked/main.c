#include <stdio.h>

#include "stack.h"

/*2
void Display(StackEntry e) {

	printf("%d\n", e);

}
2*/

/*3
void STACKTOP(int* pe, Stack* ps) {

	Pop(pe, ps);
	Push(pe, ps);

}
3*/

/*4
int STACKSIZE(StackEntry* pe, Stack* ps) {

	int i;
	for (i = 0; !StackEmpty(ps); i++) {

		Pop(pe, ps);

	}

	return i;

}
4*/


/*7
void Display(StackEntry e) {

	printf("%c", e);

}
7*/




int main() {


	StackEntry e;
	Stack s;

	StackInti(&s);

	/*1
	e = 0;
	if (!StackFull(&s))
		Push(&e, &s);

	e = 1;
	if (!StackFull(&s))
		Push(&e, &s);

	e = 2;
	if (!StackFull(&s))
		Push(&e, &s);

	e = 3;
	if (!StackFull(&s))
		Push(&e, &s);

	e = 4;
	if (!StackFull(&s))
		Push(&e, &s);

	e = 5;
	if (!StackFull(&s))
		Push(&e, &s);

	e = 6;
	if (!StackFull(&s))
		Push(&e, &s);




	if (!StackEmpty(&s))
		Pop(&e, &s);
	printf("%d\n", e);

	if (!StackEmpty(&s))
		Pop(&e, &s);
	printf("%d\n", e);

	if (!StackEmpty(&s))
		Pop(&e, &s);
	printf("%d\n", e);

	if (!StackEmpty(&s))
		Pop(&e, &s);
	printf("%d\n", e);

	if (!StackEmpty(&s))
		Pop(&e, &s);
	printf("%d\n", e);

	if (!StackEmpty(&s))
		Pop(&e, &s);
	printf("%d\n", e);

	if (!StackEmpty(&s))
		Pop(&e, &s);
	printf("%d\n", e);
	1*/

	/*2
	e = 10;
	Push(&e, &s);
	e = 5;
	Push(&e, &s);
	e = -90;
	Push(&e, &s);

	TraverseStack(&s, &Display);
	2*/

	/*3
	printf("%d\n", e);

	e = 9;
	Push(&e, &s);

	e = 10;
	Push(&e, &s);

	e = 11;
	Push(&e, &s);


	STACKTOP(&e, &s);
	printf("%d\n", e);

	Pop(&e, &s);
	printf("%d\n", e);
	Pop(&e, &s);
	printf("%d\n", e);
	3*/


	/*4
	if (!StackFull(&s))
		Push(&e, &s);
	if (!StackFull(&s))
		Push(&e, &s);
	if (!StackFull(&s))
		Push(&e, &s);
	if (!StackFull(&s))
		Push(&e, &s);
	if (!StackFull(&s))
		Push(&e, &s);



	printf("The size of the stack is: %d\n", STACKSIZE(&e, &s));
	4*/


	/*5
	e = 'i';
	Push(e, &s);

	e = 'l';
	Push(e, &s);

	e = 'A';
	Push(e, &s);

	e = ' ';
	Push(e, &s);

	e = 'i';
	Push(e, &s);

	e = 'k';
	Push(e, &s);

	e = 'a';
	Push(e, &s);

	e = 'b';
	Push(e, &s);

	e = 'l';
	Push(e, &s);

	e = 'e';
	Push(e, &s);

	e = 'd';
	Push(e, &s);

	e = 'b';
	Push(e, &s);

	e = 'A';
	Push(e, &s);

	e = ' ';
	Push(e, &s);

	e = 'n';
	Push(e, &s);

	e = 'a';
	Push(e, &s);

	e = 'm';
	Push(e, &s);

	e = 'y';
	Push(e, &s);

	e = 'A';
	Push(e, &s);


	for (int i = 0; i < 19; i++) {

		Pop(&e, &s);
		printf("%c", e);

	}
	5*/

	/*6
	e = 'A';
	char c, a;
	Push(e, &s);
	StackTop(&c, &s);
	printf("%c\n", c);
	Pop(&a, &s);
	printf("%c\n", a);
	StackTop(&c, &s);
	printf("%c\n", c);
	6*/

	/*7
	e = 'i';
	Push(e, &s);

	e = 'l';
	Push(e, &s);

	e = 'A';
	Push(e, &s);

	e = ' ';
	Push(e, &s);

	e = 'i';
	Push(e, &s);

	e = 'k';
	Push(e, &s);

	e = 'a';
	Push(e, &s);

	e = 'b';
	Push(e, &s);

	e = 'l';
	Push(e, &s);

	e = 'e';
	Push(e, &s);

	e = 'd';
	Push(e, &s);

	e = 'b';
	Push(e, &s);

	e = 'A';
	Push(e, &s);

	e = ' ';
	Push(e, &s);

	e = 'n';
	Push(e, &s);

	e = 'a';
	Push(e, &s);

	e = 'm';
	Push(e, &s);

	e = 'y';
	Push(e, &s);

	e = 'A';
	Push(e, &s);

	printf("%d\n", StackSize(&s));

	TraverseStack(&s, &Display);

	printf("\n\n");

	StackTop(&e, &s);
	printf("%c\n", e);
	StackTop(&e, &s);
	printf("%c\n", e);

	printf("\n\n");

	Pop(&e, &s);
	printf("%c\n", e);
	Pop(&e, &s);
	printf("%c\n", e);

	printf("\n\n");

	ClearStack(&s);

	if (!StackEmpty(&s)) {

		Pop(&e, &s);
		printf("%c\n", e);

	}

	7*/








}