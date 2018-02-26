#include "sstring.h"
#include <stdio.h>

#define EOF -1

/* my own string.h */

int
sstrlen(char *s)
{
	int n;
	for (n = 0; *s++ != '\0'; n++)
		;
	return n;
}

void
sstrncpy(char *s, char *t, int n)
{
	while ((*s++ = *t++) && --n > 0)
		;
}

void
sstrncat(char *s, char *t, int n)
{
	s += sstrlen(s);
	while ((*s++ = *t++) && --n > 0)
		;
	*s = '\0';
}

int
sstrncmp(char *s, char *t, int n)
{
	while ((*s++ == *t++) && --n > 0) 
		if (*s == '\0' || n == 1)
			return 0;
	return 1;
}

void
getnline(char *s, int n)
{
	while ((*s++ = getchar()) != '\n' && *(s - 1) != EOF && --n >= 0)
		;
	*--s = '\0';
	return;
}
