#include <stdio.h>

#include "sstring.h"

int
main()
{
	char str[100];
	int res;

	sstrncpy(str, "abcdefghijkl", 100);
	sstrncat(str, "cde", 100);
	res = sstrncmp(str, "fdhghkgtl", 100);
	printf("%s\n%d\n", str, res);
	return 0;
}
