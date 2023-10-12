#include "stack.h"
#include <stdlib.h>



#ifdef LIMITED_MEMORY_S

typedef struct stacknode {

	StackEntry entry;
	struct stacknode* next;

} StackNode;

struct stack {

	StackNode* top;
	int size;

};

void StackInti(Pstack* pps) {

	*pps = (struct stack*)malloc(sizeof(struct stack));
	(*pps)->top = NULL;
	(*pps)->size = 0;

}

int StackFull(Pstack ps) {

	return 0;

}

void Push(StackEntry e, Pstack ps) {

	StackNode* pn = (StackNode*)malloc(sizeof(StackNode));

	switch (e.etype) {

	case DOUBLE:
		pn->entry.etype = 1;
		pn->entry.Type.Double = e.Type.Double;
		break;

	case CHAR:
		pn->entry.etype = 0;
		pn->entry.Type.Char = e.Type.Char;
		break;

	}

	pn->next = ps->top;
	ps->top = pn;
	ps->size++;

}

int StackEmpty(Pstack ps) {

	return ps->top == NULL;

}

void Pop(StackEntry* pe, Pstack ps) {

	StackNode* pn;
	
	switch (ps->top->entry.etype) {

	case DOUBLE:
		pe->etype = 1;
		pe->Type.Double = ps->top->entry.Type.Double;
		break;

	case CHAR:
		pe->etype = 0;
		pe->Type.Char = ps->top->entry.Type.Char;
		break;

	}

	pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
	ps->size--;

}

void StackTop(StackEntry* pe, Pstack ps) {


	switch (ps->top->entry.etype) {

	case DOUBLE:
		pe->etype = 1;
		pe->Type.Double = ps->top->entry.Type.Double;
		break;

	case CHAR:
		pe->etype = 0;
		pe->Type.Char = ps->top->entry.Type.Char;
		break;

	}

}

void ClearStack(Pstack ps) {

	StackNode* pn;

	while (ps->top) {

		pn = ps->top;
		ps->top = ps->top->next;
		free(pn);
		ps->size = 0;

	}

}

int StackSize(Pstack ps) {
	
	return ps->size;

}

void TraverseStack(Pstack ps, void(*pf)(StackEntry)) {


	for (StackNode* pn = ps->top; pn; pn = pn->next) {

		(*pf)(pn->entry);

	}
}


#else

struct stack {

	int top;
	StackEntry entry[MAXSTACK];

};

void StackInti(Pstack* pps) {

	*pps = (struct stack*)malloc(sizeof(struct stack));

	(*pps)->top = 0;

}

int StackFull(Pstack ps) {

	return ps->top == MAXSTACK;

}

void Push(StackEntry e, Pstack ps) {

	switch (e.etype) {

	case DOUBLE:
		ps->entry[ps->top].etype = 1;
		ps->entry[ps->top++].Type.Double = e.Type.Double;
		break;

	case CHAR: 
		ps->entry[ps->top].etype = 0;
		ps->entry[ps->top++].Type.Char = e.Type.Char;
		break;

	}

}

int StackEmpty(Pstack ps) {

	return !ps->top;

}

void Pop(StackEntry* pe, Pstack ps) {

	switch (ps->entry[--ps->top].etype) {

	case DOUBLE: 
		pe->etype = ps->entry[ps->top].etype;
		pe->Type.Double = ps->entry[ps->top].Type.Double;
		break;

	case CHAR:
		pe->etype = ps->entry[ps->top].etype;
		pe->Type.Char = ps->entry[ps->top].Type.Char;
		break;

	}

}

void StackTop(StackEntry* pe, Pstack ps) {

	switch (ps->entry[ps->top - 1].etype) {

	case DOUBLE:
		pe->etype = 1;
		pe->Type.Double = ps->entry[ps->top - 1].Type.Double;
		break;

	case CHAR:
		pe->etype = 0;
		pe->Type.Char = ps->entry[ps->top - 1].Type.Char;
		break;

	}
}

int StackSize(Pstack ps) {

	return ps->top;

}

void ClearStack(Pstack ps) {

	ps->top = 0;

}

void TraverseStack(Pstack ps, void (*pf)(StackEntry)) {

	
	for (int i = ps->top - 1; i >= 0; i--) {

		(*pf)(ps->entry[i]);

	}

}

#endif

