#include <stdio.h>
#include "queue.h"


void Display(QueueEntry e) {

	printf("%c", e);

}

int main() {

	Queue q;
	QueueInti(&q);

	char c;

	c = 'A';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'y';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'm';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'a';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'n';
	if (!QueueFull(&q)) Append(c, &q);
	c = ' ';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'A';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'b';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'd';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'e';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'l';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'b';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'a';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'k';
	if (!QueueFull(&q)) Append(c, &q);
	c = 'i';
	if (!QueueFull(&q)) Append(c, &q);

	TraverseQueue(&q, &Display);

	printf("\n");

}