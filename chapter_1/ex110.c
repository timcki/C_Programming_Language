#include <stdio.h>

main() {
    int c;

    while ( (c = getchar()) != EOF) {
        switch (c) {
            case '\t':
                putchar('\\');
                putchar('t');
                putchar(c);
                break;
            case '\n':
                putchar('\\');
                putchar('n');
                putchar(c);
                break;
            case '\\':
                putchar('\\');
                putchar(c);
                break;
            default:
                putchar(c);
                break;
        }
    }
    return 0;
}
