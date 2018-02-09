#include <stdio.h>

#define IN 1
#define OUT 0

main() {
    int n_chars, words, n_lines, state, c;
    n_chars = words = n_lines = 0;
    state = OUT;

    while ( (c = getchar()) != EOF) {
        ++n_chars;
        if (c == '\n')
            ++n_lines;
        if (c == '\n' || c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++words;
        }
    }
    printf("n_chars: %d\nwords: %d\nlines: %d", n_chars, words, n_lines);
    return 0;
}
