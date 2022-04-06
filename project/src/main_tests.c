#include <stdio.h>
#include "defines.h"
#include "record_data.h"
#include "functions.h"

#define TEST_FILENAME_CLIENT "client_test.dat"
#define TEST_FILENAME_TRANSFER "transfer_test.dat"
#define TEST_FILENAME_DATABASE "db_test.dat"

int compare_char_arrays(char* array1, char* array2, int array_length) {
    for (int i = 0; i < array_length; i++) {
        if (array1[i] != array2[i]) {
            return 0;
        }
    }
    return 1;
}

void test_read_write_data() {
    data_t client_struct_input = {1, "name1", "sur1", "add1", "tel1", 100, 200, 50};
    data_t transfer_struct_input = {1, " ", " ", " ", " ", 0, 0, 1000};
    data_t expected_struct = {1, "name1", "sur1", "add1", "tel1", 100, 1200, 50};
    data_t got_struct = {0};
    FILE *cl_stream = fopen(TEST_FILENAME_CLIENT, "w+");
    FILE *tr_stream = fopen(TEST_FILENAME_TRANSFER, "w+");
    FILE *db_stream = fopen(TEST_FILENAME_DATABASE, "w+");
    if (cl_stream == NULL || tr_stream == NULL || db_stream == NULL) {
        puts("exit");
    } else {
        write_client_data_to_file(cl_stream, &client_struct_input);
        rewind(cl_stream);
        write_transfer_data_to_file(tr_stream, &transfer_struct_input);
        rewind(tr_stream);
        update_database(cl_stream, tr_stream, db_stream, &client_struct_input, &transfer_struct_input);
        rewind(db_stream);
        read_client_data(db_stream, &got_struct);
        if (expected_struct.number == got_struct.number  &&\
            compare_char_arrays(expected_struct.name, got_struct.name, kNameSize) &&\
            compare_char_arrays(expected_struct.surname, got_struct.surname, kSurnameSize) &&\
            compare_char_arrays(expected_struct.address, got_struct.address, kAddressSize) &&\
            compare_char_arrays(expected_struct.tel_number, got_struct.tel_number, kTelNumberSize) &&\
            expected_struct.indebtedness == got_struct.indebtedness &&\
            expected_struct.credit_limit == got_struct.credit_limit &&\
            expected_struct.cash_payments == got_struct.cash_payments) {
            printf("%s\n", "SUCCESS");
        } else {
            printf("%s\n", "DATA MISSMATCH");
        }
        fclose(cl_stream);
        fclose(tr_stream);
        fclose(db_stream);
        remove(TEST_FILENAME_CLIENT);
        remove(TEST_FILENAME_TRANSFER);
        remove(TEST_FILENAME_DATABASE);
    }
}

int main(void) {
    test_read_write_data();
    return 0;
}
