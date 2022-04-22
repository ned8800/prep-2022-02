#ifndef PROJECT_INCLUDE_RECORD_FUNCTIONS_H_
#define PROJECT_INCLUDE_RECORD_FUNCTIONS_H_

#include <stdio.h>
#include "defines.h"

void record_customer_data(FILE *stream, my_data *client);
void print_customer_input_info();
int input_customer_data(my_data *client);
void write_customer_data_to_file(FILE *stream, my_data *client);
void record_transaction_data(FILE *stream, my_data *transfer);
void print_transfer_input_info();
int input_transfer_data(my_data *transfer);
void write_transfer_data_to_file(FILE *stream, my_data *transfer);

#endif  // PROJECT_INCLUDE_RECORD_FUNCTIONS_H_
