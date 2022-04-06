#ifndef PROJECT_INCLUDE_RECORD_DATA_H_
#define PROJECT_INCLUDE_RECORD_DATA_H_

#include <stdio.h>
#include "defines.h"

void record_client_data(FILE *stream, data_t *client);
void print_client_input_info();
int input_client_data(data_t *client);
void write_client_data_to_file(FILE *stream, data_t *client);
void record_transaction_data(FILE *stream, data_t *transfer);
void print_transfer_input_info();
int input_transfer_data(data_t *transfer);
void write_transfer_data_to_file(FILE *stream, data_t *transfer);

#endif  // PROJECT_INCLUDE_RECORD_DATA_H_
