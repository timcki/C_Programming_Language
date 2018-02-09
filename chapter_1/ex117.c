#include <stdio.h>

#define MAXLINE 1000

int getoneline(char line[], int limit);
void copy(char to[], char from[]);

/* Print all lines that are longer than 80 chars */
main() {
    int len; /* length of currently checked line */
    char buf[MAXLINE]; /* current line */

    while ((len = getoneline(buf, MAXLINE)) > 0) {
        if (len >= 80)
            printf("%s", buf);
    }

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
