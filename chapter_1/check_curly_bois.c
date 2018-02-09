#include <stdio.h>

#define CURLY_BRACKET_BEGIN 0
#define CURLY_BRACKET_END 1

#define ROUND_BRACKET_BEGIN 2
#define ROUND_BRACKET_END 3

#define SINGLE_QUOTE 4
#define DOUBLE_QUOTE 5

#define SQUARE_BRACKET_BEGIN 6
#define SQUARE_BRACKET_END 7

#define TRUE 1
#define FALSE 0

void checkCompletness(int []);

int
main() {
	int the_bois[8], escaped, in_string, in_char, c, lc;

	escaped = FALSE; /* flag if next char is escaped */
	in_string = FALSE; /* flag if inside a string literal */
	in_char = FALSE; 
	lc = 0; /* Previous char */

	for (int i=0; i<8; ++i)
		the_bois[i] = 0;

	while ((c = getchar()) != EOF) {
		/* This is the most basic check. If inside string just ignore */
		if (!in_string) {
			if (!in_char) {
				if (!escaped) {
					switch (c) {
					case '\\':
						escaped = TRUE;
						printf("escaping\n");
						continue;
						break;
					case '{':
						++the_bois[CURLY_BRACKET_BEGIN];
		                break;
					case '}':
						++the_bois[CURLY_BRACKET_END];
						break;
					case '(':
						++the_bois[ROUND_BRACKET_BEGIN];
						break;
					case ')':
						++the_bois[ROUND_BRACKET_END];
						break;
					case '\'':
						++the_bois[SINGLE_QUOTE];
						in_char = TRUE;
						break;
					case '"':
						++the_bois[DOUBLE_QUOTE];
						/* If not in string then add a character to the count and change in_string */
						in_string = TRUE;
						break;
					case '[':
						++the_bois[SQUARE_BRACKET_BEGIN];
						break;
					case ']':
						++the_bois[SQUARE_BRACKET_END];
						break;
					default:
						break;
					}
				}
				else {
					escaped = FALSE;
				}

			}
			/* Basic check to exit char mode */
			else if (lc != '\\' && c == '\'') {
				in_char = FALSE;
				++the_bois[SINGLE_QUOTE];
			}
		}
		/* Basic check to exit string mode */
		else if (lc != '\\' && c == '"') {
			in_string = FALSE;
			++the_bois[DOUBLE_QUOTE];
		}

		lc = c;
    }

    checkCompletness(the_bois);

	printf("{: %d\n", the_bois[0]);
	printf("}: %d\n", the_bois[1]);
	printf("(: %d\n", the_bois[2]);
	printf("): %d\n", the_bois[3]);
	printf("': %d\n", the_bois[4]);
	printf("\": %d\n", the_bois[5]);
	printf("[: %d\n", the_bois[6]);
	printf("]: %d\n", the_bois[7]);

	return 0;
}

/* 0 if all fine, -1 if missing brackets */
void
checkCompletness(int bois[]) {

	/* TODO */

	signed short result;

	result = 0;

	if (bois[CURLY_BRACKET_BEGIN] == bois[CURLY_BRACKET_END]) {
		printf("Curly brackets: OK\n");
	}
	else {
		printf("Curly brackets: UNCLOSED\n");
		result = -1;
	}


	if (bois[ROUND_BRACKET_BEGIN]  == bois[ROUND_BRACKET_END]) {
		printf("Round brackets: OK\n");
	}
	else {
		printf("Round brackets: UNCLOSED\n");
		result = -1;
	}
}
