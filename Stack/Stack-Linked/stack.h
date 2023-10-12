
//#define INFIX_TO_POSTFIX

#ifdef INFIX_TO_POSTFIX

#define StackEntry char
#define TOGGLE 0

#else


#define StackEntry double
#define TOGGLE 1

#endif




#ifndef STACK_H
#define STACK_H


typedef struct stacknode {

	StackEntry entry;
	struct stacknode* next;

} StackNode;

typedef struct stack {

	StackNode* top;

} Stack;

void StackInti(Stack*);

int StackFull(Stack*);

void Push(StackEntry, Stack*);

int StackEmpty(Stack*);

void Pop(StackEntry*, Stack*);

void StackTop(StackEntry*, Stack*);

void ClearStack(Stack*);

void TraverseStack(Stack*, void(*)(StackEntry));

int StackSize(Stack*);




#endif STACK_H
