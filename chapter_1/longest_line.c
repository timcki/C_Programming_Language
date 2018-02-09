#include <stdio.h>

#define MAXLINE 1000

int getoneline(char line[], int limit);
void copy(char to[], char from[]);

main() {
    int len; /* length of currently checked line */
    int max; /* biggest yet */
    char buf[MAXLINE]; /* current line */
    char longest_line[MAXLINE]; /* longest line yet */

    max = 0;
    while ((len = getoneline(buf, MAXLINE)) > 0) {
        if (max < len) {
            max = len;
            copy(longest_line, buf);
        }
    }

    if (max > 0)
        printf("%d: %s", max, longest_line);

    return 0;

}

int
getoneline(char s[], int lim) {
    int c, length;

    for (length = 0; length < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++length)
        s[length] = c;
    if (c == '\n') {
        s[length] = c;
        ++length;
    }
    s[length] = '\0';

    return length;
}

void
copy(char to[], char from[]) {
    int i;
    i = 0;
    /* Doesn't check if destination is big enough. TODO */
    while ((to[i] = from[i]) != '\0')
        ++i;
}
