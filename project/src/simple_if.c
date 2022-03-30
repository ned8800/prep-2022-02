// Copyright 2022 Timofey Chichikin

#include <simple_if.h>

int simple_num(int num) {
    if (num <= 1 || num%2 == 0) {return 0;}
    int i = 3;
    do {
        if (num%i == 0) {return 0;}
        i += 2;
    } while (i <= num/2);
    return 1;
}
