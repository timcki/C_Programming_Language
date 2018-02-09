#include <stdio.h>

main() {
    /* current char and previous one */
    int c, lc;
    lc = 0;
    while ( (c = getchar()) != EOF) {
        if (c == ' ' && lc == ' ') {
            lc = c;
            continue;
        }
        else {
            lc = c;
            putchar(c);
        }
    }
    return 0;
}
