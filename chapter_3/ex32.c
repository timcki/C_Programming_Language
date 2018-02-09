#include <stdio.h>

void escape(char [], char [], int);
void deescape(char [], char [], int);

int
main(int argc, char* argv[])
{
	char dest[1000], buf[1000];
	int j, c;
	j = 0;
	while ((c = getchar()) != EOF)
		buf[j++] = c;
	escape(dest, buf, 1000);
	deescape(buf, dest, 1000);
	printf("buf:\n%s\n\nesc:\n%s\n", buf, dest);
	return 0;
}

void
escape(char to[], char from[], int size)
{
	char c;
	int i, j;
	j = i = 0;
	while ((c = from[i++]) != '\0' && j < size - 2)
		switch (c) {
		case '\t':
			to[j++] = '\\';
			to[j++] = 't';
			break;
		case '\n':
			to[j++] = '\\';
			to[j++] = 'n';
			break;
		default:
			to[j++] = c;
			break;
		}

	to[j] = '\0';
}

void
deescape(char to[], char from[], int size)
{
	char c;
	int i, j, escaped;
	j = i = 0;
	escaped = 0;
	while ((c = from[i++]) != '\0' && j < size - 2) {
		if (c == '\\' && !escaped) {
			escaped = 1;
			continue;
		} else if (escaped) {
			switch (c) {
			case 't':
				to[j++] = '\t';
				escaped = 0;
				break;
			case 'n':
				to[j++] = '\n';
				escaped = 0;
				break;
			default:
				to[j++] = '\\';
				to[j++] = c;
				escaped = 0;
				break;
			}
		} else {
			to[j++] = c;
			escaped = 0;
	}

	to[j] = '\0';
}
