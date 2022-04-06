#ifndef PROJECT_INCLUDE_FUNCTIONS_H_
#define PROJECT_INCLUDE_FUNCTIONS_H_

#include <stdio.h>
#include "defines.h"

void update_database(FILE *client_stream, FILE *transfer_stream, \
FILE *database_stream, data_t *client, data_t *transfer);
int read_client_data(FILE *stream, data_t *client);
int read_transfer_data(FILE *stream, data_t *transfer);
void write_data_to_file(FILE *database_stream, data_t *client);

#endif  // PROJECT_INCLUDE_FUNCTIONS_H_
