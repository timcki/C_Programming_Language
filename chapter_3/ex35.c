#include <stdio.h>
#include <math.h>

int itob(int, char [], int); /* converts n into base b and writes to string s */
int itoh(char [], int); /* converts int to hex, writes to string */
int itobin(char [], int); /* converts int to binary, writes to string */
int reverse(char [], int); /* reverses a string */

int
main(int argc, char* argv[])
{
	char hex_str[100];
	char bin_str[100];

	itob(16, hex_str, 16);
	itob(16, bin_str, 2);

	printf("hex: %s\nbin: %s\n", hex_str, bin_str);
	return 0;
}

int
itob(int n, char s[], int b)
{
	switch (b) {
	case 2:
		itobin(s, n);
		break;

	case 16:
		itoh(s, n);
		break;

	default:
		break;
	}
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
		s[i++] = (x<10) ? (x + '0') : (x - 10 + 'a');
	} while (n > 0);
	s[i++] = 'x';
	s[i++] = '0';
	s[i] = '\0';
	reverse(s, i);
	return 0;
}

int
reverse(char s[], int len)
{
	int j, tmp;
	j = 0;
	len -= 1;
	while (j < len) {
		tmp = s[j];
		s[j++] = s[len];
		s[len--] = tmp;
	}
	return 0;
}

int
itobin(char s[], int n)
{
	int x, i;
	x = i = 0;
	do {
		x = n % 2;
		n /= 2;
		s[i++] = (x == 1) ? '1' : '0';
	} while (n > 0);
	s[i++] = 'b';
	s[i++] = '0';
	s[i] = '\0';
	reverse(s, i);
	return 0;
}
