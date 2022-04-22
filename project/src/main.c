#include <stdio.h>
#include "defines.h"
#include "record_functions.h"
#include "custom_functions.h"

int get_choice();

void print_menu();

int main() {
    my_data customer_data = {0};
    my_data transfer_data = {0};
    int choice = get_choice();
    switch (choice) {
        case case_record_cliend_data: {
            FILE *customer_stream = fopen(filename_for_customer_data, "r+");
            if (customer_stream == NULL) {
                printf("%s\n", access_error);
            } else {
                record_customer_data(customer_stream, &customer_data);
                fclose(customer_stream);
            }
            break;
        }
        case case_record_transfer_data: {
            FILE *transfer_stream = fopen(filename_for_transfer_data, "r+");
            if (transfer_stream == NULL) {
                printf("%s\n", access_error);
            } else {
                record_transaction_data(transfer_stream, &transfer_data);
                fclose(transfer_stream);
            }
            break;
        }
        case case_update_database: {
            FILE *cl_stream = fopen(filename_for_customer_data, "r");
            if (cl_stream == NULL) {
                    printf("%s\n", file_open_error);
                    break;
            }
            FILE *tr_stream = fopen(filename_for_transfer_data, "r");
            if (tr_stream == NULL) {
                    printf("%s\n", file_open_error);
                    fclose(cl_stream);
                    break;
            }
            FILE *db_stream = fopen(filename_for_database, "w");
            if (db_stream == NULL) {
                    printf("%s\n", file_open_error);
                    fclose(cl_stream);
                    fclose(tr_stream);
                    break;
            }
            update_database(cl_stream, tr_stream, db_stream, &customer_data, &transfer_data);
            fclose(cl_stream);
            fclose(tr_stream);
            fclose(db_stream);
            break;
        }
        default: {
            printf("%s\n", simple_error);
            break;
        }
    }
    return 0;
}

int get_choice() {
    int choice;
    print_menu();
    if (scanf("%d", &choice) == 1) {
        return choice;
    } else {
        return 0;
    }
}

void print_menu() {
    printf("%s", \
    main_menu);
}
