#include <stdio.h>
#include "global.h"
#include "queue.h"

void DisplayQueue(QueueEntry e) {

	printf("%c", e);

}

int main() {

	Pqueue pq;
	QueueInti(&pq);

	char e;

	e = 'A';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'y';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'm';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'a';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'n';
	if (!QueueFull(pq)) Append(e, pq);
	e = ' ';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'A';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'b';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'd';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'e';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'l';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'b';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'a';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'k';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'i';
	if (!QueueFull(pq)) Append(e, pq);
	e = 'i';
	if (!QueueFull(pq)) Append(e, pq);

	TraverseQueue(pq, &DisplayQueue);

	printf("\n\n");

}