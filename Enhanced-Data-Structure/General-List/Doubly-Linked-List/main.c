#include "global.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void DisplayList(ListEntry e) {

	switch (e.etype) {

	case CHAR:
		printf("%c", e.Type.Char);
		break;
	case DOUBLE:
		printf("%g", e.Type.Double);
		break;

	}

}

int main() {


	Plist Pl;
	ListEntry e;
	int p;

	if (!ListInti(&Pl))
		printf("Initialization failed!");

	e.etype = CHAR;
	e.Type.Char = 'A';
	p = 0;
	if (!ListFull(Pl))
		if (p >= 0 && p <= ListSize(Pl))
			InsertList(p, e, Pl);

	e.etype = DOUBLE;
	e.Type.Double = 8;
	p = 1;
	if (!ListFull(Pl))
		if (p >= 0 && p <= ListSize(Pl))
			InsertList(p, e, Pl);

	e.etype = CHAR;
	e.Type.Char = 'y';
	p = 1;
	if (!ListFull(Pl))
		if (p >= 0 && p <= ListSize(Pl))
			InsertList(p, e, Pl);

	p = 1;
	if (!ListEmpty(Pl))
		if (p >= 0 && p <= ListSize(Pl) - 1) {

			RetrieveList(p, &e, Pl);

			switch (e.etype) {

			case CHAR:
				printf("%c", e.Type.Char);
				break;
			case DOUBLE:
				printf("%g", e.Type.Double);
				break;

			}

		}




	printf("\n\n");

	TraverseList(Pl, &DisplayList);

	e.etype = DOUBLE;
	e.Type.Double = 9;
	p = 1;
	if (!ListFull(Pl))
		if (p >= 0 && p <= ListSize(Pl))
			ReplaceList(p, e, Pl);

	printf("\n\n");

	TraverseList(Pl, &DisplayList);

	printf("\n\n");

	p = 0;
	if (!ListEmpty(Pl))
		if (p >= 0 && p <= ListSize(Pl) - 1) {

			DeleteList(p, &e, Pl);

			switch (e.etype) {

			case CHAR:
				printf("%c", e.Type.Char);
				break;
			case DOUBLE:
				printf("%g", e.Type.Double);
				break;

			}

		}


	printf("\n\n");

	TraverseList(Pl, &DisplayList);

}