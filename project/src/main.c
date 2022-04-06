#include <stdio.h>
#include "defines.h"
#include "record_data.h"
#include "functions.h"

int get_choice();
void print_menu();
int main(void) {
    data_t client_data = {0};
    data_t transfer_data = {0};
    int choice = get_choice();
    while (choice != -1) {
        switch (choice) {
            case case_record_cliend_data: {
                FILE *client_stream = fopen(filename_for_client_data, "r+");
                if (client_stream == NULL) {
                    puts("Not acess");
                } else {
                    record_client_data(client_stream, &client_data);
                    fclose(client_stream);
                }
                break;
            }
            case case_record_transfer_data: {
                FILE *transfer_stream = fopen(filename_for_transfer_data, "r+");
                if (transfer_stream == NULL) {
                    puts("Not acess");
                } else {
                    record_transaction_data(transfer_stream, &transfer_data);
                    fclose(transfer_stream);
                }
                break;
            }
            case case_update_database: {
                FILE *cl_stream = fopen(filename_for_client_data, "r");
                FILE *tr_stream = fopen(filename_for_transfer_data, "r");
                FILE *db_stream = fopen(filename_for_database, "w");
                if (cl_stream == NULL || tr_stream == NULL || db_stream == NULL) {
                    puts("exit");
                } else {
                    update_database(cl_stream, tr_stream, db_stream, &client_data, &transfer_data);
                    fclose(cl_stream);
                    fclose(tr_stream);
                    fclose(db_stream);
                }
                break;
            }
            default: {
                puts("error");
                break;
            }
        }
        choice = -1;
    }
    return 0;
}

int get_choice() {
    int choice;
    print_menu();
    int success_read_args = scanf("%d", &choice);
    if (success_read_args == 1) {
        return choice;
    } else {
        return 0;
    }
}

void print_menu() {
    printf("%s", \
    "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
}
