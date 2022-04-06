#include <stdio.h>
#include "record_data.h"
#include "defines.h"

void record_client_data(FILE *stream, data_t *client) {
    print_client_input_info();
    while (input_client_data(client) != -1) {
        write_client_data_to_file(stream, client);
        print_client_input_info();
    }
}

void print_client_input_info() {
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

int input_client_data(data_t *client) {
    int success_read_args = scanf("%d%19s%19s%29s%14s%lf%lf%lf",
        &client->number,
        client->name,
        client->surname,
        client->address,
        client->tel_number,
        &client->indebtedness,
        &client->credit_limit,
        &client->cash_payments);
    if (success_read_args == client_fields_amount) {
        return client_fields_amount;
    } else {
        return -1;
    }
}

void write_client_data_to_file(FILE *stream, data_t *client) {
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

void record_transaction_data(FILE *stream, data_t *transfer) {
    print_transfer_input_info();
    while (input_transfer_data(transfer) != -1) {
        write_transfer_data_to_file(stream, transfer);
        print_transfer_input_info();
    }
}

void print_transfer_input_info() {
    printf("%s\n%s\n",
    "1 Number account: ",
    "2 Client cash payments: ");
}

int input_transfer_data(data_t *transfer) {
    int success_read_args = scanf("%d %lf",
        &transfer->number,
        &transfer->cash_payments);
    if (success_read_args == transfer_fields_amount) {
        return transfer_fields_amount;
    } else {
        return -1;
    }
}

void write_transfer_data_to_file(FILE *stream, data_t *transfer) {
    fprintf(stream, "%-3d%-6.2f\n",
        transfer->number,
        transfer->cash_payments);
}
