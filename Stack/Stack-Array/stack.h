#ifndef ACCESSING_MECHANISM
#define ACCESSING_MECHANISM



//Have to be defined by the USER
//The Beginning

#define StackEntry char
#define MaxStack 20

//the End



typedef struct stack {

	StackEntry entry[MaxStack];
	int top;

} Stack;


void Inti(Stack*);

int StackFull(Stack*);

void Push(StackEntry, Stack*);

int StackEmpty(Stack*);

void Pop(StackEntry*, Stack*);

void StackTop(StackEntry*, Stack*);

int StackSize(Stack*);

void ClearStack(Stack*);

void TraverseStack(Stack*, void (*)(StackEntry));



#endif ACCESSING_MECHANISM
