// Copyright 2022 Timofey Chichikin

#include <stdio.h>
#include <recursioN.h>

void recursion_output(int num) {
    if (num == 1) {
        printf("%d", num);
         return;
    }
    if (num > 1) {
        recursion_output(num-1);
    } else {
        recursion_output(num+1);
    }
    printf(" %d", num);
    return;
}
