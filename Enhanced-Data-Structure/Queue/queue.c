#include "queue.h"
#include <stdlib.h>



#ifdef LIMITED_MEMORY_Q

typedef struct queuenode {

	QueueEntry entry;
	struct queuenode* next;

} QueueNode;

struct queue {

	QueueNode* front;
	QueueNode* rear;
	int size;

};

void QueueInti(Pqueue* ppq) {

	*ppq = (struct queue*)malloc(sizeof(struct queue));

	(*ppq)->front = NULL;
	(*ppq)->rear = NULL;
	(*ppq)->size = 0;

}

int QueueFull(Pqueue pq) {

	return 0;

}

void Append(QueueEntry e, Pqueue pq) {

	QueueNode* pn = (QueueNode*)malloc(sizeof(QueueNode));

	if (!pq->front)
		pq->front = pn;
	else
		pq->rear->next = pn;

	pq->rear = pn;
	pn->next = NULL;

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

	pq->size++;

}

int QueueEmpty(Pqueue pq) {

	return !pq->front;

}

void Serve(QueueEntry* pe, Pqueue pq) {

	QueueNode* pn = pq->front;

	switch (pn->entry.etype) {

	case DOUBLE:
		pe->etype = 1;
		pe->Type.Double = pn->entry.Type.Double;
		break;

	case CHAR:
		pe->etype = 0;
		pe->Type.Char = pn->entry.Type.Char;
		break;

	}

	pq->front = pn->next;
	free(pn);
	if (!pq->front)
		pq->rear = NULL;
	pq->size--;

}

void QueueTop(QueueEntry* pe, Pqueue pq) {


	switch (pq->front->entry.etype) {

	case DOUBLE:
		pe->etype = 1;
		pe->Type.Double = pq->front->entry.Type.Double;
		break;

	case CHAR:
		pe->etype = 0;
		pe->Type.Char = pq->front->entry.Type.Char;
		break;

	}

}

int QueueSize(Pqueue pq) {

	return pq->size;

}

void ClearQueue(Pqueue pq) {

	while (pq->front) {

		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;

	}
	pq->size = 0;

}

void TraverseQueue(Pqueue pq, void (*pf)(QueueEntry)) {

	for (QueueNode* pn = pq->front; pn; pn = pn->next) {

		(*pf)(pn->entry);

	}

}

#else

struct queue {

	int front;
	int rear;
	int size;
	QueueEntry entry[MAXQUEUE];

};

void QueueInti(Pqueue* ppq) {

	*ppq = (struct queue*)malloc(sizeof(struct queue));

	(*ppq)->front = 0;
	(*ppq)->rear = -1;
	(*ppq)->size = 0;

}

int QueueFull(Pqueue pq) {

	return pq->size == MAXQUEUE;

}

void Append(QueueEntry e, Pqueue pq) {

	pq->rear = (pq->rear + 1) % MAXQUEUE;

	switch (e.etype) {

	case DOUBLE:
		pq->entry[pq->rear].etype = 1;
		pq->entry[pq->rear].Type.Double = e.Type.Double;
		break;

	case CHAR:
		pq->entry[pq->rear].etype = 0;
		pq->entry[pq->rear].Type.Char = e.Type.Char;
		break;

	}

	pq->size++;

}

int QueueEmpty(Pqueue pq) {

	return !pq->size;

}

void Serve(QueueEntry* pe, Pqueue pq) {


	switch (pq->entry[pq->front].etype) {

	case DOUBLE:
		pe->etype = pq->entry[pq->front].etype;
		pe->Type.Double = pq->entry[pq->front].Type.Double;
		break;

	case CHAR:
		pe->etype = pq->entry[pq->front].etype;
		pe->Type.Char = pq->entry[pq->front].Type.Char;
		break;

	}

	pq->front = (pq->front + 1) % MAXQUEUE;
	pq->size--;

}

void QueueTop(QueueEntry* pe, Pqueue pq) {

	switch (pq->entry[pq->front].etype) {

	case DOUBLE:
		pe->etype = pq->entry[pq->front].etype;
		pe->Type.Double = pq->entry[pq->front].Type.Double;
		break;

	case CHAR:
		pe->etype = pq->entry[pq->front].etype;
		pe->Type.Char = pq->entry[pq->front].Type.Char;
		break;

	}

}

int QueueSize(Pqueue pq) {

	return pq->size;

}

void ClearQueue(Pqueue pq) {

	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;

}

void TraverseQueue(Pqueue pq, void (*pf)(QueueEntry)) {

	for (int pos = pq->front, s = 1; s <= pq->size; s++) {

		(*pf)(pq->entry[pos]);
		pos = (pos + 1) % MAXQUEUE;

	}

}

#endif
