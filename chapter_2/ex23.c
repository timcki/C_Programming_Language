#include <stdio.h>
#include <math.h>

#define MAXLEN 8

/* Change hexdecimal string into integer */
int htoi(char [], unsigned long *);

/* after reading hex number used to tell how many places were read */
short lastPlace;

int
main()
{
	char hs[MAXLEN], i, j, c;
	unsigned long parsedNum;

	parsedNum = 0;

	for (j = 0; j < MAXLEN; ++j)
		hs[j] = 0;

	/* Reads first MAXLEN chars and cuts after that */
	for (i=0; i < MAXLEN && (c = getchar()) != '\n'; ++i) {
		/* Hack to eliminate first two chars if user inputs with 0x or 0X at the beginning */
		if (hs[0] == '0' && (hs[1] == 'X' || hs[1] == 'x'))
			i = 0;
		hs[i] = c;
	}
	lastPlace = i-1;
	if (htoi(hs, &parsedNum) > 0) 
		printf("%lu\n", parsedNum);
	else
		printf("WRONG FORMAT\n");


	return 0;
}

/* To convert from hex to base10 you need to go from the last digit and start
 * multiplying the number represented in hex by consequtive powers of 16.
 * Ex.
 * FF = (16*16^0) + (16*16^1)
 */

int
htoi(char hex[], unsigned long *parsed)
{
	int i, multiplier;
	multiplier = 0;
	for (i=lastPlace; i>=0; --i) {
		if (hex[i] >= '0' && hex[i] <= '9') {
			*parsed += (hex[i] - '0') * (unsigned long)pow(16, multiplier);
		}

		else if (hex[i] >= 'A' && hex[i] <= 'F') {
			*parsed += (10 + hex[i] - 'A') * (unsigned long)pow(16, multiplier);
		}

		else if (hex[i] >= 'a' && hex[i] <= 'f') {
			*parsed += (10 + hex[i] - 'a') * (unsigned long)pow(16, multiplier);
		}

		else
			return -1;
		++multiplier;
	}

	return 0;
}
