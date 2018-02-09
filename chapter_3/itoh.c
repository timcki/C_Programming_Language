#include <stdio.h>

int itoh(char [], int);

int
main()
{
	char s[100];
	itoh(s, 255);
	printf("%s\n", s);
	return 0;
}

int
itoh(char s[], int n)
{
	int x, i;
	i = x = 0;
	do {
		x = n % 16;
		n /= 16;
		switch (x) {
		case 0: case 1: case 2: case 3: case 4:
		case 5: case 6: case 7: case 8: case 9:
			s[i++] = x + '0';
			break;
		case 10: case 11: case 12:
		case 13: case 14: case 15:
			s[i++] = x - 10 + 'a';
			break;
		}
	} while (n > 0);
	s[i++] = 'x';
	s[i++] = '0';
	s[i++] = '\0';
	return 0;
}
