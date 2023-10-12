#include "list.h"
#include <stdlib.h>

#ifdef LIMITED_MEMORY_L

typedef struct listnode {

	ListEntry entry;
	struct listnode* next;

} ListNode;

struct list {

	ListNode* head;
	int size;

};

int ListInti(Plist* ppl) {

	if ((*ppl) = (Plist)malloc(sizeof(struct list))) {

		(*ppl)->head = NULL;
		(*ppl)->size = 0;
		return 1;

	}

	else
		return 0;

}

int ListFull(Plist pl) {

	return 0;

}

int InsertList(int pos, ListEntry e, Plist pl) {

	ListNode* temp;

	if (temp = (ListNode*)malloc(sizeof(ListNode))) {

		switch (e.etype) {

		case CHAR:
			temp->entry.etype = CHAR;
			temp->entry.Type.Char = e.Type.Char;
			break;

		case DOUBLE:
			temp->entry.etype = DOUBLE;
			temp->entry.Type.Double = e.Type.Double;
			break;

		}

		if (pos == 0) {

			temp->next = pl->head;
			pl->head = temp;

		}

		else {

			ListNode* q;
			int i;

			for (q = pl->head, i = 0; i < pos - 1; i++) {

				q = q->next;

			}

			temp->next = q->next;
			q->next = temp;

		}

		pl->size++;

		return 1;

	}

	else
		return 0;

}

void ReplaceList(int pos, ListEntry e, Plist pl) {

	ListNode* q;
	int i;

	for (q = pl->head, i = 0; i < pos; i++) {

		q = q->next;

	}

	switch (e.etype) {

	case CHAR:
		q->entry.etype = CHAR;
		q->entry.Type.Char = e.Type.Char;
		break;

	case DOUBLE:
		q->entry.etype = DOUBLE;
		q->entry.Type.Double = e.Type.Double;
		break;

	}

}

int ListEmpty(Plist pl) {

	return !pl->size;

}

void DeleteList(int pos, ListEntry* pe, Plist pl) {

	ListNode* temp;

	if (pos == 0) {

		switch (pl->head->entry.etype) {

		case CHAR:
			pe->etype = CHAR;
			pe->Type.Char = pl->head->entry.Type.Char;
			break;

		case DOUBLE:
			pe->etype = DOUBLE;
			pe->Type.Double = pl->head->entry.Type.Double;
			break;
		}

		temp = pl->head;
		pl->head = temp->next;
		free(temp);

	}

	else {

		int i;
		ListNode* q;

		for (temp = pl->head, i = 0; i < pos - 1; i++) {

			temp = temp->next;
		
		}

		switch (temp->next->entry.etype) {

		case CHAR:
			pe->etype = CHAR;
			pe->Type.Char = temp->next->entry.Type.Char;
			break;

		case DOUBLE:
			pe->etype = DOUBLE;
			pe->Type.Double = temp->next->entry.Type.Double;
			break;
		}

		q = temp->next;
		temp->next = temp->next->next;
		free(q);

	}

	pl->size--;

}

void RetrieveList(int pos, ListEntry* pe, Plist pl) {

	int i;
	ListNode* temp;

	for (temp = pl->head, i = 0; i < pos; i++) {

		temp = temp->next;

	}

	switch (temp->entry.etype) {

	case CHAR:
		pe->etype = CHAR;
		pe->Type.Char = temp->entry.Type.Char;
		break;

	case DOUBLE:
		pe->etype = DOUBLE;
		pe->Type.Double = temp->entry.Type.Double;
		break;
	}

}

int ListSize(Plist pl) {

	return pl->size;

}

void DestroyList(Plist pl) {

	ListNode* q;

	for (q = pl->head; q; q = pl->head) {

		pl->head = q->next;
		free(q);

	}

	pl->size = 0;

}

void TraverseList(Plist pl, void (*pf)(ListEntry)) {

	for (ListNode* q = pl->head; q; q = q->next)
		(*pf)(q->entry);

}

#else

struct list {


	ListEntry entry[MAXLIST];
	int size;

};

int ListInti(Plist* ppl) {

	if (*ppl = (Plist)malloc(sizeof(struct list))) {

		(*ppl)->size = 0;
		return 1;

	}

	else
		return 0;

}

int ListFull(Plist pl) {

	return pl->size == MAXLIST;

}

int InsertList(int p, ListEntry e, Plist pl) {

	for (int i = pl->size - 1; i >= p; i--) {

		switch (pl->entry[i].etype) {

		case CHAR:
			pl->entry[i + 1].etype = CHAR;
			pl->entry[i + 1].Type.Char = pl->entry[i].Type.Char;
			break;

		case DOUBLE:
			pl->entry[i + 1].etype = DOUBLE;
			pl->entry[i + 1].Type.Double = pl->entry[i].Type.Double;
			break;

		}

	}
	
	switch (e.etype) {

	case CHAR:
		pl->entry[p].etype = CHAR;
		pl->entry[p].Type.Char = e.Type.Char;
		break;

	case DOUBLE:
		pl->entry[p].etype = DOUBLE;
		pl->entry[p].Type.Double = e.Type.Double;
		break;

	}

	pl->size++;

	return 1;

}

void ReplaceList(int p, ListEntry e, Plist pl) {

	switch (e.etype) {

	case CHAR:
		pl->entry[p].etype = CHAR;
		pl->entry[p].Type.Char = e.Type.Char;
		break;

	case DOUBLE:
		pl->entry[p].etype = DOUBLE;
		pl->entry[p].Type.Double = e.Type.Double;
		break;

	}

}

int ListEmpty(Plist pl) {

	return !pl->size;

}

void DeleteList(int p, ListEntry* pe, Plist pl) {

	switch (pl->entry[p].etype) {

	case CHAR:
		pe->etype= CHAR;
		pe->Type.Char = pl->entry[p].Type.Char;
		break;

	case DOUBLE:
		pe->etype = DOUBLE;
		pe->Type.Double = pl->entry[p].Type.Double;
		break;

	}

	for (int i = p + 1; i <= pl->size - 1; i++) {

		switch (pl->entry[i].etype) {

		case CHAR:
			pl->entry[i - 1].etype = CHAR;
			pl->entry[i - 1].Type.Char = pl->entry[i].Type.Char;
			break;

		case DOUBLE:
			pl->entry[i - 1].etype = DOUBLE;
			pl->entry[i - 1].Type.Double = pl->entry[i].Type.Double;
			break;

		}

	}

	pl->size--;

}

void RetrieveList(int p, ListEntry* pe, Plist pl) {

	switch (pl->entry[p].etype) {

	case CHAR:
		pe->etype = CHAR;
		pe->Type.Char = pl->entry[p].Type.Char;
		break;

	case DOUBLE:
		pe->etype = DOUBLE;
		pe->Type.Double = pl->entry[p].Type.Double;
		break;

	}

}

int ListSize(Plist pl) {

	return pl->size;

}

void DestroyList(Plist pl) {

	pl->size = 0;

}

void TraverseList(Plist pl, void (*pf)(ListEntry)) {

	for (int i = 0; i <= pl->size - 1; i++)
		(*pf)(pl->entry[i]);

}

#endif