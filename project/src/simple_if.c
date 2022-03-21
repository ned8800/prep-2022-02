// Copyright 2022 Timofey Chichikin

#include <simple_if.h>

int simple_num(int num) {
    if (num <= 1) {return 0;}
    for (int i = 2; i <= num/2; i++) {
        if (num%i == 0) {return 0;}
    }
    return 1;
}
