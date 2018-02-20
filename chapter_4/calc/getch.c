#include <stdio.h>

#include "calc.h"
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

/* Check if there is a char in the buffer. If so return it instead of stdin. */
int
getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* Push char in the buffer */
void
ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ERROR: ungetch -  too many characters\n");
	else
		buf[bufp++] = c;
}
