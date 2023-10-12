#include "stack.h"
#include <stdlib.h>

void StackInti(Stack* ps) {

	ps->top = NULL;

}

int StackFull(Stack* ps) {

	return 0;

}

void Push(StackEntry e, Stack* ps) {

	StackNode* pn = (StackNode*)malloc(sizeof(StackNode));
	pn->entry = e;
	pn->next = ps->top;
	ps->top = pn;

}

int StackEmpty(Stack* ps) {

	return ps->top == NULL;

}

void Pop(StackEntry* pe, Stack* ps) {

	StackNode* pn;
	*pe = ps->top->entry;
	pn = ps->top;
	ps->top = ps->top->next;
	free(pn);

}

void StackTop(StackEntry* pe, Stack* ps) {

	*pe = ps->top->entry;

}

void ClearStack(Stack* ps) {

	StackNode* pn;

	while (ps->top) {

		pn = ps->top;
		ps->top = ps->top->next;
		free(pn);
		
	}

}

void TraverseStack(Stack* ps, void(*pf)(StackEntry)) {

	for (StackNode* pn = ps->top; pn; pn = pn->next) {

		(*pf)(pn->entry);

	}
}

int StackSize(Stack* ps) {

	int i;
	StackNode* pn = ps->top;

	for (i = 0; pn; pn = pn->next) {

		i++;

	}
	return i;

}