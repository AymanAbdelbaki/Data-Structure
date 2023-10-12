#include "global.h"

#ifndef STACK_H
#define STACK_H

//#define LIMITED_MEMORY_S

typedef struct stack* Pstack;


void StackInti(Pstack*);

int StackFull(Pstack);

void Push(StackEntry, Pstack);

int StackEmpty(Pstack);

void Pop(StackEntry*, Pstack);

void StackTop(StackEntry*, Pstack);

int StackSize(Pstack);

void ClearStack(Pstack);

void TraverseStack(Pstack, void (*)(StackEntry));


#endif STACK_H
