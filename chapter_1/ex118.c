#include <stdio.h>

#define MAXLINE 1000

int getoneline(char line[], int limit);
void trim(char line[], int length);

/* Remove trailing tabs and spaces and delete entirely blank lines */
int
main() {
    int len; /* length of currently checked line */
    char buf[MAXLINE]; /* current line */

    while ((len = getoneline(buf, MAXLINE)) > 0) {
            trim(buf, len);
            printf("%s", buf);
    }

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

void trim(char l[], int len) {

    len = len-2; /* Check after the end of string and newline */

    while (l[len] == '\t' || l[len] == ' ')
        --len;

    if (len < 0)
        l[0] = '\0';
    else {
        l[len+1] = '\n';
        l[len+2] = '\0';
    }
}
