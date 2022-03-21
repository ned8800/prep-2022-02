// Copyright 2022 Timofey Chichikin

#include <stddef.h>
#include <stdio.h>
#include <utils.h>

int custom_pow(int base, int pow) {
    int result = 1;
    for (int i = 0; i < pow; ++i) {
        result *= base;
    }
    return result;
}

size_t timer_from(unsigned int from) {
    if (from > 65535) {
        return 0;
    }
    size_t time = 0;
    for (unsigned int i = from; i > 0; --i) {
        ++time;
        printf("%u ", i);
        if (time == from) {
            printf("%u\n", --i);
            return ++time;
        }
    }
    return time;
}
