#include "global.h"


#ifndef QUEUE_H
#define QUEUE_H


//#define LIMITED_MEMORY_Q

typedef struct queue* Pqueue;


void QueueInti(Pqueue*);

int QueueFull(Pqueue);

void Append(QueueEntry, Pqueue);

int QueueEmpty(Pqueue);

void Serve(QueueEntry*, Pqueue);

void QueueTop(QueueEntry*, Pqueue);

int QueueSize(Pqueue);

void ClearQueue(Pqueue);

void TraverseQueue(Pqueue*, void (*)(QueueEntry));


#endif QUEUE_H
