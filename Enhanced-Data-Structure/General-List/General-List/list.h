#include "global.h"

#ifndef LIST_H
#define LIST_H

//#define LIMITED_MEMORY_L

typedef struct list* Plist;

int ListInti(Plist*);

int ListFull(Plist);

int InsertList(int, ListEntry, Plist);

void ReplaceList(int, ListEntry, Plist);

int ListEmpty(Plist);

void DeleteList(int, ListEntry*, Plist);

void RetrieveList(int, ListEntry*, Plist);

int ListSize(Plist);

void DestroyList(Plist);

void TraverseList(Plist, void (*)(ListEntry));





#endif LIST_H
