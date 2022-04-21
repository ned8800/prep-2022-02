#include "matrix.h"
#include <stdio.h>
#include <malloc.h>

// NOTE(stitaevskiy): Place your implementation here

Matrix* create_matrix_from_file(const char* path_file){
size_t cr_rows;
size_t cr_colls;
//double buffer;
FILE * file_in = fopen(path_file, "rt");
if (!fopen(path_file, "rt")) {
return NULL;
}
fscanf(file_in, "%zu %zu", &cr_rows, &cr_colls);
Matrix * mymatrix = malloc(sizeof(Matrix));
mymatrix->colls = cr_colls;
mymatrix->rows = cr_rows;

return mymatrix;
}
