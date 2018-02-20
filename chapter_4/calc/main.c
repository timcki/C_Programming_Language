#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "calc.h"
#define MAXOP 100

int
main()
{
	Optype type;
	double op2;
	char s[MAXOP];

	extern char var;

	/* -1 if no variable */
	var = -1;

	initvars();

	while ((type = getOp(s)) != EOF) {

		switch (type) {

		case NUMBER:
			push(atof(s));
			break;

		case ADDITION:
			push(pop() + pop());
			break;

		case MULTIPLICATION:
			push(pop() * pop());
			break;

		case SUBSTRACTION:
			op2 = pop();
			push(pop() - op2);
			break;

		case DIVISION:
			op2 = pop();
			if (!op2)
				push(pop() / op2);
			else {
				printf("ERROR: Division by zero\n");
				return -1;
			}
			break;

		case MODULO:
			op2 = pop();
			if (op2)
				push((int) pop() % (int) op2);
			else
				printf("ERROR: Division by zero\n");
			break;

		case VARIABLE:
			var = s[0];
			break;

		case VARIABLE_WRITE:
			/* normally if var is bigger than zero stack pops the value of it instead 
			 * of next thing from stack. Edge case is assigning a value which is solved
			 * by using op2 as a temporary place to store which letter is var
			 */
			op2 = var;
			var = -1;

			writevar(op2, pop());
			break;


		/* math.h */
		case SIN:
			push(sin(pop()));
			break;

		case COS:
			push(cos(pop()));
			break;

		case TAN:
			push(tan(pop()));
			break;

		case EXP:
			push(exp(pop()));
			break;

		case LOG:
			op2 = pop();
			if (op2 < 0 || op2 == 1)
				printf("ERROR: Bad logarithm\n");
			else
				push(log(op2));
			break;

		case POW:
			op2 = pop();
			push(pow(pop(), op2));
			break;

		case SQRT:
			op2 = pop();
			if (op2 < 0)
				printf("ERROR: Square root of negative number\n");
			else
				push(sqrt(op2));
			break;


		case RESULT:
			printf("\t%.8g\n", pop());
			break;

		case QUIT:
			return 0;

		case UNKNOWN:
			printf("ERROR: Unkown operation: %s\n", type);

		}
	}
	return 0;
}
