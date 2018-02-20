#include <stdio.h>
#include <string.h>

void strcatt(char *, char *);

int
main()
{
	char test[20] = "abc";
	strcatt(test, "def");
	printf("%s\n", test);
	return 0;
}

void
strcatt(char *s, char *t)
{
	s += strlen(s);
	while (*s++ = *t++)
		;
}
