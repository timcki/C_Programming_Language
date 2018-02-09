#include <stdio.h>
#include <string.h>

/*
 * TODO
 * [] DUMB WAY: with index i
 * [] SMART WAY: with slicing
 */
void expand(char [], char []);

int
main(int argc, char* argv[])
{
	if (argc != 2)
		return -1;
	char dest[1000];
	expand(dest, argv[1]);
	printf("%s\n", dest);
	return 0;
}

void
expand(char to[], char expand[])
{
	int i, j, k;

	/* 
	 * Actually what we are looking for is blocks of x-y. The only real problem
	 * arises with the case: a-b-c. Im going to check the first two, and then return
	 * to the last one to check if the one after that one is not a '-'.
	 */

	j = i = 0;

	for (; i+2 < strlen(expand); i++) {
		/* check for a three possible to expand. Else add expand[i] to to[] */
		if (expand[i] != '-' && expand[i+1] == '-' && expand[i+2] != '-') {
			for (k = expand[i]; k <= expand[i+2]; ++k)
				to[j++] = k;
			i += 2;
		}
		else
			to[j++] = expand[i];
	}

	while (expand[i] != '\0')
		to[j++] = expand[i++];
	to[j] = '\0';
}
