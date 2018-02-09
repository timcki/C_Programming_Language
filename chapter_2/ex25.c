#include <stdio.h>

signed int any(char [], char []);

int
main(int argc, char** argv)
{
	signed int a;
	if (argc != 3) {
		printf("Usage: ./ex s1 s2\n");
		return -1;
	}
	a = any(argv[1], argv[2]);
	printf("s1: %s\ns2: %s\noccurence at: %d\n", argv[1], argv[2], a);
	return 0;
}

signed int
any(char base[], char comp[])
{
	signed int earliestOccurence, currentCheck, i, j;

	i = j = 0;

	while ((currentCheck = comp[j++]) != '\0') {
		while (base[i] != currentCheck && base[i] != '\0')
			i++;
		if (base[i] == '\0' && earliestOccurence < 0)
			earliestOccurence = -1;
		else if (earliestOccurence > ++i)
			earliestOccurence = i;
		i = 0;
	}

	return earliestOccurence;
}
