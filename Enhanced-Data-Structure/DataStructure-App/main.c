#include <stdio.h>
#include "global.h"
#include "stack.h"
#include "queue.h"


void DisplayQueue(StackEntry e) {

	switch (e.etype) {

	case DOUBLE: printf("%g", e.Type.Double);
		break;

	case CHAR: printf("%c", e.Type.Char);

	}

}



void DisplayStack(StackEntry e) {

	switch (e.etype) {

	case DOUBLE: printf("%g", e.Type.Double);
		break;

	case CHAR: printf("%c", e.Type.Char);
		break;

	}

}




int main() {

	Pstack ps;
	StackInti(&ps);
	StackEntry e;

	Pqueue pq;
	QueueInti(&pq);
	QueueEntry c;

	
	
	
	e.etype = CHAR;
	e.Type.Char = 'a';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'y';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'm';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'a';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'n';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'a';
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

	e.etype = DOUBLE;
	e.Type.Double = 8;
	if (!StackFull(ps)) Push(e, ps);

	e.etype = CHAR;
	e.Type.Char = '@';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'g';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'm';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'a';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'i';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'l';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = '.';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'c';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'o';
	if (!StackFull(ps)) Push(e, ps);

	e.Type.Char = 'm';
	if (!StackFull(ps)) Push(e, ps);

	TraverseStack(ps, &DisplayStack);

	printf("\n\n");
	printf("Stack size = %d", StackSize(ps));

	printf("\n\n");

	if(!StackEmpty(ps))
		StackTop(&c, ps);
	
	switch (c.etype) {

	case DOUBLE:
		printf("%g", c.Type.Double);
		break;

	case CHAR:
		printf("%c", c.Type.Char);
		break;

	}

	printf("\n\n");

	if(!StackEmpty(ps))
		Pop(&c, ps);

	switch (c.etype) {

	case DOUBLE:
		printf("%g", c.Type.Double);
		break;

	case CHAR:
		printf("%c", c.Type.Char);
		break;

	}

	printf("\n\n");

	ClearStack(ps);
	printf("Stack size after clearing = %d\n\n", StackSize(ps));


	
	c.etype = CHAR;
	c.Type.Char = 'a';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'y';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'm';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'a';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'n';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'a';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'b';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'd';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'e';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'l';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'b';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'a';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'k';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'i';
	if (!QueueFull(pq)) Append(c, pq);

	c.etype = DOUBLE;
	c.Type.Double = 8;
	if (!QueueFull(pq)) Append(c, pq);

	c.etype = CHAR;
	c.Type.Char = '@';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'g';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'm';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'a';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'i';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'l';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = '.';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'c';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'o';
	if (!QueueFull(pq)) Append(c, pq);

	c.Type.Char = 'm';
	if (!QueueFull(pq)) Append(c, pq);

	TraverseQueue(pq, &DisplayQueue);

	printf("\n\n");

	printf("Queue size = %d", QueueSize(pq));

	printf("\n\n");

	if(!QueueEmpty(pq))
		QueueTop(&c, pq);

	switch (c.etype) {

	case DOUBLE:
		printf("%g", c.Type.Double);
		break;

	case CHAR:
		printf("%c", c.Type.Char);
		break;

	}

	printf("\n\n");

	if(!QueueEmpty(pq))
		Serve(&c, pq);

	switch (c.etype) {

	case DOUBLE:
		printf("%g", c.Type.Double);
		break;

	case CHAR:
		printf("%c", c.Type.Char);
		break;

	}


	printf("\n\n");

	ClearQueue(pq);
	printf("Queue size after clearing = %d\n\n", QueueSize(pq));
	

}