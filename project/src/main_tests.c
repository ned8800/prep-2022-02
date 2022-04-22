#include <stdio.h>
#include "defines.h"
#include "record_functions.h"
#include "custom_functions.h"

#define TEST_FILENAME_CLIENT "record.dat"
#define TEST_FILENAME_TRANSFER "transaction.dat"
#define TEST_FILENAME_DATABASE "blackrecord.dat"

int arrays_compare(char* array1, char* array2, int array_length) {
    for (int i = 0; i < array_length; i++) {
        if (array1[i] != array2[i]) {
            return 0;
        }
    }
    return 1;
}

int test_customer_data() {
    my_data customer_input = {1, "customer_name", "customer_sur", \
     "customer_add", "customer_tel", 120, 100, 500};
    my_data transfer_input = {1, " ", " ", " ", " ", 0, 0, 1000};
    my_data expected_output = {1, "customer_name", "customer_sur", \
     "customer_add", "customer_tel", 120, 100, 1500};
    my_data buffer_data = {0};
    FILE *customer_stream = fopen(TEST_FILENAME_CLIENT, "r+");
    FILE *transfer_stream = fopen(TEST_FILENAME_TRANSFER, "r+");
    FILE *database_stream = fopen(TEST_FILENAME_DATABASE, "r+");
    if (customer_stream == NULL || transfer_stream == NULL || database_stream == NULL) {
        printf("%s\n", "Couldn't open file");
        return 1;
    }
    write_customer_data_to_file(customer_stream, &customer_input);
    rewind(customer_stream);
    write_transfer_data_to_file(transfer_stream, &transfer_input);
    rewind(transfer_stream);
    update_database(customer_stream, transfer_stream, database_stream, &customer_input, &transfer_input);
    rewind(database_stream);
    read_customer_data(database_stream, &buffer_data);
    if (!arrays_compare(expected_output.name, buffer_data.name, NameSizeCustomer) ||\
        !arrays_compare(expected_output.surname, buffer_data.surname, SurnameSizeCustomer) ||\
        !arrays_compare(expected_output.address, buffer_data.address, AddressSizeCustomer) ||\
        !arrays_compare(expected_output.tel_number, buffer_data.tel_number, TelNumberSizeCustomer)) {
        printf("%s\n", "Miss Array Data");
        return 1;
    }
    if (expected_output.number != buffer_data.number  ||\
        expected_output.indebtedness != buffer_data.indebtedness ||\
        expected_output.credit_limit != buffer_data.credit_limit ||\
        expected_output.cash_payments != buffer_data.cash_payments) {
        printf("%s\n", "Miss Static Data");
        return 1;
    }
    fclose(customer_stream);
    fclose(transfer_stream);
    fclose(database_stream);
    remove(TEST_FILENAME_CLIENT);
    remove(TEST_FILENAME_TRANSFER);
    remove(TEST_FILENAME_DATABASE);
    printf("%s\n", "Done");
    return 0;
}

int main(void) {
    if (test_customer_data() != 0) {
        printf("%s\n", "Done!");
    } else {
        printf("%s\n", "Data Error");
    }
    return 0;
}
