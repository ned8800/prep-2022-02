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

size_t timer_from(int from) {
    if (from > 65535) {
        return 0;
    }
    int time = 0;
    for (int i = from; i > 0; --i) {
        ++time;
        printf("%d ", i);
        if (time == from) {
            printf("%d\n", --i);
            return ++time;
        }
    }
    return time;
}
