#ifndef GLOBAL_H
#define GLOBAL_H

typedef enum type {

	CHAR,
	DOUBLE

} TYPE;


typedef struct elementtype {

	char etype;
	
	union {

		char Char;
		double Double;

	} Type;

} ElementType;


typedef ElementType StackEntry;

typedef ElementType QueueEntry;

typedef ElementType ListEntry;

#define MAXELEMENTS 25

#define MAXSTACK MAXELEMENTS

#define MAXQUEUE MAXELEMENTS

#define MAXLIST MAXELEMENTS



#endif GLOBAL_H
