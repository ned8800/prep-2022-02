#include <stdio.h>
#include "functions.h"
#include "defines.h"

void update_database(FILE *client_stream, FILE *transfer_stream, \
FILE *database_stream, data_t *client, data_t *transfer) {
    while (read_client_data(client_stream, client) != -1) {
        while (read_transfer_data(transfer_stream, transfer) != -1) {
            if (client->number == transfer->number && transfer->cash_payments != 0) {
                client->credit_limit += transfer->cash_payments;
            }
        }
        write_data_to_file(database_stream, client);
        rewind(transfer_stream);
    }
}

int read_client_data(FILE *stream, data_t *client) {
    int success_read_args = fscanf(stream, "%d%19s%19s%29s%14s%lf%lf%lf",
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

int read_transfer_data(FILE *stream, data_t *transfer) {
    int success_read_args = fscanf(stream, "%d %lf",
        &transfer->number,
        &transfer->cash_payments);
    if (success_read_args == transfer_fields_amount) {
        return transfer_fields_amount;
    } else {
        return -1;
    }
}

void write_data_to_file(FILE *database_stream, data_t *client) {
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
