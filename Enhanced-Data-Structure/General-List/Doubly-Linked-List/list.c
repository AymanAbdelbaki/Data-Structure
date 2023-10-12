#include "global.h"
#include "list.h"
#include <stdlib.h>

typedef struct listnode {

	struct listnode* prev;
	ListEntry entry;
	struct listnode* next;

} ListNode;

struct list {

	ListNode* current;
	int currentPos;
	int size;

};

int ListInti(Plist* ppl) {

	if (*ppl = (Plist)malloc(sizeof(struct list))) {

		(*ppl)->current = NULL;
		(*ppl)->currentPos = 0;
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

	ListNode* pn = (ListNode*)malloc(sizeof(ListNode));
	
	switch (e.etype) {

	case CHAR:
		pn->entry.etype = CHAR;
		pn->entry.Type.Char = e.Type.Char;
		break;
		
	case DOUBLE:
		pn->entry.etype = DOUBLE;
		pn->entry.Type.Double = e.Type.Double;
		break;

	}

	ListNode* ptemp;

	if (pos <= pl->currentPos) {

		for (; pl->currentPos > pos; pl->currentPos--) {

			pl->current = pl->current->prev;

		}

		pn->next = pl->current;

		if (pl->current) {

			ptemp = pl->current->prev;
			pl->current->prev = pn;

		}
		else
			ptemp = NULL;

		pn->prev = ptemp;
		
		if(ptemp)
			ptemp->next = pn;
		pl->current = pn;

	}
	
	else {

		for (; pl->currentPos < pos - 1; pl->currentPos++) {

			pl->current = pl->current->next;

		}

		pn->next = pl->current->next;
		
		if (pn->next)
			pn->next->prev = pn;

		pn->prev = pl->current;
		pl->current->next = pn;

		pl->current = pn;
		pl->currentPos = pos;

	}
	pl->size++;

}

void ReplaceList(int pos, ListEntry e, Plist pl) {

	ListNode* pn;
	int LASTPOS;

	if (pos <= pl->currentPos) {

		for (pn = pl->current, LASTPOS = pl->currentPos; LASTPOS > pos; LASTPOS--) {

			pn = pn->prev;

		}

	}

	else {

		for (pn = pl->current, LASTPOS = pl->currentPos; LASTPOS < pos; LASTPOS++) {

			pn = pn->next;

		}

	}

	switch (e.etype) {

	case CHAR:
		pn->entry.etype = CHAR;
		pn->entry.Type.Char = e.Type.Char;
		break;

	case DOUBLE:
		pn->entry.etype = DOUBLE;
		pn->entry.Type.Double = e.Type.Double;
		break;

	}

}

int ListEmpty(Plist pl) {

	return !pl->size;

}

void DeleteList(int pos, ListEntry* pe, Plist pl) {

	ListNode* ptemp;

	if (pos <= pl->currentPos) {

		for (; pl->currentPos > pos; pl->currentPos--) {

			pl->current = pl->current->prev;

		}

		switch (pl->current->entry.etype) {

		case CHAR:
			pe->etype = CHAR;
			pe->Type.Char = pl->current->entry.Type.Char;
			break;

		case DOUBLE:
			pe->etype = DOUBLE;
			pe->Type.Double = pl->current->entry.Type.Double;
			break;

		}

		ptemp = pl->current;
		pl->current = pl->current->next;

		if(ptemp->prev)
			ptemp->prev->next = ptemp->next;

		if(ptemp->next)
			ptemp->next->prev = ptemp->prev;

		free(ptemp);

	}

	else {

		for (; pl->currentPos < pos - 1; pl->currentPos++) {

			pl->current = pl->current->next;

		}

		switch (pl->current->next->entry.etype) {

		case CHAR:
			pe->etype = CHAR;
			pe->Type.Char = pl->current->next->entry.Type.Char;
			break;

		case DOUBLE:
			pe->etype = DOUBLE;
			pe->Type.Double = pl->current->next->entry.Type.Double;
			break;

		}

		ptemp = pl->current->next;
		ptemp->prev->next = ptemp->next;
		
		if (ptemp->next) {

			ptemp->next->prev = ptemp->prev;
			pl->current = pl->current->next->next;
			pl->currentPos = pos;

		}

		free(ptemp);

	}

	pl->size--;

}

void RetrieveList(int pos, ListEntry* pe, Plist pl) {

	ListNode* pn;
	int LASTPOS;

	if (pos <= pl->currentPos) {

		for (pn = pl->current, LASTPOS = pl->currentPos; LASTPOS > pos; LASTPOS--) {

			pn = pn->prev;

		}

	}

	else {

		for (pn = pl->current, LASTPOS = pl->currentPos; LASTPOS < pos; LASTPOS++) {

			pn = pn->next;

		}

	}

	switch (pl->current->entry.etype) {

	case CHAR:
		pe->etype = CHAR;
		pe->Type.Char = pl->current->entry.Type.Char;
		break;

	case DOUBLE:
		pe->etype = DOUBLE;
		pe->Type.Double = pl->current->entry.Type.Double;
		break;

	}

}

int ListSize(Plist pl) {

	return pl->size;

}

void DestroyList(Plist pl) {

	ListNode* pn1, * pn2;
	pn1 = pn2 = pl->current;
	pl->current = pl->current->next;

	for (; pn1; pn2 = pn1) {

		pn1 = pn1->prev;
		free(pn2);

	}

	for (pn2 = pl->current; pl->current; pn2 = pl->current) {

		pl->current = pl->current->next;
		free(pn2);

	}

	pl->size = 0;
	pl->currentPos = 0;

}

void TraverseList(Plist pl, void (*pf)(ListEntry)) {

	ListNode* pn;
	int LASTPOS;

	for (pn = pl->current, LASTPOS = pl->currentPos; LASTPOS > 0; LASTPOS--)
		pn = pn->prev;

	for (; pn; pn = pn->next)
		(*pf)(pn->entry);
}