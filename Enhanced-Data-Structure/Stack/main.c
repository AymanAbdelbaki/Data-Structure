#include <stdio.h>
#include "global.h"
#include "stack.h"

void DisplayStack(StackEntry e) {

	printf("%c", e);

}

int main() {

	Pstack ps;
	StackInti(&ps);

	StackEntry e;

	e.etype = CHAR;
	e.Type.Char = 'A';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'y';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'm';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'a';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'n';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = ' ';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'A';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'b';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'd';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'e';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'l';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'b';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'a';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'k';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'i';
	if (!StackFull(ps)) Push(e, ps);
	e.Type.Char = 'i';
	if (!StackFull(ps)) Push(e, ps);

	TraverseStack(ps, &DisplayStack);

	printf("\n\n");

}