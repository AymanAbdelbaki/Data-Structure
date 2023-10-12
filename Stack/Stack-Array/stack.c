#include "Stack.h"

void Inti(Stack* ps) {

	ps->top = 0;

}

int StackFull(Stack* ps) {

	if (ps->top == MaxStack)
		return 1;
	else
		return 0;

}

void Push(StackEntry e, Stack* ps) {

	ps->entry[ps->top++] = e;

}

int StackEmpty(Stack* ps) {

	return !ps->top;

}

void Pop(StackEntry* pe, Stack* ps) {

	*pe = ps->entry[--ps->top];

}

void StackTop(StackEntry* pe, Stack* ps) {

	*pe = ps->entry[ps->top - 1];

}

int StackSize(Stack* ps) {

	return ps->top;

}

void ClearStack(Stack* ps) {

	ps->top = 0;

}

void TraverseStack(Stack* ps, void (*pf)(StackEntry)) {

	for (int i = ps->top - 1; i >= 0; i--) {

		(*pf)(ps->entry[i]);

	}

}