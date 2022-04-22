#include <stdio.h>
#include "record_functions.h"
#include "defines.h"

void record_customer_data(FILE *stream, my_data *client) {
    print_customer_input_info();
    while (input_customer_data(client) != -1) {
        write_customer_data_to_file(stream, client);
        print_customer_input_info();
    }
}

void print_customer_input_info() {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
        "1 Number account: ",
        "2 Client name: ",
        "3 Surname: ",
        "4 Addres client: ",
        "5 Client Telnum: ",
        "6 Client indebtedness: ",
        "7 Client credit limit: ",
        "8 Client cash payments: ");
}

int input_customer_data(my_data *client) {
    int success_read_args = scanf("%d%19s%19s%29s%14s%lf%lf%lf",
        &client->number,
        client->name,
        client->surname,
        client->address,
        client->tel_number,
        &client->indebtedness,
        &client->credit_limit,
        &client->cash_payments);
    if (success_read_args == customer_fields_amount) {
        return customer_fields_amount;
    } else {
        return -1;
    }
}

void write_customer_data_to_file(FILE *stream, my_data *client) {
    if (stream != NULL && client != NULL) {
        fprintf(stream, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
            client->number,
            client->name,
            client->surname,
            client->address,
            client->tel_number,
            client->indebtedness,
            client->credit_limit,
            client->cash_payments);
    }
}

void record_transaction_data(FILE *stream, my_data *transfer) {
    if (stream != NULL && transfer != NULL) {
        print_transfer_input_info();
        while (input_transfer_data(transfer) != -1) {
            write_transfer_data_to_file(stream, transfer);
            print_transfer_input_info();
        }
    }
}

void print_transfer_input_info() {
    printf("%s\n%s\n",
    "1 Number account: ",
    "2 Client cash payments: ");
}

int input_transfer_data(my_data *transfer) {
    if (transfer == NULL) {
        return -1;
    }
    int success_read_args = scanf("%d %lf",
        &transfer->number,
        &transfer->cash_payments);
    if (success_read_args == transfer_fields_amount) {
        return transfer_fields_amount;
    } else {
        return -1;
    }
}

void write_transfer_data_to_file(FILE *stream, my_data *transfer) {
    if (stream != NULL && transfer != NULL) {
        fprintf(stream, "%-3d%-6.2f\n",
            transfer->number,
            transfer->cash_payments);
    }
}
