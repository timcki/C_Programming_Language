#include <stdio.h>

#include "calc.h"
#define MAXVAL 100

int sp = 0;
double stack[MAXVAL];

extern char var;

void
push(double v)
{
	if (sp < MAXVAL)
		stack[sp++] = v;
	else
		printf("ERROR: Stack full can't push %g\n", v);
}

double
pop(void)
{
	if (sp) {
		/* return variable if is used in operation */
		if (var > 0)
			return getvar();
		/* (--sp) because sp is at next free position */
		return stack[--sp];
	}
	printf("ERROR: Stack empty\n");
	pvars();
	return 0.0;
}

void
pstack(void)
{
	printf("stack(%d):\n", sp);
	for (int i = 0; i < sp; ++i) {
		printf("%g, ", stack[i]);
	}
	printf("\n");
}

double
stacktop(void)
{
	if (sp)
		return stack[sp-1];
	else
		printf("ERROR: Stack empty\n");
}

void stackdup(void)
{
	int i, tmp;
	if (sp < 99) {
		for (i = sp-1; i > 0; i--)
			stack[i] =  stack[i+1];
		sp++;
		stack[1] = stack[0];
	}
	else
		printf("ERROR: Stack full can't duplicate top\n");
}

void swap(void)
{
	int tmp;
	tmp = stack[0]; stack[0] = stack[1]; stack[1] = tmp;
}

