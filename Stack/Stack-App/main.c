#include <stdio.h>
#include "stack.h"
#include <math.h>

/*
// First CODE
// This First CODE work with the character stack, but the result of any operation should be {0, 1, 2, ..., 9}

int isDigit(char c) {

	switch (c) {

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return 1;

	default:
		return 0;

	}

}


//*****************************************************************


int higherPrecedence(char c, char e) {

	if (c == '$') {

		if (e == '$')
			return 0;
		else
			return 1;

	}

	else if (c == '*' || c == '/') {

		if (e == '+' || e == '-')
			return 1;
		else
			return 0;

	}

	else
		return 0;

}


//*****************************************************************


char operation(char op1, char op2, char operator) {

	int ope1 = (int)op1 - 48, ope2 = (int)op2 - 48, result;

	switch (operator) {

	case '$':
		result = pow(ope1, ope2);
		break;

	case '*':
		result = ope1 * ope2;
		break;

	case '/':
		result = ope1 / ope2;
		break;

	case '+':
		result = ope1 + ope2;
		break;

	case '-':
		result = ope1 - ope2;
		break;
	}

	return (char)(result + 48);

}

//****************************************************************************************************************************

char *infixToPostfix(char* mathOperations) {

	char c, e = '\0';
	int i, j, k = 0;
	Stack tempStack;
	static char mainString[50];

	StackInti(&tempStack);

	for (i = 0; (c = mathOperations[i]) != '\0'; i++) {

		if (isDigit(c)) {

			mainString[k++] = c;

		}


		else {

			if (!StackEmpty(&tempStack)) {

				StackTop(&e, &tempStack);

			}


			if (StackEmpty(&tempStack) || higherPrecedence(c, e)) {

				if (!StackFull(&tempStack))
					Push(c, &tempStack);

			}

			else {

				do {

					if (!StackEmpty(&tempStack))
						Pop(&e, &tempStack);

					mainString[k++] = e;

					if (!StackEmpty(&tempStack))
						StackTop(&e, &tempStack);

				} while (!higherPrecedence(c, e) && !StackEmpty(&tempStack));

				if (StackEmpty(&tempStack) && !higherPrecedence(c, e))
					Push(c, &tempStack);

			if(higherPrecedence(c, e) && !StackFull(&tempStack))
					Push(c, &tempStack);

			}

		}

	}

	while (!StackEmpty(&tempStack)) {

		Pop(&e, &tempStack);
		mainString[k++] = e;

	}

	mainString[k] = '\0';

	return mainString;

}


//************************************************************


int calculating(char* operationString) {

	int i, j;
	char c, op1, op2;
	Stack operandStack;

	StackInti(&operandStack);

	for (i = 0; (c = operationString[i]) != '\0'; i++) {

		if (isDigit(c)) {

			if(!StackFull(&operandStack))
				Push(c, &operandStack);

		}

		else {

			Pop(&op2, &operandStack);
			Pop(&op1, &operandStack);

			Push(operation(op1, op2, c), &operandStack);

		}

	}

	Pop(&c, &operandStack);

	int d = (int)c - 48;

	return d;

}


//*******************************************************************************************************************


int main() {

	
	char mathOperations[] = "1+2*2$2/2-1*2$3/2";
	
	printf("%d", calculating(infixToPostfix(mathOperations)));
	printf("\n\n");

}

// End of First CODE
*/



// Second CODE
// This code "Transfers infix to postfix with character stack", and "Evaluate the postfix with double stack"

int IsDigit(char c) {

	return (c >= '0' && c <= '9');

}


//*****************************************************************


int Precedent(char op1, char op2) {

	if (op1 == '$')
		return 1;

	if (op1 == '*' || op1 == '/')
		return (op2 != '$');

	if (op1 == '+' || op1 == '-')
		return (op2 != '$' && op2 != '*' && op2 != '/');

	else
		return 0;

}

void InfixToPostfix(char infix[], char postfix[]) {

	int i, j;
	char c, op;
	Stack s;

	StackInti(&s);

	for (i = 0, j = 0; (c = infix[i]) != '\0'; i++) {

		if (IsDigit(c))
			postfix[j++] = c;
		else {

			if (!StackEmpty(&s))
				StackTop(&op, &s);

			while (!StackEmpty(&s) && Precedent(op, c)) {

				Pop(&op, &s);
				postfix[j++] = op;

				if (!StackEmpty(&s))
					StackTop(&op, &s);

			}
			
			if(!StackFull(&s))
				Push(c, &s);

		}

	}

	while (!StackEmpty(&s)) {

		Pop(&op, &s);
		postfix[j++] = op;

	}

	postfix[j] = '\0';

}

double Oper(char c, double op1, double op2) {

	switch (c) {

	case '$':
		return pow(op1, op2);
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;

	}

}

double EvaluatePostfix(char expr[]) {

	int i;
	double val, op1, op2;
	char c;

	Stack s;


	for (i = 0; (c = expr[i]) != '\0'; i++) {


		if (IsDigit(c))
			Push((double)(c - '0'), &s);

		else {

			Pop(&op2, &s);
			Pop(&op1, &s);

			val = Oper(c, op1, op2);
			Push(val, &s);

		}

	}

	Pop(&val, &s);
	return val;

}



int main() {

	// To change code from "EvaluatePostfix" to "InfixToPostfix"; you should unhash "#define INFIX_TO_POSTFIX", in stack.h

	if (!TOGGLE) {

		char infix[] = "1+2*2$2/2-1*2$3/2", postfix[50];

		InfixToPostfix(infix, postfix);

		printf("%s", postfix);

	}
	
	
	
	else if (TOGGLE) {

		char postfix[] = "1222$*2/+123$*2/-";

		printf("%g", EvaluatePostfix(postfix));

	}
	


}

// End of Second CODE
