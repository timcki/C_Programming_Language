#include <stdio.h>

int strrindex(char [], char);

int
main()
{
	printf("%d\n", strrindex("abcd", 'g'));
	return 0;
}

int
strrindex(char s[], char t)
{
	/* calculate strlen */
	int len;
	len = 0;
	while (s[len] != '\0')
		len++;
	while (s[len] != t && len > 0)
		len--;
	if (len > 0)
		return len;
	else if (s[0] == t)
		return 0;
	else
		return -1;
}
