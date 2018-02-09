#include <stdio.h>
float cel_to_fahr(int cel);

main() {
    for (int i = 0; i <= 30; ++i)
        printf("%2d °C --> %.2f °F\n", i, cel_to_fahr(i));
}

float
cel_to_fahr(int cel) {
    return (cel * 1.8) + 32;
}
