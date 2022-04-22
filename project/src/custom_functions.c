#include <stdio.h>
#include "custom_functions.h"
#include "defines.h"

int read_customer_data(FILE *stream, my_data *client) {
    if (stream == NULL || client == NULL) {
        return -1;
    }
    int success_read_args = fscanf(stream, "%d%19s%19s%29s%14s%lf%lf%lf",
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


void update_database(FILE *customer_stream, FILE *transfer_stream, \
FILE *database_stream, my_data *client, my_data *transfer) {
    if (customer_stream != NULL && transfer_stream != NULL \
        && database_stream != NULL && client != NULL && transfer != NULL) {
        while (read_customer_data(customer_stream, client) != -1) {
            while (read_transfer_data(transfer_stream, transfer) != -1) {
                if (client->number == transfer->number && transfer->cash_payments != 0) {
                    client->credit_limit += transfer->cash_payments;
                }
            }
            write_data_to_file(database_stream, client);
            rewind(transfer_stream);
        }
    }
}

int read_transfer_data(FILE *stream, my_data *transfer) {
    if (stream == NULL || transfer == NULL) {
        return -1;
    }
    int success_read_args = fscanf(stream, "%d %lf",
        &transfer->number,
        &transfer->cash_payments);
    if (success_read_args == transfer_fields_amount) {
        return transfer_fields_amount;
    } else {
        return -1;
    }
}

void write_data_to_file(FILE *database_stream, my_data *client) {
    if (database_stream != NULL && client != NULL) {
        fprintf(database_stream, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
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
