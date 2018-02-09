#include <stdio.h>

#define MAXLINE 1000
#define SPLIT_AT 80

int getoneline(char line[], int limit); /* Get one line of stdin  */
void fold(char line[], int fold_at, int length); /* Fold line every 80 chars but not in the middle of some blanks */


/* Fold text every n chars. We can split in middle of a word but can't on a blank.
 * If we encouter one, print to the end of the last possible word and print them at the beginning of next line
 */
int
main() {
    char buf[MAXLINE];
    int len;
    while ((len = getoneline(buf, MAXLINE)) > 0)
	return 0;
}

int
getoneline(char s[], int lim) {
	int c, length;

	for (length = 0; length < lim-1 && (c = getchar()) != EOF && c!='\n'; ++length)
		s[length] = c;
	if (c == '\n') {
		s[length] = c;
		++length;
	}

	s[length] = '\0';
	return length;
}

void fold(char l[], int f, int len) {
	int num_of_splits, at_char;
	at_char = 0;
	num_of_splits = len / f; /* Calculate number of folds */
	for (int i=0; i<num_of_splits; ++i) {
		/* TODO */
	}
}
