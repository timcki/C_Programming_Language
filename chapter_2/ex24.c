#include <stdio.h>

#define MAXLENGTH 100

/* Erases for s1 that matches one from s2
 * Ex.
 * s1 = "abcd"
 * s2 = "abghj"
 * s3 = "cdab"
 * squeeze(s1, s2);
 * squeeze(s3, s2);
 * s1 == "cd"
 * s3 = "cdab"
 */
void squeeze(char [], char []);

int
main(int argc, char* argv[])
{
	if (argc != 3) {
		printf("Usage: ./name s1 s2\n");
		return -1;
	}
	squeeze(argv[1], argv[2]);
	printf("%s\n", argv[1]);
	return 0;
}

void
squeeze(char base[], char erase[])
{
	int i, j;

	for (i = j = 0; base[i] != '\0' && erase[i] != '\0'; i++) {
		/* All good except for the case when the erase string is shorter. Going to solve that */
		if (base[i] != erase[i])
			base[j++] = base[i];
	}
	/* solved the problem of one string being shorter than the other by simply 
	 * copying the remaining of base to the end of base*/
	while (base[i] != '\0')
		base[j++] = base[i++];
	base[j] = '\0';
}

/* NICE JOB ON THAT ONE BUD */
