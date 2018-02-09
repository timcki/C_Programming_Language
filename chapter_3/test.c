#include <stdio.h>

int
main()
{
	char s[] = {'a', 'b', 'c'};
	int len;
	len = 0;
	while (s[len++] != '\0')
		;
	printf("%d\n", len);
	return 0;
}
