#include <stdio.h>

#define MAXLINE 1000

int getoneline(char line[], int limit); /* Get one line of stdin  */
int trim(char line[], int length); /* Trim all trailing whitespaces, return length after trim */
void reverse(char line[], int length); /* Reverse the string */

/* Remove trailing tabs and spaces and delete entirely blank lines */
int
main() {
    int len; /* length of currently checked line */
    int len_after_trim;
    char buf[MAXLINE]; /* current line */

    while ((len = getoneline(buf, MAXLINE)) > 0) {
            len_after_trim = trim(buf, len);
            reverse(buf, len_after_trim);
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

int
trim(char l[], int len) {

    len = len-2; /* Check after the end of string and newline */

    while (l[len] == '\t' || l[len] == ' ')
        --len;

    if (len < 0)
        l[0] = '\0';
    else {
        l[len+1] = '\n';
        l[len+2] = '\0';
    }
    return len+2;
}

void
reverse(char l[], int len) {
    int tmp; /* Holds value during the swap */
    int middle; /* Middle of the string. If not even rounds to bottom to leave center char unchanged. */
    int base_index; /* Position from the bottom during iteration */

    len -= 2; /* Reverse after the end of string and newline */
    middle = len / 2; 
    base_index = 0;

    for (int i = len; i > middle; --i) {
        tmp = l[base_index];
        l[base_index] = l[i];
        l[i] = tmp;
        ++base_index;
    }
}
