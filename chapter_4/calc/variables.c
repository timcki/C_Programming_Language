#include <stdio.h>

#include "calc.h"
#define VARSIZE 26

double vars[VARSIZE];
extern char var;

void pvars(void)
{
	for (int i = 0; i < VARSIZE; i++)
		printf("%c - %g\n", i + 'a', vars[i]);
}

void initvars(void)
{
	for (int i = 0; i < VARSIZE; i++) {
		vars[i] = 0;
	}
}

void writevar(char var, double val)
{
	vars[var-'a'] = val;
	printf("ASSIGN: %c = %g\n", var, val);
}

double getvar(void)
{
	char tmp;
	tmp = var;
	var = -1;
	return vars[tmp-'a'];
}
