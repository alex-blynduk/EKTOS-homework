#include "int_to_binary.h"
#include <stdio.h>

//%b doesn't work for me, although I use C23, so I took functions from the Internet

void print_binary16(const int16_t n) {
    const int bits = 16;
    const unsigned int u = (unsigned int)n;

    for (int i = bits - 1; i >= 0; i--) {
        const unsigned int mask = 1 << i;
        if (u & mask) {
            printf("1");
        } else {
            printf("0");
        }

        if (0 == i % 8) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_binary8(const int8_t n) {
    const int bits = 8;
    const unsigned int u = (unsigned int)n;

    for (int i = bits - 1; i >= 0; i--) {
        const unsigned int mask = 1 << i;
        if (u & mask) {
            printf("1");
        } else {
            printf("0");
        }

        if (0 == i % 8) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_binary8u(const uint8_t n) {
    const int bits = 8;

    for (int i = bits - 1; i >= 0; i--) {
        const unsigned int mask = 1 << i;
        if (n & mask) {
            printf("1");
        } else {
            printf("0");
        }

        if (0 == i % 8) {
            printf(" ");
        }
    }
    printf("\n");
}
