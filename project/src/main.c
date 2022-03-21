// Copyright 2022 Timofey Chichikin

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <simple_if.h>
#include <recursioN.h>

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG  (-2)

#define TST_FOO_FIX     1
#define TST_FOO_IMPL    2
#define TST_MOD_IMPL    3
#define TST_MOD_IMPL_2  4

int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    int test_case = strtol(argv[1], NULL, 0);
    const char* data;
    data = argv[2];

    switch (test_case) {
        case TST_FOO_FIX: {
            int to = atoi(data);
            size_t ticks_count = timer_from(to);
            printf("%zu\n", ticks_count);
            break;
        }
        case TST_FOO_IMPL: {
            if (argc == 4) {
                int base = atoi(data);
                int pow =  atoi(argv[3]);
                int res = custom_pow(base, pow);

                printf("%i\n", res);
            } else {
                return ERR_ARGS_COUNT;
            }
            break;
        }
        case TST_MOD_IMPL: {
            int num = atoi(data);
            printf("%d\n", simple_num(num));
            break;
        }
        case TST_MOD_IMPL_2: {
            int num = atoi(data);
            recursion_output(num);
            break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}
