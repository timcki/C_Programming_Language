#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int
main()
{
	printf("%d\n", strend("abcdef", "ed"));
	return 0;
}

int
strend(char *s, char *t)
{
	int len;
	len = strlen(t);
	s += strlen(s) - len;
	for ( ; *s == *t; s++, t++)
		if (*s ==  '\0')
			return 1;
	return 0;
}
