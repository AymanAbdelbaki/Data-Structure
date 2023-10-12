#ifndef QUEUE_H
#define QUEUE_H

#define QueueEntry char
#define MAXQUEUE 15

typedef struct queue {

	int front;
	int rear;
	int size;
	QueueEntry entry[MAXQUEUE];

} Queue;


void QueueInti(Queue*);

int QueueFull(Queue*);

void Append(QueueEntry, Queue*);

int QueueEmpty(Queue*);

void Serve(QueueEntry*, Queue*);

int QueueSize(Queue*);

void ClearQueue(Queue*);

void TraverseQueue(Queue*,void (*)(QueueEntry));

#endif QUEUE_H
