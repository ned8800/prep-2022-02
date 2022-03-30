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

int quick_custom_pow(int base, int pow) {
    if (pow == 0 || base == 1) {
        return 1;
        }
    if (base == 0) {
        return 0;
        }
    int result = 1;
    while (pow != 0) {
        if ((pow & 1) !=0) {
            result *= base;
            }
        base *= base;
        pow >>= 1;
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
