#ifndef QUEUE_H
#define QUEUE_H

#define QueueEntry char

typedef struct queuenode {

	QueueEntry entry;
	struct queuenode* next;

} QueueNode;

typedef struct queue {

	QueueNode *front;
	QueueNode *rear;
	int size;

} Queue;


void QueueInti(Queue*);

int QueueFull(Queue*);

void Append(QueueEntry, Queue*);

int QueueEmpty(Queue*);

void Serve(QueueEntry*, Queue*);

int QueueSize(Queue*);

void ClearQueue(Queue*);

void TraverseQueue(Queue*, void (*)(QueueEntry));

#endif QUEUE_H
