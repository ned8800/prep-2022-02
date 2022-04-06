#ifndef PROJECT_INCLUDE_CUSTOM_FUNCTIONS_H_
#define PROJECT_INCLUDE_CUSTOM_FUNCTIONS_H_

#include <stdio.h>
#include "defines.h"

void update_database(FILE *customer_stream, FILE *transfer_stream, \
FILE *database_stream, my_data *client, my_data *transfer);
int read_customer_data(FILE *stream, my_data *client);
int read_transfer_data(FILE *stream, my_data *transfer);
void write_data_to_file(FILE *database_stream, my_data *client);

#endif  // PROJECT_INCLUDE_CUSTOM_FUNCTIONS_H_
