#include <stdio.h>

#define IN 1
#define OUT 0
#define ARRAY_SIZE 15

void print_horizontal(int t[]);
void print_vertical(int t[]);

void
print_vertical(int t[]) {
    /* Going to iterate over entire array and find the highest number of words. This will be the highest point i will have to print from. Then i'm going to check one by one if any other words, have lower number of chars. If yes going to print them on that iteration. */
    int max_number_of_words;

    max_number_of_words = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (t[i] > max_number_of_words)
            max_number_of_words = t[i];
    }

    for (int i = max_number_of_words; i >= 0; --i) {
        for (int j = 0; j < ARRAY_SIZE; ++j) {
            if (t[j] > i)
                printf(" | ");
            else
                printf("   ");
        }
        putchar('\n');
    };
    for (int j = 0; j < ARRAY_SIZE; ++j)
        printf(" - ");
    putchar('\n');

    for (int j = 0; j < ARRAY_SIZE; ++j)
        printf("%2d ", j);
}

void
print_horizontal(int t[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%3d |", i);
        for (int j = 0; j < t[i]; ++j)
            putchar('-');
        printf(" %d \n", t[i]);
    }
}

int
main() {
    int wl, c, state;
    int word_lengths[ARRAY_SIZE];

    for (int i=0; i < ARRAY_SIZE; ++i)
        word_lengths[i] = 0;

    wl = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {

        if (c == '\t' || c == '\n' || c == ' ') {
            ++word_lengths[wl];
            wl = 0;
            state = OUT;
        }

        else if (state == OUT)
            state = IN;

        if (state == IN)
            ++wl;
    }

    //print_horizontal(word_lengths);
    print_vertical(word_lengths);
    return 0;
}
