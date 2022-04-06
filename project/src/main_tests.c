#include <stdio.h>
#include "defines.h"
#include "record_functions.h"
#include "custom_functions.h"

#define TEST_FILENAME_CLIENT "customer_test.dat"
#define TEST_FILENAME_TRANSFER "transfer_test.dat"
#define TEST_FILENAME_DATABASE "db_test.dat"

int arrays_compare(char* array1, char* array2, int array_length) {
    for (int i = 0; i < array_length; i++) {
        if (array1[i] != array2[i]) {
            return 0;
        }
    }
    return 1;
}

void test_customer_data() {
    my_data customer_input = {1, "customer_name", "customer_sur", \
     "customer_add", "customer_tel", 120, 100, 500};
    my_data transfer_input = {1, " ", " ", " ", " ", 0, 0, 1000};
    my_data expected_output = {1, "customer_name", "customer_sur", \
     "customer_add", "customer_tel", 120, 100, 1500};
    my_data buffer_data = {0};
    FILE *customer_stream = fopen(TEST_FILENAME_CLIENT, "w+");
    FILE *transfer_stream = fopen(TEST_FILENAME_TRANSFER, "w+");
    FILE *database_stream = fopen(TEST_FILENAME_DATABASE, "w+");
    if (customer_stream == NULL || transfer_stream == NULL || database_stream == NULL) {
        puts("exit");
    } else {
        write_customer_data_to_file(customer_stream, &customer_input);
        rewind(customer_stream);
        write_transfer_data_to_file(transfer_stream, &transfer_input);
        rewind(transfer_stream);
        update_database(customer_stream, transfer_stream, database_stream, &customer_input, &transfer_input);
        rewind(database_stream);
        read_customer_data(database_stream, &buffer_data);
        if (expected_output.number == buffer_data.number  &&\
            arrays_compare(expected_output.name, buffer_data.name, kNameSize) &&\
            arrays_compare(expected_output.surname, buffer_data.surname, kSurnameSize) &&\
            arrays_compare(expected_output.address, buffer_data.address, kAddressSize) &&\
            arrays_compare(expected_output.tel_number, buffer_data.tel_number, kTelNumberSize) &&\
            expected_output.indebtedness == buffer_data.indebtedness &&\
            expected_output.credit_limit == buffer_data.credit_limit &&\
            expected_output.cash_payments == buffer_data.cash_payments) {
            printf("%s\n", "done");
        } else {
            printf("%s\n", "Miss Data");
        }
        fclose(customer_stream);
        fclose(transfer_stream);
        fclose(database_stream);
        remove(TEST_FILENAME_CLIENT);
        remove(TEST_FILENAME_TRANSFER);
        remove(TEST_FILENAME_DATABASE);
    }
}

int main(void) {
    test_customer_data();
    return 0;
}
